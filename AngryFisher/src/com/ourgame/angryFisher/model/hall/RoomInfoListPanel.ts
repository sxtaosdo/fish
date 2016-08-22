/**
 * 大厅房间信息列表
 */
class RoomInfoListPanel extends BaseComponent implements IBase {
	private closeBtn: eui.Button;
	private dataList: eui.List;
	private collection: eui.ArrayCollection;

	public constructor() {
		super(false);
		var sp: egret.Sprite = new egret.Sprite();
		sp.graphics.beginFill(0x000000, 0);
		sp.graphics.drawRect(-207, -155, Main.STAGE_WIDTH, Main.STAGE_HEIGHT);
		sp.graphics.endFill();
		this.addChild(sp);
		// this.width = Main.GAME_WIDTH;
		// this.height = Main.GAME_HEIGHT;
		this.skinName = "resource/game_skins/LabbyRoomInfoListSkin.exml";
		this.collection = new eui.ArrayCollection();
	}

	protected onSkinComplete(e: any): void {
		super.onSkinComplete(e);
		this.dataList.itemRenderer = RoomInfoListRenderer;
		this.x = (Main.STAGE_WIDTH - this.width) / 3;
		this.y = (Main.STAGE_HEIGHT - this.height) >> 1;
	}

	public enter(data?: any): void {
		var temp: RoomInfoVo = data;
		if (this.skinLoaded) {
			this.closeBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onCloseBtn, this);
			this.dataList.addEventListener(eui.ItemTapEvent.ITEM_TAP, this.onSelect, this);
			this.collection.removeAll();
			temp.list.forEach(element => {
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

	private onSelect(evt: eui.ItemTapEvent): void {

		if (this.dataList.selectedItem.state == 1) {	//等于1为开启状态
			HallClientModel.instance.selectRoomIndex = this.dataList.selectedItem;
			ClientModel.instance.changeGameState(LoadingUI.instance);
			LoadingUI.instance.enter("resource/game_skins/LoadRoomSkin.exml");
			LoadingUI.instance.loadAssets(() => {
				ClientModel.instance.changeGameState(new GameWorld());
			}, LoadingUI.assets2);
		} else {
			console.log("敬请期待");

		}
	}
}