class FishVo {
	public name: string;
	public id: number;
	public path: Array<PathPointVo>;
	public index: number;
	public rate: number;
	public hitTestLevel: number;

	public constructor() {
		this.path = new Array<PathPointVo>();
	}

	public analysis(data: any): void {
		this.name = data.name;
		this.rate = data.rate;
		this.id = data.id;
		this.hitTestLevel = data.hitTestLevel;
		var key: any;
		var index: number = 0;
		for (key in data.path) {
			var vo: PathPointVo = new PathPointVo();
			vo.analysis(data.path[key]);
			vo.index = index;
			this.path.push(vo);
			index++;
		}
	}
}