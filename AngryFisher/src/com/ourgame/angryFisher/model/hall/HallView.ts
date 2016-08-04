class HallView extends BaseComponent implements IBase {

	private room1Btn: eui.Button;
	private room2Btn: eui.Button;
	private roomInfoPanel: RoomInfoListPanel;
	private lightMc: egret.MovieClip;
	private qpMc: egret.MovieClip;
	private paopao: egret.MovieClip;
	private jpText: egret.BitmapText;

	public constructor() {
		super();
		this.skinName = "resource/game_skins/LabbySkin.exml";
		this.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onTap, this);
	}

	public enter(data?: any): void {
		// console.log(egret.Capabilities.runtimeType);

		if (!egret.Capabilities.isMobile) {
			this.lightMc = MovieclipUtils.createMc("lightMc_png", "lightMc_json");
			this.lightMc.play(-1);
			this.lightMc.scaleX = this.lightMc.scaleY = 2;
			this.lightMc.alpha = 0.9;
			this.addChildAt(this.lightMc, 1);

			this.paopao = MovieclipUtils.createMc("paopao_png", "paopao_json");
			this.paopao.play(-1);
			// this.lightMc.scaleX = this.lightMc.scaleY = 2;
			// this.lightMc.alpha = 0.9;
			this.paopao.x = 300;
			this.paopao.y = Main.GAME_HEIGHT - 200;
			this.addChildAt(this.paopao, 1);
		}

		this.qpMc = MovieclipUtils.createMc("qiPaoMc_png", "qiPaoMc_json");
		this.qpMc.play(-1);
		this.qpMc.x = 300;
		this.qpMc.y = 400;
		this.addChildAt(this.qpMc, 1);

		this.jpText = new egret.BitmapText();
		this.jpText.font = RES.getRes("sy1_fnt");
		this.jpText.text = "500000000";
		TimerManager.instance.doLoop(1000, () => {
			this.jpText.text = (parseInt(this.jpText.text) + RandomUtil.randInt(1, 100)).toString();
		});
		this.jpText.x = 190;
		this.jpText.y = 50;
		this.jpText.width = 210;
		this.jpText.textAlign = egret.HorizontalAlign.CENTER;
		this.addChild(this.jpText);
	}

	public exit(): void {
		if (this.parent != null) {
			this.parent.removeChild(this);
		}
		if (this.lightMc) {
			this.lightMc.stop();
		}
		this.qpMc.stop();
		this.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onTap, this)
	}

	public execute(data?: any): void {

	}

	private onTap(evt: egret.TouchEvent): void {
		evt.target.name
		switch (evt.target) {
			case this.room1Btn:
				this.showRoomInfoListPanel(ConfigModel.instance.roomList[0]);
				break;
			case this.room2Btn:
				this.showRoomInfoListPanel(ConfigModel.instance.roomList[1]);
				break;
		}
	}

	private showRoomInfoListPanel(data: RoomInfoVo): void {
		if (this.roomInfoPanel == null) {
			this.roomInfoPanel = new RoomInfoListPanel();
		}
		this.addChild(this.roomInfoPanel);
		this.roomInfoPanel.enter(data);
	}
}