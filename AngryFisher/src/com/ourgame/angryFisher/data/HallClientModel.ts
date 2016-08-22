/**大厅、步步为营的数据 */
class HallClientModel {

	private static _instance: HallClientModel;

	private _goResult: number = 0;
	private _diceInfo: DiceInfo;
	private _pool: number = 0;
	/**当前选中房间信息 */
	public selectRoomIndex: RoomInfoItemVo;

	public constructor() {

	}

    public static get instance(): HallClientModel {
        if (this._instance == null) {
            this._instance = new HallClientModel();
        }
        return this._instance;
    }

	public onGoResult(data: any): void {
		this._goResult = data.dice;
		GameDispatcher.send(BaseEvent.DICE_GO_RESULT_EVENT);
	}

	public onDiceInfo(data: any): void {
		this._diceInfo = data;
		GameDispatcher.send(BaseEvent.DICE_INFO_EVENT);
	}

	public onPool(value: number): void {
		this._pool = value;
		GameDispatcher.send(BaseEvent.POOL_EVENT);
	}

	public get goResult(): number {
		return this._goResult;
	}

	public get pool(): number {
		return this._pool;
	}

	public get diceInfo(): DiceInfo {
		return this._diceInfo;
	}
}