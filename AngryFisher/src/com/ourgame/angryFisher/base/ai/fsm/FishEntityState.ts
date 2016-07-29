
/**
 * 寻找
 */
class FishStateSeek implements IState {
	private static _instance: FishStateSeek;
	private client: ClientModel;

	public constructor() {

	}

	public static get instance(): FishStateSeek {
		if (this._instance == null) {
			this._instance = new FishStateSeek();
		}
		return this._instance;
	}


    public onMessage(entity: IBaseGameEntity, telegram: Telegram): boolean {
		return false;
	}

    public enter(entity: IBaseGameEntity): void {
		this.client = ClientModel.instance;
		entity.isDestroy = false;
		var fish: FishRenderer = (<FishRenderer>entity);
		if (fish.pathStep == 0) {
			fish.clientPathList=fish.pathList;
			//设置第一个点
			fish.currentPath = fish.clientPathList[0];
			fish.pathStep = 1;
			fish.rotation = fish.currentPath.rotation;
			entity.getDisplayObject().x = fish.currentPath.x;
			entity.getDisplayObject().y = fish.currentPath.y;
		}
	}

    public execute(entity: IMovingEneity): void {
		var fish: FishRenderer = (<FishRenderer>entity);
		var pp: PathPoint = fish.clientPathList[fish.pathStep];
		if (pp == null) {
			entity.getFSM().ChangeState(FishStateDestroy.instance);
		} else {
			entity.getDisplayObject().y = pp.y;
			entity.getDisplayObject().x = pp.x;
			entity.getDisplayObject().rotation = pp.rotation;
			fish.pathStep++;
		}
	}

    public exit(entity: IBaseGameEntity): void {

	}
}

/**
 * 寻找2,绿色算法
 */
// class FishStateSeek2 implements IState {
// 	private static _instance: FishStateSeek;
// 	private client: ClientModel;

// 	public constructor() {

// 	}

// 	public static get instance(): FishStateSeek {
// 		if (this._instance == null) {
// 			this._instance = new FishStateSeek();
// 		}
// 		return this._instance;
// 	}


//     public onMessage(entity: IBaseGameEntity, telegram: Telegram): boolean {
// 		return false;
// 	}

//     public enter(entity: IBaseGameEntity): void {
// 		this.client = ClientModel.instance;
// 		entity.isDestroy = false;
// 		var fish: FishRenderer = (<FishRenderer>entity);
// 		if (fish.pathStep == 0) {
// 			//设置第一个点
// 			fish.currentPath = fish.pathList[0];
// 			fish.pathStep = 1;
// 			entity.getDisplayObject().x = fish.currentPath.x;
// 			entity.getDisplayObject().y = fish.currentPath.y;
// 			//计算客户端需要的路径点
// 		}
// 		fish.nextPath = fish.pathList[fish.pathStep + 1];
// 		fish.rotation = Math.atan2((fish.nextPath.y - fish.currentPath.y), (fish.nextPath.x - fish.currentPath.x));

// 	}

//     public execute(entity: IMovingEneity): void {
// 		var fish: FishRenderer = (<FishRenderer>entity);
// 		if (fish.displayObject.parent != null) {
// 			fish.displayObject.x += 5;
// 			if (fish.displayObject.x - fish.displayObject.width > fish.displayObject.stage.stageWidth) {
// 				fish.displayObject.y += (100 + Math.random() * 15);
// 				fish.displayObject.x = 0;
// 			}
// 			if (fish.displayObject.y > fish.displayObject.stage.stageHeight) {
// 				// fish.displayObject.parent.removeChild(fish.displayObject);
// 				fish.displayObject.y = Math.random() * 15 + 30;
// 			}
// 		}

// 	}

//     public exit(entity: IBaseGameEntity): void {

// 	}
// }

/**
 * 抵达
 */
class FishStateArrive implements IState {
	private static _instance: FishStateArrive;
	private client: ClientModel;

	public constructor() {

	}

	public static get instance(): FishStateArrive {
		if (this._instance == null) {
			this._instance = new FishStateArrive();
		}
		return this._instance;
	}


    public onMessage(entity: IBaseGameEntity, telegram: Telegram): boolean {
		return false;
	}

    public enter(entity: IBaseGameEntity): void {
		var fish: FishRenderer = (<FishRenderer>entity);
		if (fish.pathStep >= fish.pathList.length) {
			entity.getFSM().ChangeState(FishStateDestroy.instance);	//走完了所有的点
		} else {
			fish.pathStep += 1;
			entity.getFSM().ChangeState(FishStateSeek.instance);
		}
	}

    public execute(entity: IBaseGameEntity): void {

	}

    public exit(entity: IBaseGameEntity): void {
		entity.isDestroy = true;
	}
}

/**
 * 死亡
 */
class FishStateDeath implements IState {
	private static _instance: FishStateDeath;
	private client: ClientModel;

	public constructor() {

	}

	public static get instance(): FishStateDeath {
		if (this._instance == null) {
			this._instance = new FishStateDeath();
		}
		return this._instance;
	}


    public onMessage(entity: IBaseGameEntity, telegram: Telegram): boolean {
		return false;
	}

	//播放死亡动画
	//播放金币动画
    public enter(entity: IBaseGameEntity): void {
		var fish: FishRenderer = (<FishRenderer>entity);
		(<egret.MovieClip>fish.displayObject).stop();
		// egret.Tween.get(fish.displayObject).call(() => {
		// 	fish.displayObject.filters = [MatrixUtils.blurFliter];
		// }).wait(100).call(() => {
		// 	fish.displayObject.filters = [MatrixUtils.blurFliter];
		// }).wait(100).call(() => { fish.displayObject.filters = [MatrixUtils.blurFliter]; }).wait(100).call(() => {
		// 	if (fish.displayObject.parent != null) {
		// 		fish.displayObject.parent.removeChild(fish.displayObject);
		// 	}
		// 	entity.getFSM().ChangeState(FishStateDestroy.instance);
		// });
		//死亡动画
		var mc: egret.MovieClip = MovieclipUtils.createMc("fishd1_png", "fishd1_json");
		mc.x = fish.displayObject.x;
		mc.y = fish.displayObject.y;
		mc.rotation = fish.displayObject.rotation;
		mc.anchorOffsetX = mc.width >> 1;
		mc.anchorOffsetY = mc.height >> 1;
		fish.displayObject.parent.addChild(mc);
		fish.displayObject.parent.removeChild(fish.displayObject);
		fish.displayObject = mc;
		//倍率文字
		var bt: egret.BitmapText = new egret.BitmapText();
		bt.font = RES.getRes("sy1_fnt");
		bt.width = fish.displayObject.width;
		bt.textAlign = egret.HorizontalAlign.CENTER;
		bt.x = fish.displayObject.x;
		bt.y = fish.displayObject.y;
		bt.text = "x" + fish.getDataVo<FishVo>(FishVo).rate;
		fish.displayObject.parent.addChild(bt);
		mc.gotoAndPlay(1, 1);
		egret.Tween.get(this).wait(mc.totalFrames / 30 * 1000).call((bt: egret.BitmapText) => {
			bt.parent.removeChild(bt);
			entity.getFSM().ChangeState(FishStateDestroy.instance);
		}, this, [bt]);
	}

    public execute(entity: IBaseGameEntity): void {

	}

    public exit(entity: IBaseGameEntity): void {

	}
}

/**
 * 销毁
 */
class FishStateDestroy implements IState {
	private static _instance: FishStateDestroy;
	private client: ClientModel;

	public constructor() {

	}

	public static get instance(): FishStateDestroy {
		if (this._instance == null) {
			this._instance = new FishStateDestroy();
		}
		return this._instance;
	}


    public onMessage(entity: IBaseGameEntity, telegram: Telegram): boolean {
		return false;
	}

    public enter(entity: IBaseGameEntity): void {
		entity.isDestroy = true;
		var fish: FishRenderer = (<FishRenderer>entity);
		(<egret.MovieClip>fish.displayObject).stop();
		if (fish.displayObject.parent != null) {
			fish.displayObject.parent.removeChild(fish.displayObject);
		}
		// delete ClientModel.instance.fishList[fish.sid];
	}

    public execute(entity: IBaseGameEntity): void {

	}

    public exit(entity: IBaseGameEntity): void {

	}
}