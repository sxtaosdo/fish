/**
 * 海底配置
 */
class DeabedVo {

	public id: number;
	public name: string;
	public bg: string;
	public plant: Array<PlantVo>;

	public constructor() {
		this.plant = new Array<PlantVo>();
	}

	public analysis(data: any): void {
		this.id = data.id;
		this.name = data.name;
		this.bg = data.bg;
		var key: any;
		for (key in data.plant) {
			var vo: PlantVo = new PlantVo();
			vo.analysis(data.plant[key]);
			this.plant.push(vo);
		}
	}
}

/**
 * 植物
 */
class PlantVo {

	public x: number;
	public y: number;
	public id: number;

	public constructor() {

	}

	public analysis(data: any): void {
		this.x = data.x;
		this.y = data.y;
		this.id = data.id;
	}
}