class RoomInfoVo {

	public id: number;
	public name: string;
	public list: Array<RoomInfoItemVo>;

	public constructor() {
		this.list = new Array<RoomInfoItemVo>();
	}

	public analysis(data: any): void {
		this.id = data.id;
		this.name = data.name;
		data.list.forEach(element => {
			var vo: RoomInfoItemVo = new RoomInfoItemVo();
			vo.analysis(element);
			this.list.push(vo);
		});
	}
}

class RoomInfoItemVo {
	public index: number;
	public name: string;
	public state: number;
	public desc: string;
	public min: number;

	public analysis(data: any): void {
		this.index = data.index;
		this.name = data.name;
		this.state = data.state;
		this.desc = data.desc;
		this.min = data.min;
	}
}