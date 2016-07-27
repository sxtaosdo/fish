class DeabedPanel extends egret.Sprite implements IBase {

	private static bgNameList: Array<string> = ["bg2_png", "bg3_png", "bg4_png", "bg6_png", "bg7_png", "bg8_png", "BattleBackground1_png", "bg_png", "bg1_png"];
    private bg: egret.Bitmap;

	public constructor() {
		super();
		this.bg = new egret.Bitmap();
		this.touchChildren = this.touchEnabled = false;
	}

	public enter(data?: any): void {
		this.addChild(this.bg);
	}

	public exit(): void {
        this.bg.texture = RES.getRes(DeabedPanel.bgNameList[RandomUtil.randInt(0, GameWorld.bgNameList.length - 1)]);

	}

	public execute(data?: any): void {
		if (data != null) {

		} else {

		}
	}
}