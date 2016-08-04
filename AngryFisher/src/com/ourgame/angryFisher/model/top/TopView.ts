/**
 * 顶部条
 */
class TopView extends BaseComponent implements IBase {

	public exitBtn: eui.Button;
	public rechargeBtn: eui.Button;
	public mailBtn: eui.Button;
	public helpBtn: eui.Button;
	public operationBtn: eui.Button;
	public autoBtn: eui.Button;


	public constructor() {
		super(false);
		this.skinName = "resource/game_skins/TopSkin.exml";
	}

	public enter(data?: any): void {
		if (this.skinLoaded) {
			this.exitBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onExit, this);
			this.operationBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onOperation, this);
			this.helpBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onHelp, this);
			this.autoBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onAuto, this);
			this.mailBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onMail, this);
			this.rechargeBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onRechargel, this);
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
		ClientModel.instance.openWindow(OperationPanel);
	}

	private onHelp(): void {
		ClientModel.instance.openWindow(HelpPanel);
	}
	private onMail(): void {
		ClientModel.instance.openWindow(MailPanel);
	}
	private onRechargel(): void {
		InterfaceManager.instance.recharge();
	}

	private onAuto(): void {

	}

	private onData(): void {

	}
}