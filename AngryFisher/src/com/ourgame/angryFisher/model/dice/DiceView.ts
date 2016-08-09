class DiceView extends BaseComponent implements IBase {


	public closeBtn: eui.Button;
	public singeBtn: eui.Button;
	public getBtn: eui.Button;
	public infoBtn: eui.Button;
	public contentScroller: eui.Scroller;


	private light: egret.MovieClip;
	private bomb: egret.MovieClip;
	private logo: egret.MovieClip;
	private goBtn: egret.MovieClip;
	private bg: egret.Bitmap;

	private game: DiceGamePanel;
	private gameMask: egret.Sprite;

	public constructor() {
		super(false);
		this.skinName = "resource/game_skins/dice/DicePanelSkin.exml";
		this.y = 25;

		this.gameMask = new egret.Sprite();
		this.gameMask.width = 750;
		this.gameMask.height = 350;
		this.gameMask.graphics.beginFill(0x000000);
		this.gameMask.graphics.drawRect(0, 0, 750, 350);
		this.gameMask.graphics.endFill();
		this.gameMask.x = DiceGamePanel.ZERO_POINT_X;
		this.gameMask.y = DiceGamePanel.ZERO_POINT_Y;
		this.addChild(this.gameMask);

		this.game = new DiceGamePanel();
		this.game.mask = this.gameMask;
		this.addChildAt(this.game, 0);

		this.bg = BitMapUtil.createBitmapByName("lobbyBg_png");
		this.bg.alpha = 0.8;
		this.bg.y = 14;
		this.addChildAt(this.bg, 0);
	}

	protected onSkinComplete(e: any): void {
        super.onSkinComplete(e);

		this.light = MovieclipUtils.createMc("DiceLightMc_png", "DiceLightMc_json");
		this.light.gotoAndPlay(1, -1);
		this.light.x = 14;
		this.addChild(this.light);

		this.logo = MovieclipUtils.createMc("DiceLogoMc_png", "DiceLogoMc_json");
		this.logo.gotoAndPlay(1, -1);
		this.logo.x = 146;
		this.logo.y = 17;
		this.addChild(this.logo);

		this.goBtn = MovieclipUtils.createMc("DiceGoBtnMc_png", "DiceGoBtnMc_json");
		this.goBtn.gotoAndPlay(1, -1);
		this.goBtn.x = 850;
		this.goBtn.y = 450;
		this.addChild(this.goBtn);
    }

	public enter(data?: any): void {
		if (this.skinLoaded) {
			this.getBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onGetBtn, this);
			this.infoBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onInfoBtn, this);
		}
		this.game.enter();
	}

	public exit(): void {
		if (this.parent != null) {
			this.parent.removeChild(this);
			ClientModel.instance.changeGameState(new HallView());
		}
		this.game.exit();
	}

	public execute(data?: any): void {

	}

	private onGetBtn(): void {
		ClientModel.instance.openWindow(BindPanel);
	}

	private onInfoBtn(): void {
		ClientModel.instance.openWindow(HitInfoPanel);
	}
}