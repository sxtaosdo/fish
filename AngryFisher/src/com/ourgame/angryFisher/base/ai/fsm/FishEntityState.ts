
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
			//计算客户端需要的路径点
			var lastPoint: PathPoint = fish.pathList[0];
			for (var i: number = 0; i < fish.pathList.length; i++) {
				var element: PathPoint = fish.pathList[i];
				var next: PathPoint = fish.pathList[i + 1];
				if (next != null) {
					var disX: number = next.x - lastPoint.x;
					var disY: number = next.y - lastPoint.y;
					var distance: number = Math.sqrt(disX * disX + disY * disY);
					var speedX: number = lastPoint.speed * disX / distance;
					var speedY: number = lastPoint.speed * disY / distance;
					var advanceTime: number = Math.floor(distance / lastPoint.speed);
					var rotation: number = Math.atan2(disY, disX) * 57 + 180;
					if (i == 0) {
						lastPoint.rotation = rotation;
						fish.clientPathList.push(lastPoint);
					}

					//起始点为上次计算的终点，不计入
					for (var j: number = 1; j < advanceTime; j++) {
						var pp: PathPoint = new PathPoint();
						pp.x = lastPoint.x + j * speedX;
						pp.y = lastPoint.y + j * speedY;
						pp.rotation = rotation;
						pp.speed = lastPoint.speed;
						fish.clientPathList.push(pp);
						if (j == advanceTime - 1) {
							lastPoint = pp;
						}
					}
				}
			}
			//设置第一个点
			fish.currentPath = fish.clientPathList[0];
			fish.pathStep = 1;
			fish.rotation = fish.currentPath.rotation;
			entity.getDisplayObject().x = fish.currentPath.x;
			entity.getDisplayObject().y = fish.currentPath.y;
		}

		// this.client = ClientModel.instance;
		// entity.isDestroy = false;
		// var fish: FishRenderer = (<FishRenderer>entity);
		// if (fish.pathStep == 0) {
		// 	//设置第一个点
		// 	fish.currentPath = fish.pathList[0];
		// 	fish.pathStep = 1;
		// 	entity.getDisplayObject().x = fish.currentPath.x;
		// 	entity.getDisplayObject().y = fish.currentPath.y;
		// 	//计算客户端需要的路径点
		// }
		// fish.nextPath = fish.pathList[fish.pathStep + 1];
		// fish.rotation = Math.atan2((fish.nextPath.y - fish.currentPath.y), (fish.nextPath.x - fish.currentPath.x));

	}

    public execute(entity: IMovingEneity): void {
		var fish: FishRenderer = (<FishRenderer>entity);
		var pp: PathPoint = fish.clientPathList.shift();
		if (pp == null) {
			entity.getFSM().ChangeState(FishStateDeath.instance);
		} else {
			entity.getDisplayObject().y = pp.y;
			entity.getDisplayObject().x = pp.x;
			entity.getDisplayObject().rotation = pp.rotation;
		}
		// console.log("posX:"+pp.x.toString());
		// console.log("posY:"+pp.y.toString());
		// console.log("rotation:"+pp.rotation.toString());
		// if(this.bbrotation==999){
		// 	this.bbrotation=pp.rotation;
		// }
		// else if(this.bbrotation!=pp.rotation){
		// 	this.bbrotation=pp.rotation;
		// }

		// var x: number = entity.getDisplayObject().x - entity["nextPath"].x;
		// var y: number = entity.getDisplayObject().y - entity["nextPath"].y;
		// var distance: number = Math.sqrt(x * x + y * y);
		// if (distance < entity.speed) {
		// 	entity.getDisplayObject().y = entity["nextPath"].x;
		// 	entity.getDisplayObject().x = entity["nextPath"].y;
		// }
		// if ((entity.getDisplayObject().y == entity.speedY) && (entity.getDisplayObject().x == entity.speedX)) {
		// 	entity.getFSM().ChangeState(FishStateArrive.instance);
		// }





		// if (fish.displayObject.parent != null) {
		// 	fish.displayObject.x += 5;
		// 	if (fish.displayObject.x - fish.displayObject.width > fish.displayObject.stage.stageWidth) {
		// 		fish.displayObject.y += (100 + Math.random() * 15);
		// 		fish.displayObject.x = 0;
		// 	}
		// 	if (fish.displayObject.y > fish.displayObject.stage.stageHeight) {
		// 		// fish.displayObject.parent.removeChild(fish.displayObject);
		// 		fish.displayObject.y = Math.random() * 15 + 30;
		// 	}
		// }

	}

    public exit(entity: IBaseGameEntity): void {

	}
}

/**
 * 抵达
 */
class FishStateArrive {
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
			entity.getFSM().ChangeState(FishStateDeath.instance);	//走完了所有的点
		} else {
			fish.pathStep += 1;
			entity.getFSM().ChangeState(FishStateSeek.instance);
		}
	}

    public execute(entity: IBaseGameEntity): void {

	}

    public exit(entity: IBaseGameEntity): void {
		//生成网
		entity.isDestroy = true;
	}
}

class FishStateDeath {
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

    public enter(entity: IBaseGameEntity): void {
		var fish: FishRenderer = (<FishRenderer>entity);
		(<egret.MovieClip>fish.displayObject).stop();
		egret.Tween.get(fish.displayObject).call(() => {
			fish.displayObject.filters = [MatrixUtils.blurFliter];
		}).wait(100).call(() => {
			fish.displayObject.filters = [MatrixUtils.blurFliter];
		}).wait(100).call(() => { fish.displayObject.filters = [MatrixUtils.blurFliter]; }).wait(100).call(() => {
			if (fish.displayObject.parent != null) {
				fish.displayObject.parent.removeChild(fish.displayObject);
			}
			entity.isDestroy = true;
			delete ClientModel.instance.fishList[fish.sid];
		})
	}

    public execute(entity: IBaseGameEntity): void {

	}

    public exit(entity: IBaseGameEntity): void {
		//生成网
	}
}