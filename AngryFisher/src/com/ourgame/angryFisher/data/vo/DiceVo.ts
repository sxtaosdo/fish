class DiceVo {

	public id: number = 0;
	public total: number = 0;
	public final: number = 0;
	public awardMap: Object;
	public girdList: Array<GridVo>;
	

	public constructor() {
		this.awardMap = {};
		this.girdList = new Array<GridVo>();
	}

	public analysis(data: any): void {
		this.total = data.total;
		this.final = data.final;
		var key: any;
		var index: number = 0;

		for (key in data.awardMap) {
			this.awardMap[index] = data.awardMap[index];
			index++;
		}

		var list = data.Grid;
        for (key in list) {
            var vo: GridVo = new GridVo();
            vo.analysis(list[key]);
            this.girdList.push(vo);
        }
	}
}