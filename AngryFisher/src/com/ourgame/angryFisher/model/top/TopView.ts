class TopView extends BaseComponent implements IBase {

	private exitBtn: eui.Button;
	private autoBtn: eui.Button;

	public constructor() {
		super(false);
		this.skinName = "resource/game_skins/TopSkin.exml";
	}

	public enter(data?: any): void {
		if (this.skinLoaded) {
			this.exitBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onExit, this);
			this.execute(ClientModel.instance.gameState);
		}
	}

	public exit(): void {
		this.exitBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onExit, this);
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
		ClientModel.instance.changeGameState(new HallView());
	}
}