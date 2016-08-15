class PathPointVo {

	public index: number;
	public x: number;
	public y: number;
	public speed: number;
	public rotation: number;

	public constructor() {
	}

	public analysis(data: any): void {
		this.x = data[0];
		this.y = data[1];
		this.speed = data[2];
	}
}