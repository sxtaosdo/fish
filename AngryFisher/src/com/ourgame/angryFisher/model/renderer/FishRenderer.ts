/**
 * 基本的鱼
 */
class FishRenderer extends BaseMovingEntity implements IMovingEneity {
	/**配置的路径点 */
	public pathList: Array<PathPoint>;
	/**客户端计算后的路径点 */
	public clientPathList: Array<PathPoint>;
	public pathStep: number = 0;
	public currentPath: PathPoint;
	public nextPath: PathPoint;
	private vo: FishVo;

	public constructor() {
		super();
		this.pathList = new Array<PathPoint>();
		this.clientPathList = new Array<PathPoint>();
		this.stateMachine = new StateMachine(this);
	}

    public update(): void {
		this.getFSM().Update();
	}

	public handleMessage(msg: Telegram): boolean {
		return;
	}

    public getFSM(): StateMachine {
		return this.stateMachine;
	}

	public getDisplayObject(): egret.DisplayObject {
		return this.displayObject;
	}

	public setData(vo: FishVo): void {
		if (this.vo != null) {
			if (this.vo.id != vo.id) {
				this.setMc(vo.id);
			}
		} else {
			this.setMc(vo.id);
		}
		this.vo = vo;
		this.pathList = vo.path;
		this.name = vo.name;
		this.pathStep = 0;
		this.speedX = 0;
		this.speedY = 0;
		this.clientPathList = [];
	}

	private setMc(id: number): void {
		var mc: egret.MovieClip;
        var js: any = RES.getRes("fish" + id + "_json");
        var tx: any = RES.getRes("fish" + id + "_png");
        var data: egret.MovieClipDataFactory = new egret.MovieClipDataFactory(js, tx);
        mc = new egret.MovieClip(data.generateMovieClipData());
		mc.stop();
        mc.rotation = 180;
		mc.anchorOffsetX = mc.width >> 1;
		mc.anchorOffsetY = mc.height >> 1;
        mc.play(-1);
        mc.touchEnabled = false;
		this.displayObject = mc;
	}

	public getDataVo<T>(clazz: any) {
		var vo: T;
		vo = <any>this.vo;
		return vo;
	}
}