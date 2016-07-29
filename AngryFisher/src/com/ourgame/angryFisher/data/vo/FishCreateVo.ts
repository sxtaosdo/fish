class FishCreateVo {
	public id: number;
	/**
	 * 鱼群基础ID，每条鱼在此基础上++ 
	 */
	public groupID: number;
	/**
	 * 鱼的类型 
	 */
	public fishType: number;
	/**
	 * 生成时间 
	 */
	public createTime: number;
	/**
	 * 两点之间的时间 
	 */
	public speed: number;
	/**
	 *  鱼群的数量
	 */
	public fishCount: number;
	/**
	 * 同步用随机种子 
	 */
	public randomSeed: number;
	/**
	 * 鱼群的半径 
	 */
	public radius: number;
	/**
	 * 队伍间隔 
	 */
	public interval: number;
	/**
	 * 队伍方法 
	 */
	// public mClusterMethod:number;
	/**
	 * 路径ID 
	 */
	public pathID: number;
	/**
	 * 已经生成鱼的数量 
	 */
	public currentCount: number = 0;
	/**
	 * 当时的赛季，用来确定使用何种算法来解析路径
	 */
	// public currGamePeriodType:number;

	// public isLuckFish:boolean = false;

	public constructor() {
	}

	public analysis(data: any): void {
		this.id = data.id;
		this.fishType = data.fishType;
		this.createTime = data.createTime;
		this.speed = data.speed;
		this.fishCount = data.fishCount;
		this.radius = data.radius;
		this.interval = data.interval;
		this.pathID = data.pathID;

	}
}