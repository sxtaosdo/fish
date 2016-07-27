class RoomInfoListRenderer extends eui.ItemRenderer {

	private infoText: eui.Label;
	private conText: egret.TextField;

	public constructor() {
		super();
		this.addEventListener(eui.UIEvent.COMPLETE, this.onSkinComplete, this);
		this.skinName = "resource/renderer/HallRoomInfoListItemSkin.exml";
	}

	protected onSkinComplete(e: any): void {
		this.conText = new egret.TextField();
		this.conText.x = this.infoText.x;
		this.conText.y = this.infoText.y;
		this.conText.width = this.infoText.width;
		this.conText.height = this.infoText.height;
		this.conText.size = this.infoText.size;
		this.conText.textColor = this.infoText.textColor;
		this.conText.lineSpacing = 3;
		this.addChild(this.conText);
	}

	public dataChanged(): void {
		var vo: RoomInfoItemVo = this.data;
		if (vo.state == 0) {
			// this.infoText.text = "敬请期待";
			this.conText.text = "敬请期待";
		} else {
			this.conText.textFlow = new egret.HtmlTextParser().parser("<font>" + vo.name + "\n" + vo.desc + "\n准入值" + vo.min + "</font>");
			// this.infoText.text = "<font>" + vo.name + "<br>" + vo.desc + "<br>准入值" + vo.min + "</font>";
		}
	}
}