class DeabedPanel extends egret.Sprite implements IBase {

	private static bgNameList: Array<string> = ["bg2_png", "bg3_png", "bg4_png", "bg6_png", "bg7_png", "bg8_png", "BattleBackground1_png", "bg_png", "bg1_png"];
    private bg: egret.Bitmap;
	private plantList: Array<egret.MovieClip>;

	public constructor() {
		super();
		this.bg = new egret.Bitmap();
		this.touchChildren = this.touchEnabled = false;
		this.plantList = new Array<egret.MovieClip>();
	}

	public enter(data?: any): void {
		this.addChild(this.bg);
		this.plantList.push();
	}

	public exit(): void {

	}

	public execute(data?: any): void {
		if (data) {
			this.bg.texture = RES.getRes(DeabedPanel.bgNameList[RandomUtil.randInt(0, DeabedPanel.bgNameList.length - 1)]);
			this.bg.visible = true;
		} else {
			if (this.bg) {
				this.bg.visible = false;
			}
		}
	}
}