/**
 * 顶部条
 */
class TopView extends BaseComponent implements IBase {

	private exitBtn: eui.Button;
	private autoBtn: eui.Button;
	private operationBtn: eui.Button;

	public constructor() {
		super(false);
		this.skinName = "resource/game_skins/TopSkin.exml";
	}

	public enter(data?: any): void {
		if (this.skinLoaded) {
			this.exitBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onExit, this);
			this.operationBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onOperation, this);
			this.autoBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onAuto, this);
			this.execute(ClientModel.instance.gameState);
		}
	}

	public exit(): void {
		this.exitBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onExit, this);
		this.operationBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onOperation, this);
			this.autoBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onAuto, this);
	}

	public execute(data?: any): void {
		if (data instanceof HallView) {
			this.exitBtn.visible = false;
			this.autoBtn.visible = false;
		} else if (data instanceof GameWorld) {
			this.exitBtn.visible = true;
			this.autoBtn.visible = true;
		}
	}

	private onExit(): void {
		// ClientModel.instance.changeGameState(new HallView());
		ClientModel.instance.openAlert("确定要退出吗？", () => {
			ClientModel.instance.changeGameState(new HallView());
		})
	}

	private onOperation(): void {
		if (ConfigModel.instance.showTest) {
            var test: TestWindow = new TestWindow();
            this.stage.addChild(test);
            test.enter(this.parent.parent);
        }
	}

	private onAuto():void{
		
	}
}