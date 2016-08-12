class LevelUpPanel extends BaseComponent implements IWindow {

	public levelText: eui.Label;

	public constructor() {
		super()
		this.skinName = "resource/game_skins/window/LevelUpSkin.exml";
	}

	protected onSkinComplete(e: any): void {
        super.onSkinComplete(e);
    }

	public enter(data?: any): void {
		this.levelText.text = UserModel.instance.vo.level.toString();
		TimerManager.instance.doOnce(2000, this.exit, this);
	}

	public exit(): void {
		ClientModel.instance.openWindow(null);
	}

	public execute(data?: any): void {

	}

	public init(): void {

	}

    public destroy(): void {

	}
}