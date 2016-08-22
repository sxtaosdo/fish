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
		} else if (dis.x > GameWorld.GAME_WIDTH) {
			dis.x = GameWorld.GAME_WIDTH;
			entity.speedX = -entity.speedX;
			change = true;
		}
		if (dis.y < 0) {
			dis.y = 0;
			entity.speedY = -entity.speedY;
			change = true;
		}
		else if (dis.y > GameWorld.GAME_HEIGHT) {
			dis.y = GameWorld.GAME_HEIGHT;
			entity.speedY = -entity.speedY;
			change = true;
		}
		if (change) {
			entity.rotation = Math.atan2(entity.speedY, entity.speedX) * 57;

		}
		this.client.fishList.forEach(element => {
			var dis1: egret.DisplayObject = element.displayObject;
			if (dis1.parent != null) {
				if (element.getFSM().CurrentState == FishStateSeek.instance) {
					var pad1: number = 1.5 * Math.max(dis1.width, dis1.height);
					var dis2: egret.DisplayObject = entity.getDisplayObject();
					var pad2: number = 1.5 * Math.max(dis2.width, dis2.height);
					if ((dis1.x - dis2.x) > -(pad1 + pad2) && (dis1.x - dis2.x) < (pad1 + pad2) && (dis1.y - dis2.y) > -(pad1 + pad2) && (dis1.y - dis2.y) < (pad1 + pad2)) {
						if (HitTestUtils.hitTest(dis1, entity.getDisplayObject())) {		//包围盒碰撞检测
							// if (dis.hitTestPoint(dis.x, dis.y, false)) {				//点碰撞检测
							entity.getFSM().ChangeState(ShellMovingEntityStateArrive.instance);
						}
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
class ShellMovingEntityStateArrive implements IState {
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

	//爆炸动画
	//收金币动画
    public enter(entity: IBaseGameEntity): void {
		this.client = ClientModel.instance;
		var shell: ShellRenderer = <ShellRenderer>entity;
		// var dis: egret.MovieClip = <any>entity.getDisplayObject();
		/*var temp = MovieclipUtils.createMc(shell.data.bomb + "_png", shell.data.bomb + "_json");
		temp.x = dis.x;
		temp.y = dis.y + shell.data.offy;
		dis.parent.addChild(temp);
		dis.parent.removeChild(dis);
		shell.displayObject = temp;
		temp.gotoAndPlay(1, 1);
		shell.displayObject.anchorOffsetX = shell.displayObject.width >> 1;*/
		// shell.displayObject.anchorOffsetY = shell.displayObject.height >> 1;

		(<egret.MovieClip>shell.displayObject).movieClipData = shell.mcf.generateMovieClipData(shell.data.bomb);
		(<egret.MovieClip>shell.displayObject).gotoAndPlay(1, 1);
		this.client.fishList.forEach(element => {
			if (element.isDestroy == false) {
				var dis1: egret.DisplayObject = shell.displayObject;
				var dis2: egret.DisplayObject = element.getDisplayObject();
				var pad1: number = 1.5 * Math.max(dis1.width, dis1.height);
				var pad2: number = 1.5 * Math.max(dis2.width, dis2.height);
				if ((dis1.x - dis2.x) > -(pad1 + pad2) && (dis1.x - dis2.x) < (pad1 + pad2) && (dis1.y - dis2.y) > -(pad1 + pad2) && (dis1.y - dis2.y) < (pad1 + pad2)) {
					if (HitTestUtils.hitTest(shell.displayObject, element.getDisplayObject())) {
						element.getFSM().ChangeState(FishStateDeath.instance);
						(<PlayerGunRenderer>shell.owner).killFish(element.getDataVo<FishVo>(FishVo))
					}
				}
			}
		});
		entity.getFSM().ChangeState(ShellMovingEntityStateDeath.instance);
	}

    public execute(entity: IBaseGameEntity): void {

	}

    public exit(entity: IBaseGameEntity): void {
	}
}


class ShellMovingEntityStateDeath implements IState {
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
				HitGoldAnimation.instance.enter({ target: obj.owner, money: 99, x: obj.displayObject.x, y: obj.displayObject.y });
			} else {
				console.error("obj.displayObject.parent" + obj.displayObject.parent);
			}
		});
	}

    public execute(entity: IBaseGameEntity): void {

	}

    public exit(entity: IBaseGameEntity): void {
	}
}