// class MovingEntityState implements IState {

// 	private static _instance: MovingEntityState;

// 	public constructor() {
// 	}

// 	public static get instance(): MovingEntityState {
// 		if (this._instance == null) {
// 			this._instance = new MovingEntityState();
// 		}
// 		return this._instance;
// 	}


//     public onMessage(entity: IBaseGameEntity, telegram: Telegram): boolean {
// 		return false;
// 	}

//     public enter(entity: IBaseGameEntity): void {

// 	}

//     public execute(entity: IBaseGameEntity): void {

// 	}

//     public exit(entity: IBaseGameEntity): void {

// 	}

// }
/**
 * 寻找
 */
class ShellMovingEntityStateSeek implements IState {
	private static _instance: ShellMovingEntityStateSeek;
	private client: ClientModel;

	public constructor() {

	}

	public static get instance(): ShellMovingEntityStateSeek {
		if (this._instance == null) {
			this._instance = new ShellMovingEntityStateSeek();
		}
		return this._instance;
	}


    public onMessage(entity: IBaseGameEntity, telegram: Telegram): boolean {
		return false;
	}

    public enter(entity: IBaseGameEntity): void {
		this.client = ClientModel.instance;
		entity.isDestroy = false;
	}

    public execute(entity: IMovingEneity): void {
		entity.getDisplayObject().y += entity.speedY;
		entity.getDisplayObject().x += entity.speedX;
		var dis: egret.DisplayObject = entity.getDisplayObject();
		var change: boolean = false;
		if (dis.x < 0) {
			dis.x = 0;
			entity.speedX = -entity.speedX;
			change = true;
		} else if (dis.x > dis.stage.stageWidth) {
			dis.x = dis.stage.stageWidth;
			entity.speedX = -entity.speedX;
			change = true;
		}
		if (dis.y < 0) {
			dis.y = 0;
			entity.speedY = -entity.speedY;
			change = true;
		}
		else if (dis.y > dis.stage.stageHeight) {
			dis.y = dis.stage.stageHeight;
			entity.speedY = -entity.speedY;
			change = true;
		}
		if (change) {
			entity.rotation = Math.atan2(entity.speedY, entity.speedX) * 57;

		}
		this.client.fishList.forEach(element => {
			var dis: egret.DisplayObject = element.displayObject;
			if (dis.parent != null) {
				if (element.getFSM().CurrentState == FishStateSeek.instance) {
					if (HitTestUtils.hitTest(dis, entity.getDisplayObject())) {		//包围盒碰撞检测
						// if (dis.hitTestPoint(dis.x, dis.y, false)) {				//点碰撞检测
						entity.getFSM().ChangeState(ShellMovingEntityStateArrive.instance);
					}
				}
			}
		});
	}

    public exit(entity: IBaseGameEntity): void {

	}
}

/**
 * 抵达
 */
class ShellMovingEntityStateArrive {
	private static _instance: ShellMovingEntityStateArrive;
	private client: ClientModel;

	public constructor() {

	}

	public static get instance(): ShellMovingEntityStateArrive {
		if (this._instance == null) {
			this._instance = new ShellMovingEntityStateArrive();
		}
		return this._instance;
	}


    public onMessage(entity: IBaseGameEntity, telegram: Telegram): boolean {
		return false;
	}

    public enter(entity: IBaseGameEntity): void {
		// entity.getDisplayObject().
		//播放爆咋动画
		//
		this.client = ClientModel.instance;
		console.log(entity.sid + "");
		var dis: egret.Bitmap = <any>entity.getDisplayObject();
		dis.texture = RES.getRes("net_png");
		dis.anchorOffsetX = dis.width >> 1;
		dis.anchorOffsetY = dis.height >> 1;
		this.client.fishList.forEach(element => {
			// var dis: egret.DisplayObject = element.displayObject;
			// if (dis.hitTestPoint(dis.x, dis.y, false)) {
			// 	if (dis.parent) {
			// 		dis.parent.removeChild(dis);
			// 	}
			// }
			if (HitTestUtils.hitTest(dis, element.getDisplayObject())) {
				element.getFSM().ChangeState(FishStateDeath.instance);
			}
		});
		entity.getFSM().ChangeState(ShellMovingEntityStateDeath.instance);
	}

    public execute(entity: IBaseGameEntity): void {

	}

    public exit(entity: IBaseGameEntity): void {
		//生成网
	}
}


class ShellMovingEntityStateDeath {
	private static _instance: ShellMovingEntityStateDeath;
	private client: ClientModel;

	public constructor() {

	}

	public static get instance(): ShellMovingEntityStateDeath {
		if (this._instance == null) {
			this._instance = new ShellMovingEntityStateDeath();
		}
		return this._instance;
	}


    public onMessage(entity: IBaseGameEntity, telegram: Telegram): boolean {
		return false;
	}

    public enter(entity: IBaseGameEntity): void {
		var obj: ShellRenderer = <ShellRenderer>entity;
		egret.Tween.get(obj.displayObject).to({ alpha: 0 }, 350).call(() => {
			if (obj.displayObject.parent) {
				obj.displayObject.parent.removeChild(obj.displayObject)
				entity.isDestroy = true;
				(<PlayerGunRenderer>obj.owner).clearnShell(obj.sid);
			}
		});
	}

    public execute(entity: IBaseGameEntity): void {

	}

    public exit(entity: IBaseGameEntity): void {
		//生成网
	}
}