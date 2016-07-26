/**
 * 炮弹
 * 
 * 
 * 
 */
class ShellRenderer extends BaseMovingEntity implements IMovingEneity {
	

	public constructor() {
		super();
		this.stateMachine = new StateMachine(this);
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


}