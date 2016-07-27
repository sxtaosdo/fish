/**
 * 大厅房间信息列表
 */
class RoomInfoListPanel extends BaseComponent implements IBase {
	private closeBtn: eui.Button;
	private dataList: eui.List;
	private collection: eui.ArrayCollection();

	public constructor() {
		super();
		var sp: egret.Sprite = new egret.Sprite();
		sp.graphics.beginFill(0x000000, 0);
		sp.graphics.drawRect(-Main.GAME_WIDTH >> 1, -Main.GAME_HEIGHT >> 1, Main.GAME_WIDTH, Main.GAME_HEIGHT);
		sp.graphics.endFill();
		this.addChild(sp);
		// this.width = Main.GAME_WIDTH;
		// this.height = Main.GAME_HEIGHT;
		this.skinName = "resource/game_skins/LabbyRoomInfoListSkin.exml";
		this.dataList.itemRenderer = RoomInfoListRenderer;
		this.collection = new eui.ArrayCollection();
	}

	public enter(data?: any): void {
		if (this.skinLoaded) {
			this.closeBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onCloseBtn, this);
			this.collection.removeAll();
			data.forEach(element => {
				this.collection.addItem(element);
			});
			this.dataList.dataProvider = this.collection;
		}
	}

	public exit(): void {
		if (this.parent != null) {
			this.parent.removeChild(this);
		}
		this.closeBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onCloseBtn, this);
	}

	public execute(data?: any): void {

	}

	private onCloseBtn(): void {
		this.exit();
	}
}