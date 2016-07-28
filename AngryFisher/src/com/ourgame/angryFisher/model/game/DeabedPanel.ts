class DeabedPanel extends egret.Sprite implements IBase {

	private static bgNameList: Array<string> = ["bg2_png", "bg3_png", "bg4_png", "bg6_png", "bg7_png", "bg8_png", "BattleBackground1_png", "bg_png", "bg1_png"];
    private bg: egret.Bitmap;
	private plantList: Array<egret.MovieClip>;
	private config: ConfigModel;

	public constructor() {
		super();
		this.bg = new egret.Bitmap();
		this.touchChildren = this.touchEnabled = false;
		this.plantList = new Array<egret.MovieClip>();
		this.config = ConfigModel.instance;
	}

	public enter(data?: any): void {
		this.addChild(this.bg);
		this.plantList.push();
	}

	public exit(): void {
		this.clreanPlant();
	}

	public execute(data?: any): void {
		if (data) {
			this.clreanPlant();
			var vo: DeabedVo = this.config.deabedList[RandomUtil.randInt(0, this.config.deabedList.length - 1)];
			vo.plant.forEach(element => {
				var mc: egret.MovieClip = MovieclipUtils.createMc("plant_" + element.id + "_png", "plant_" + element.id + "_json");
				mc.x = element.x;
				mc.y = element.y;
				this.plantList.push(mc);
				this.addChild(mc);
			});
			// this.bg.texture = RES.getRes(DeabedPanel.bgNameList[RandomUtil.randInt(0, DeabedPanel.bgNameList.length - 1)]);
			this.bg.texture = RES.getRes(vo.bg);
			this.bg.visible = true;
		} else {
			if (this.bg) {
				this.bg.visible = false;
				this.clreanPlant();
			}
		}
	}

	private clreanPlant(): void {
		// this.plantList.forEach(element => {
		// 	element.stop();
		// 	if (element.parent) {
		// 		element.parent.removeChild(element);
		// 	}
		// });
		while (this.plantList.length > 0) {
			var element: egret.MovieClip = this.plantList.pop();
			if (element.parent) {
				element.parent.removeChild(element);
			}
		}
	}
}