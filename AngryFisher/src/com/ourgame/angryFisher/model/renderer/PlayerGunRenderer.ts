class PlayerGunRenderer extends BaseComponent implements IBase {

	private centerPoint: egret.Point;
	private shellList: Array<ShellRenderer>;
	private touchEvt: egret.TouchEvent;
	private lastSendTime: number = 0;
	private position: Vector2Ds;
	private shellContent: egret.Sprite;
	private robot: egret.MovieClip;

	public data: PlayerVo;
	public shellVo: ShellVo;

	public nameText: eui.Label;
	public lvText: eui.Label;
	public lvBar: eui.ProgressBar;
	public gunText: eui.Label;
	public moneyText: eui.Label;

	public constructor(content: egret.Sprite) {
		super(false);
		this.shellContent = content;
		this.skinName = "resource/renderer/PlayerGun.exml";
		this.shellList = new Array<ShellRenderer>();
	}

	public onSkinComplete(e): void {
		super.onSkinComplete(e);
		this.y = Main.STAGE_HEIGHT - this.height - 40;
		this.x = 100;
		this.robot = MovieclipUtils.createMc("robot_png", "robot_json");
		this.robot.x = 145;
		this.robot.y = 80;
		this.robot.gotoAndStop(1);
		this.robot.anchorOffsetX = 35;
		this.robot.anchorOffsetY = 38;
		this.addChild(this.robot);
	}

	public enter(data?: any): void {
		this.data = UserModel.instance.vo;
		// this.shellVo = ConfigModel.instance.shellList[this.data.gunLevel];
		this.shellVo = this.data.gunLevel == 0 ? ConfigModel.instance.shellList[1] : ConfigModel.instance.shellList[this.data.gunLevel];
		if (this.skinLoaded) {
			this.fillData();
		}
		this.centerPoint = this.localToGlobal(this.robot.x, this.robot.y);
		this.position = new Vector2Ds(this.centerPoint.x, this.centerPoint.y - 50);
		this.addEventListener(egret.Event.ADDED_TO_STAGE, this.onAdd, this);
		this.robot.filters = [new egret.ColorMatrixFilter(MatrixUtils.change)];
	}

	public exit(): void {

	}

	public execute(data?: any): void {
		if (this.touchEvt != null) {
			this.onMove(this.touchEvt);
			if ((egret.getTimer() - this.lastSendTime) > this.shellVo.sendInterval) {
				this.fire();
			}
		}
		this.shellList.forEach(element => {
			element.getFSM().Update();
		});
		// this.updateData();
	}

	private onAdd(): void {
		this.stage.addEventListener(egret.TouchEvent.TOUCH_BEGIN, this.onBegin, this);
		this.stage.addEventListener(egret.TouchEvent.TOUCH_END, this.onEnd, this);
	}

	private onBegin(evt: egret.TouchEvent): void {
		this.touchEvt = evt;
	}

	private onEnd(evt: egret.TouchEvent): void {
		this.touchEvt = null;
	}

	private onMove(evt: egret.TouchEvent): void {
		var disY: number = evt.stageY - this.centerPoint.y;
		if (disY > -1) {
			disY = -1;
		}
		var disX: number = evt.stageX - this.centerPoint.x;
		this.robot.rotation = Math.atan2(disY, disX) * 57;
	}

	private fire(): void {
		this.robot.gotoAndPlay(1, 1);
		var shell: ShellRenderer = this.getIdelShell();
		shell.position = this.position;
		shell.getFSM().ChangeState(ShellMovingEntityStateSeek.instance);
		shell.rotation = this.robot.rotation;
		// shell.displayObject.scaleX = shell.displayObject.scaleY = this.data.level == 0 ? 1 : this.data.level;
		this.data.gunCount--;
		this.shellContent.addChild(shell.displayObject);
		// this.shellContent.addChild(shell.testBox);
		this.lastSendTime = egret.getTimer();

	}

	private getIdelShell(): ShellRenderer {
		var shell: ShellRenderer = EntityManager.instance.getAvailableEntity<ShellRenderer>(ShellRenderer);
		shell.setData(this.shellVo);
		shell.owner = this;
		this.shellList[shell.sid] = shell;
		return shell;
	}

	public clearnShell(id: string): void {
		delete this.shellList[id];
	}

	public fillData(): void {
		this.nameText.text = this.data.name;
		this.lvText.text = "LV:" + this.data.level;
		this.lvBar.maximum = this.data.totalExp;
		this.lvBar.minimum = 0;
	}

	public updateData(): void {
		if (this.skinLoaded) {
			this.lvBar.value = this.data.currentExp;
			this.gunText.text = this.data.gunCount.toString();
			this.moneyText.text = this.data.moeny.toString();
			this.lvText.text = this.data.level.toString();
			this.shellVo = this.data.level == 0 ? ConfigModel.instance.shellList[1] : ConfigModel.instance.shellList[this.data.gunLevel];
		}
	}

	public killFish(fish: FishVo): void {
		this.data.currentExp++;
		if (this.data.currentExp > this.data.totalExp) {
			this.data.currentExp = 0;
			this.data.level++;
			this.data.totalExp = (this.data.totalExp + this.data.level * 5);
			this.lvBar.maximum = this.data.totalExp;
			this.lvBar.minimum = 0;
			GameDispatcher.send(GameEvent.LEVEL_UP_EVENT);
		}
		this.data.moeny += fish.rate;
		this.updateData();
	}
}