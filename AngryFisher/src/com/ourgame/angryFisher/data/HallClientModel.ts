/**大厅、步步为营的数据 */
class HallClientModel {

	private static _instance: HallClientModel;

	private _goResult: number = 0;
	private _diceInfo: DiceInfo;

	public constructor() {

	}

    public static get instance(): HallClientModel {
        if (this._instance == null) {
            this._instance = new HallClientModel();
        }
        return this._instance;
    }

	public onGoResult(data: any): void {
		this._goResult = data.num;
		GameDispatcher.send(BaseEvent.DICE_GO_RESULT_EVENT);
	}

	public onDiceInfo(data: any): void {
		this._diceInfo = data;
		GameDispatcher.send(BaseEvent.DICE_INFO_EVENT);
	}

	public get goResult(): number {
		return this._goResult;
	}

	public get diceInfo(): DiceInfo {
		return this._diceInfo;
	}
}