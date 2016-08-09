/**
 * 步步为营地格信息
 */
class GridVo {
	public index: number = 0;
	public rewardType: number = 0;
	public rewardNum: number = 0;
	public offsetX: number = 0;
	public offsetY: number = 0;
	public isCover: boolean;
	public x: number = 0;
	public y: number = 0;

	public constructor() {
	}

	public analysis(data: any): void {
		this.index = parseInt(data.index);
		this.rewardType = parseInt(data.rewardType)
		this.rewardNum = parseInt(data.rewardNum)
		this.offsetX = parseInt(data.offsetX)
		this.offsetY = parseInt(data.offsetY)
		this.x = parseInt(data.x)
		this.y = parseInt(data.y)
		this.isCover = data.isCover == "0" ? false : true;
	}
}