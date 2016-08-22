/**
 * 顶部条
 */
class TopView extends BaseComponent implements IBase {

	public exitBtn: eui.Button;
	public rechargeBtn: eui.Button;
	public mailBtn: eui.Button;
	public helpBtn: eui.Button;
	public operationBtn: eui.Button;
	public autoBtn: eui.Button;
	public userInfo: eui.Group;
	public userMoneyText: eui.BitmapLabel;
	public roomInfo: eui.Group;
	public listScroller: eui.Scroller;
	public roomList: eui.List;
	public bugGunBtn: eui.Button;
	public lockBtn: eui.Button;
	public roomNameText: eui.Label;
	public bgImage: eui.Image;

	private roomListData: eui.ArrayCollection;

	public constructor() {
		super(false);
		this.skinName = "resource/game_skins/TopSkin.exml";
		this.roomListData = new eui.ArrayCollection();
	}

	protected onSkinComplete(e: any): void {
		super.onSkinComplete(e);
		this.roomList.visible = false;
		this.bgImage.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onRoomBgTap, this);
		this.roomList.addEventListener(eui.ItemTapEvent.ITEM_TAP, this.onSelectRoom, this);
		this.userMoneyText.font = RES.getRes("sy1_fnt");
	}

	public enter(data?: any): void {
		if (this.skinLoaded) {
			this.exitBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onExit, this);
			this.operationBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onOperation, this);
			this.helpBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onHelp, this);
			this.autoBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onAuto, this);
			this.mailBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onMail, this);
			this.rechargeBtn.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onRechargel, this);
			this.execute(ClientModel.instance.gameState);

			this.userMoneyText.text = UserModel.instance.vo.moeny.toString();
		}
	}

	public exit(): void {
		this.exitBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onExit, this);
		this.operationBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onOperation, this);
		this.autoBtn.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onAuto, this);
	}

	public execute(data?: any): void {
		if (data instanceof HallView) {
			this.exitBtn.visible = false;
			this.autoBtn.visible = false;
			this.userInfo.visible = false;
			this.roomInfo.visible = false;
			this.bugGunBtn.visible = false;
			this.lockBtn.visible = false;
		} else if (data instanceof GameWorld) {
			this.exitBtn.visible = true;
			this.autoBtn.visible = true;
			this.userInfo.visible = true;
			this.roomInfo.visible = true;
			this.bugGunBtn.visible = true;
			this.lockBtn.visible = true;


			this.roomNameText.text = HallClientModel.instance.selectRoomIndex.name;

			var key: any;
			for (key in ConfigModel.instance.roomList) {
				var key2: any;
				for (key2 in ConfigModel.instance.roomList[key].list) {
					if (ConfigModel.instance.roomList[key].list[key2].state == 1) {
						this.roomListData.addItem(ConfigModel.instance.roomList[key].list[key2].name);
					}
				}
			}
			this.roomList.dataProvider = this.roomListData;
		}
	}

	private onExit(): void {
		ClientModel.instance.openAlert("确定要退出吗？", () => {
			ClientModel.instance.changeGameState(new HallView());
		})
	}

	private onRoomBgTap(evt?: egret.TouchEvent): void {
		if (evt instanceof egret.TouchEvent) {
			evt.stopImmediatePropagation();
			evt.stopPropagation();
		}
		this.roomList.visible = !this.roomList.visible;
		if (this.roomList.visible) {
			this.stage.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onRoomBgTap, this);
		} else {
			this.stage.removeEventListener(egret.TouchEvent.TOUCH_TAP, this.onRoomBgTap, this);
		}
	}

	private onSelectRoom(e: eui.ItemTapEvent): void {
		this.onRoomBgTap();
	}

	private onOperation(): void {
		ClientModel.instance.openWindow(OperationPanel);
	}

	private onHelp(): void {
		ClientModel.instance.openWindow(HelpPanel);
	}
	private onMail(): void {
		ClientModel.instance.openWindow(MailPanel);
	}
	private onRechargel(): void {
		InterfaceManager.instance.recharge();
	}

	private onAuto(): void {

	}

	private onData(): void {

	}
}