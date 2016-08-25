class Test extends egret.Sprite {

	private fish: egret.MovieClip;
	private bmp: egret.Bitmap;
	private point: egret.Sprite;

	public constructor() {
		super();

		this.touchChildren = true;
		this.touchEnabled = false;

		this.fish = MovieclipUtils.createMc("fish13_png", "fish13_json");
		this.fish.gotoAndPlay(1, -1);
		this.fish.touchEnabled = true;
		this.fish.x = 200;
		this.fish.y = 150;
		this.fish.anchorOffsetX = this.fish.width >> 1;
		this.fish.anchorOffsetY = this.fish.height >> 1;
		this.addChild(this.fish);
		this.addEventListener(egret.Event.ENTER_FRAME, this.onFrame, this);
		egret.Tween.get(this.fish).to({ rotation: 720 }, 1000);


		this.point = new egret.Sprite();


		this.addEventListener(egret.TouchEvent.TOUCH_TAP, this.onTap, this);
	}

	private onFrame(): void {
		console.log();

		if (this.bmp) {
			// this.bmp.texture.dispose();
		} else {
			this.bmp = new egret.Bitmap();
			this.bmp.y = 400;
			this.addChild(this.bmp);
		}
		this.bmp.rotation = this.fish.rotation;
		this.bmp.texture = this.fish.$bitmapData;
	}

	private onTap(evt: egret.TouchEvent): void {
		console.log(evt.target);
		var target:egret.MovieClip=evt.target;
		console.log(target.$bitmapData.getPixel32(evt.localX,evt.localY));
	}

}