class FishVo {
	public name: string;
	public id: number;
	public path: Array<PathPoint>;
	public index: number;

	public constructor() {
		this.path = new Array<PathPoint>();
	}

	public analysis(data: any): void {
		this.name = data.name;
		this.id = data.id;
		var key: any;
		var index: number = 0;
		for (key in data.path) {
			var vo: PathPoint = new PathPoint();
			vo.analysis(data.path[key]);
			vo.index = index;
			this.path.push(vo);
			index++;
		}
	}
}