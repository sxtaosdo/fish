var Test = (function (_super) {
    __extends(Test, _super);
    function Test() {
        _super.call(this);
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
    var d = __define,c=Test,p=c.prototype;
    p.onFrame = function () {
        console.log();
        if (this.bmp) {
        }
        else {
            this.bmp = new egret.Bitmap();
            this.bmp.y = 400;
            this.addChild(this.bmp);
        }
        this.bmp.rotation = this.fish.rotation;
        this.bmp.texture = this.fish.$bitmapData;
    };
    p.onTap = function (evt) {
        console.log(evt.target);
        var target = evt.target;
        console.log(target.$bitmapData.getPixel32(evt.localX, evt.localY));
    };
    return Test;
}(egret.Sprite));
egret.registerClass(Test,'Test');
//# sourceMappingURL=Test.js.map