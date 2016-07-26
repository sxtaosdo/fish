class PlayerGunRenderer extends BaseComponent implements IBase {

	private robot: eui.Image;
	private centerPoint: egret.Point;
	private shellList: Array<ShellRenderer>;
	// private isTouchDown: boolean = false;
	private touchEvt: egret.TouchEvent;
	private lastSendTime: number = 0;
	private sendInterval: number = 300;
	private position: Vector2Ds;

	public constructor() {
		super(false);
		this.skinName = "resource/renderer/PlayerGun.exml";
		this.shellList = new Array<ShellRenderer>();
	}

	public onSkinComplete(e): void {
		super.onSkinComplete(e);
		this.y = 550;
		this.x = 100;
	}

	public enter(data?: any): void {
		if (this.skinLoaded) {
		}
		this.centerPoint = this.localToGlobal(this.robot.x, this.robot.y);
		this.position = new Vector2Ds(this.centerPoint.x, this.centerPoint.y);
		this.addEventListener(egret.Event.ADDED_TO_STAGE, this.onAdd, this);
	}

	public exit(): void {

	}

	public execute(data?: any): void {
		if (this.touchEvt != null) {
			this.onMove(this.touchEvt);
			if ((egret.getTimer() - this.lastSendTime) > this.sendInterval) {
				this.fire();
			}
		}
		this.shellList.forEach(element => {
			element.getFSM().Update();
		});
	}

	private onAdd(): void {
		this.stage.addEventListener(egret.TouchEvent.TOUCH_BEGIN, this.onBegin, this);
		this.stage.addEventListener(egret.TouchEvent.TOUCH_END, this.onEnd, this);
	}

	private onBegin(evt: egret.TouchEvent): void {
		// TimerManager.instance.doFrameLoop(1, this.onMove, this, [evt]);
		// this.isTouchDown = true;
		this.touchEvt = evt;
	}

	private onEnd(evt: egret.TouchEvent): void {
		// TimerManager.instance.clearTimer(this.onMove);
		// this.isTouchDown = false;
		this.touchEvt = null;
	}

	private onMove(evt: egret.TouchEvent): void {
		// console.log(evt.stageX, evt.stageY);
		// console.log(this.centerPoint.x, this.centerPoint.y);
		// (Math.atan((目标Y -中心Y) / (目标X - 中心X))) % (Math.PI)
		var disY: number = evt.stageY - this.centerPoint.y;
		if (disY > -1) {
			disY = -1;
		}
		var disX: number = evt.stageX - this.centerPoint.x;
		this.robot.rotation = Math.atan2(disY, disX) * 57;
	}

	private fire(): void {
		var shell: ShellRenderer = this.getIdelShell();
		shell.position = this.position;
		shell.speed = 10;
		shell.getFSM().ChangeState(ShellMovingEntityStateSeek.instance);
		shell.rotation = this.robot.rotation;
		// console.log("rotation" + shell.rotation.toString());
		this.parent.addChild(shell.displayObject);
		this.lastSendTime = egret.getTimer();

	}

	private getIdelShell(): ShellRenderer {
		var shell: ShellRenderer = EntityManager.instance.getAvailableEntity<ShellRenderer>(ShellRenderer);
		shell.displayObject = BitMapUtil.createBitmapByName("playerShell_png");
		shell.displayObject.anchorOffsetX = shell.displayObject.width >> 1
		shell.displayObject.anchorOffsetY = shell.displayObject.height >> 1
		shell.entityType = EntityType.SHELL;
		shell.owner = this;
		this.shellList[shell.sid] = shell;
		return shell;
	}

	public clearnShell(id: string): void {
		delete this.shellList[id];
	}
}