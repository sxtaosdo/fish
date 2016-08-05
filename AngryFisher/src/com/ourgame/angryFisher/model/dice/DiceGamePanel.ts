class DiceGamePanel extends BaseComponent implements IBase {
	public static ZERO_POINT_X: number = 130;
	public static ZERO_POINT_Y: number = 160;

	public constructor() {
		super(false);
		this.skinName = "resource/game_skins/dice/DiceGameSkin.exml";
		this.x = DiceGamePanel.ZERO_POINT_X;
		this.y = DiceGamePanel.ZERO_POINT_Y;
	}

	public enter(data?: any): void {

	}

	public exit(): void {

	}

	public execute(data?: any): void {

	}
}