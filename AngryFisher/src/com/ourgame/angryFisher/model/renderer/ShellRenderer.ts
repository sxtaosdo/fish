/**
 * 炮弹
 * 
 * 
 * 
 */
class ShellRenderer extends BaseMovingEntity implements IMovingEneity {

	public data: ShellVo;
	public mcf: egret.MovieClipDataFactory;//切换纹理用

	public constructor() {
		super();
		this.stateMachine = new StateMachine(this);
	}

	public setData(vo: ShellVo): void {
		this.data = vo;
		if (this.displayObject) {
			if (this.displayObject.parent) {
				this.displayObject.parent.removeChild(this.displayObject);
			}
		}
		this.mcf = MovieclipUtils.getFactory(vo.shell + "_png", vo.shell + "_json");
		this.displayObject = new egret.MovieClip(this.mcf.generateMovieClipData(this.data.shell))
		this.displayObject.anchorOffsetX = this.displayObject.width >> 1;
		this.displayObject.anchorOffsetY = this.displayObject.height >> 1;
		this.entityType = EntityType.SHELL;
	}

	public update(): void {

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

	public getDataVo<T>(clazz: any) {
		return;
	}
}