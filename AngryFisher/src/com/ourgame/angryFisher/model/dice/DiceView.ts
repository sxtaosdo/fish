class DiceView extends BaseComponent implements IBase {


	private contentScroller: eui.Scroller;
	private contentGroup: eui.Group;
	private closeBtn: eui.Button;
	private singeBtn: eui.Button;
	private getBtn: eui.Button;
	private infoBtn: eui.Button;
	private diceDoingBtn: eui.RadioButton;
	private diceCompleteBtn: eui.RadioButton;

	private light: egret.MovieClip;
	private bomb: egret.MovieClip;
	private logo: egret.MovieClip;
	private goBtn: egret.MovieClip;
	private diceMc: egret.MovieClip;
	private paopao: egret.MovieClip;
	private bg: egret.Bitmap;
	private diceImage: egret.Bitmap;
	private availableTimesText: egret.BitmapText;

	private game: DiceGamePanel;
	private gameMask: egret.Sprite;

	private playing: boolean = false;

	public constructor() {
		super(false);
		this.skinName = "resource/game_skins/dice/DicePanelSkin.exml";
		this.y = 25;

		this.gameMask = new egret.Sprite();
		this.gameMask.width = 745;
		this.gameMask.height = 355;
		this.gameMask.graphics.beginFill(0x000000);
		this.gameMask.graphics.drawRoundRect(0, 0, 745, 355, 60, 60);
		this.gameMask.graphics.endFill();
		this.gameMask.x = DiceGamePanel.ZERO_POINT_X;
		this.gameMask.y = DiceGamePanel.ZERO_POINT_Y;
		this.addChild(this.gameMask);

		this.game = new DiceGamePanel();
		this.contentScroller.mask = this.gameMask;

		this.contentGroup.addChild(this.game);
		this.contentScroller.viewport = this.contentGroup;
		this.contentGroup.setLayoutBoundsSize(1500, 760)

		this.bg = BitMapUtil.createBitmapByName("lobbyBg_png");
		this.bg.alpha = 0.8;
		this.bg.y = 14;
		this.addChildAt(this.bg, 0);

		this.availableTimesText = new egret.BitmapText();
		this.availableTimesText.font = RES.getRes("dice1_fnt");
		this.availableTimesText.width = 60;
		this.availableTimesText.textAlign = egret.HorizontalAlign.CENTER;
		this.availableTimesText.x = 55;
		this.availableTimesText.y = 25;
		this.availableTimesText.letterSpacing = -20;
		this.addChild(this.availableTimesText);
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
		this.goBtn.touchEnabled = true;
		this.goBtn.x = 850;
		this.goBtn.y = 450;
		this.addChild(this.goBtn);

		this.paopao = MovieclipUtils.createMc("DicePaoPao_png", "DicePaoPao_json");
		this.paopao.gotoAndPlay(1, -1);
		this.paopao.touchEnabled = false;
		this.paopao.x = 300;
		this.paopao.y = 370;
		this.addChild(this.paopao);

		this.diceDoingBtn.selected = true;
    }

	public enter(data?: any): void {
		if (this.skinLoaded) {
			this.getBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onGetBtn, this);
			this.infoBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onInfoBtn, this);
			this.goBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onGoBtn, this);
		}
		this.game.enter();
		GameDispatcher.addEventListener(BaseEvent.DICE_GO_RESULT_EVENT, this.onGoResult, this);
		GameDispatcher.addEventListener(BaseEvent.DICE_INFO_EVENT, this.onDiceInfo, this);
		ConnectionManager.instance.sendHelper.diceInfo();
	}

	public exit(): void {
		if (this.parent != null) {
			this.parent.removeChild(this);
			ClientModel.instance.changeGameState(new HallView());
		}
		this.getBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onGetBtn, this);
		this.infoBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onInfoBtn, this);
		this.goBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onGoBtn, this);
		this.game.exit();
		this.paopao.stop();
		this.logo.stop();
		this.goBtn.stop();
		this.light.stop();
	}

	public execute(data?: any): void {

	}

	private onGetBtn(): void {
		ClientModel.instance.openWindow(BindPanel);
	}

	private onInfoBtn(): void {
		ClientModel.instance.openWindow(HitInfoPanel);
	}

	private onGoBtn(): void {
		if (this.playing == false) {
			if (HallClientModel.instance.diceInfo.availableTimes > 0) {
				this.playing = true;
				ConnectionManager.instance.sendHelper.diceGo();
			} else {
				ClientModel.instance.openWindow(DiceAlert);
			}
		}
	}

	private onGoResult(): void {
		//处理骰子
		if (this.diceMc == null) {
			this.diceMc = MovieclipUtils.createMc("DiceBoxMc_png", "DiceBoxMc_json");
			this.diceMc.x = 300;
			this.diceMc.y = 120;
			this.diceMc.stop();
		}
		this.addChild(this.diceMc);
		this.diceMc.gotoAndPlay(1, 1);
		console.log("摇骰子结果：" + HallClientModel.instance.goResult);

		this.diceImage = BitMapUtil.createBitmapByName("dice" + HallClientModel.instance.goResult + "_png");
		this.diceImage.x = 365;
		this.diceImage.y = 402;
		this.diceImage.scaleX = this.diceImage.scaleY = 0.85;

		egret.Tween.get(this).wait(30 * 40).call(() => {
			this.addChildAt(this.diceImage, this.numChildren - 1);
		}, this).wait(30 * 33).call(() => {
			if (this.diceImage.parent) {
				this.diceImage.parent.removeChild(this.diceImage);
			}
			if (this.diceMc.parent) {
				this.diceMc.parent.removeChild(this.diceMc);
			}
			this.playing = false;
			//处理小鱼移动
			this.game.execute(HallClientModel.instance.goResult);
		});
	}

	private onDiceInfo(): void {
		this.availableTimesText.text = HallClientModel.instance.diceInfo.availableTimes.toString();
	}
}