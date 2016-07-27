/**
 * 程序主界面
 * 游戏界面
 * 大厅界面
 * 其他界面
 * 弹出框管理
 * top条
 */
class GameMain extends egret.Sprite implements IBase {

	private currentState: IBase;
	private previousState: IBase;
	private topBar: TopView;

	public constructor() {
		super();

		this.topBar = new TopView();

		this.addEventListener(egret.Event.ADDED_TO_STAGE, this.enter, this);

		this.addChild(BitMapUtil.createBitmapByName("bg_png"));
	}


	public enter(data?: any): void {
		GameDispatcher.addEventListener(BaseEvent.GAME_STATE_EVENT, this.onStateChange, this);
		this.setDefoult();
	}

	/**
	 * 进入游戏后默认的设置
	 */
	private setDefoult(): void {
		ClientModel.instance.changeGameState(new HallView());
		this.addChild(this.topBar);
		this.topBar.enter();
	}

	public exit(): void {

	}

	public execute(data?: any): void {

	}

	private onStateChange(evt: any): void {
		var newState: IBase = ClientModel.instance.gameState;

		this.previousState = this.currentState;
		if (this.previousState != null) {
			this.previousState.exit();
		}
		this.currentState = newState;
		this.currentState.enter();

		this.addChildAt(<any>this.currentState, 0);
		this.topBar.execute(newState);
	}

}