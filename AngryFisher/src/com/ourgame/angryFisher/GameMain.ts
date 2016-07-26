/**
 * 程序主界面
 * 游戏界面
 * 大厅界面
 * 其他界面
 * 弹出框管理
 */
class GameMain extends egret.Sprite implements IBase {

	private currentState: IBase;
	private previousState: IBase;

	public constructor() {
		super();

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
		ClientModel.instance.setGameState(new GameWorld());//目前默认进入游戏界面
	}

	public exit(): void {

	}

	public execute(data?: any): void {

	}

	private onStateChange(evt: any): void {
		var newState: IBase = ClientModel.instance.gameState
		if (this.previousState == null) {
			this.previousState = newState;
			this.previousState.enter();
			this.addChild(<any>this.previousState);
		} else {
			if (newState != null) {
				this.previousState = this.currentState;
				this.currentState.exit();
				this.currentState = newState;
				this.currentState.enter();
			} else {
				console.error("newState is :" + newState);
			}
			this.addChild(<any>this.currentState);
		}
	}

}