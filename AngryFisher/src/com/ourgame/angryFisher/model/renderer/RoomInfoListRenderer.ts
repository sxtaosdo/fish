class RoomInfoListRenderer extends eui.ItemRenderer {

	private con: eui.Label;

	public constructor() {
		super();
		this.skinName = "resource/renderer/HallRoomInfoListItemSkin.exml"
	}

	public onChangeData(): void {
		var vo: RoomInfoVo = this.data;
		if (vo.state == "0") {
			this.con.text = "敬请期待";
		} else {
			this.con.text = vo.name + "<br>" + vo.desc + "<br>准入值" + vo.min;
		}
	}
}