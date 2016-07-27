class HallView extends BaseComponent implements IBase {

	private room1Btn: eui.Button;
	private room2Btn: eui.Button;
	private roomInfoPanel: RoomInfoListPanel;

	public constructor() {
		super();
		this.skinName = "resource/game_skins/LabbySkin.exml";
		this.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onTap, this)
	}

	public enter(data?: any): void {

	}

	public exit(): void {

	}

	public execute(data?: any): void {

	}

	private onTap(evt: egret.TouchEvent): void {
		evt.target.name
		switch (evt.target) {
			case this.room1Btn:
				this.showRoomInfoListPanel();
				break;
			case this.room2Btn:
				this.showRoomInfoListPanel();
				break;
		}
	}

	private showRoomInfoListPanel(data?: any): void {
		if (this.roomInfoPanel == null) {
			this.roomInfoPanel = new RoomInfoListPanel();
		}
		this.addChild(this.roomInfoPanel);
		this.roomInfoPanel.enter(data);
	}
}