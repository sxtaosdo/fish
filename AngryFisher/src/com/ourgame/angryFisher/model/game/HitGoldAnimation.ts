/**
 * 击中鱼后的金币动画
 */
class HitGoldAnimation implements IBase {
	private static _instance: HitGoldAnimation;
	private goldList: Array<egret.MovieClip>;

	public constructor() {
		this.goldList = new Array<egret.MovieClip>();
	}

	public static get instance(): HitGoldAnimation {
		if (this._instance == null) {
			this._instance = new HitGoldAnimation();
		}
		return this._instance;
	}

	public enter(data?: any): void {
		var owner: PlayerGunRenderer = data.target;
		var money: number = data.money;
		for (var index = 1; index < 7; index++) {
			var mc: egret.MovieClip = MovieclipUtils.createMc("hitAwardGold_png", "hitAwardGold_json");
			// mc.x = data.x - 60 + 50 * parseInt((index % 3) + "");
			// mc.y = data.y - 60 + 50 * parseInt(((index - 1) / 3) + "");
			mc.x = data.x;
			mc.y = data.y;
			mc.gotoAndPlay(1, -1);
			owner.parent.addChild(mc);
			// egret.Tween.get(mc).to({ y: mc.y - 30 }, 100).wait(400 + (index * 50)).to({ x: owner.x, y: owner.y }, 200).call((mcc) => {
			egret.Tween.get(mc).to({ y: data.y - 60 + 50 * parseInt(((index - 1) / 3) + ""), x: data.x - 60 + 50 * parseInt((index % 3) + "") }, 150).wait(400 + (index * 50)).to({ x: owner.x + 190, y: owner.y + 65 }, 200).call((mcc) => {
				mcc.stop();
				if (mcc.parent) {
					mcc.parent.removeChild(mcc);
				} else {
					console.error("parent is null");
				}
			}, this, [mc]);
		}
	}

	public exit(): void {

	}

	public execute(data?: any): void {

	}
}