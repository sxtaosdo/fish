class JpBarPanel extends BaseComponent implements IBase {

	private mc: egret.MovieClip;
	private flash: egret.MovieClip;

	public constructor() {
		super(false);
		this.skinName = "resource/game_skins/JpBarSkin.exml";
		this.touchChildren = false;
	}

	protected onSkinComplete(e: any): void {
        super.onSkinComplete(e);
    }

	public enter(data?: any): void {
		this.flash = MovieclipUtils.createMc("jpBarFlashMc_png", "jpBarLightMc_json");
		this.flash.gotoAndPlay(1, -1);
		this.flash.scaleX = this.flash.scaleY = 0.65;
		this.flash.x = 100;
		this.flash.y = 12;
		this.addChild(this.flash);

		this.mc = MovieclipUtils.createMc("jpBarLightMc_png", "jpBarLightMc_json");
		this.mc.gotoAndPlay(1, -1);
		this.mc.x = 42;
		this.addChild(this.mc);

		this.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onTap, this);
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

	private onTap(): void {
		ClientModel.instance.openWindow(RankPanel);
	}
}