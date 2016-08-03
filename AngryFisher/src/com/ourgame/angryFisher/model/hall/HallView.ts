class HallView extends BaseComponent implements IBase {

	private room1Btn: eui.Button;
	private room2Btn: eui.Button;
	private roomInfoPanel: RoomInfoListPanel;
	private lightMc: egret.MovieClip;
	private qpMc: egret.MovieClip;

	public constructor() {
		super();
		this.skinName = "resource/game_skins/LabbySkin.exml";
		this.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onTap, this)
	}

	public enter(data?: any): void {
		// console.log(egret.Capabilities.runtimeType);

		if (!egret.Capabilities.isMobile) {
			// this.lightMc = MovieclipUtils.createMc("lightMc_png", "lightMc_json");
			// this.lightMc.play(-1);
			// this.lightMc.y = -100;
			// this.addChildAt(this.lightMc, 1);
		}

		this.qpMc = MovieclipUtils.createMc("qiPaoMc_png", "qiPaoMc_json");
		this.qpMc.play(-1);
		this.qpMc.x = 300;
		this.qpMc.y = 400;
		this.addChildAt(this.qpMc, 1);
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