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
			mc.x = data.x-60 + 50 * parseInt((index % 3) + "");
			mc.y = data.y-60 + 50 * parseInt(((index - 1) / 3) + "");
			mc.gotoAndPlay(1, -1);
			owner.parent.addChild(mc);
			egret.Tween.get(mc).wait(500).to({ x: owner.x, y: owner.y }, 500).call((mcc) => {
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