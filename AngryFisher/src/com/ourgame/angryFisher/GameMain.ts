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
	private popup: WindowManager;

	public constructor() {
		super();

		this.popup = WindowManager.instance;

		this.addEventListener(egret.Event.ADDED_TO_STAGE, this.enter, this);
		GameDispatcher.addEventListener(BaseEvent.ASSETS_COMPLETE_EVENT, this.onAssetsComplete, this);
		GameDispatcher.addEventListener(BaseEvent.WINDOW_EVENT, this.onWindow, this);
	}

	public enter(data?: any): void {
		GameDispatcher.addEventListener(BaseEvent.GAME_STATE_EVENT, this.onStateChange, this);
		this.setDefoult();
	}

	private onAssetsComplete(): void {
		if (this.topBar == null) {
			this.topBar = new TopView();
		}
		this.addChild(this.topBar);
		this.topBar.enter();
	}

	/**
	 * 打开窗口
	 */
	private onWindow(): void {
		if (ClientModel.instance.window == null) {
            if (this.contains(this.popup)) {
                this.removeChild(this.popup);
                this.popup.exit();
            }
        } else {
            this.addChild(this.popup);
            this.popup.enter();
        }
	}

	/**
	 * 进入游戏后默认的设置
	 */
	private setDefoult(): void {
		ClientModel.instance.changeGameState(new LoginView());
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
		if (this.topBar) {
			this.topBar.execute(newState);
		}
	}

}