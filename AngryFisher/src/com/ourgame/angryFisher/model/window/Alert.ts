/**
 * 飘字提示
 * @author sxt
 */
class Alert extends BaseComponent implements IWindow {
    
    public static SHOW_TIME: number = 2500;
    private context: egret.TextField;
    private bg: egret.Sprite;
    private imageBg: egret.Bitmap;
    private contentSp: egret.Sprite;
    private isShow: boolean = false;

    public constructor() {
        super(false);
        this.init();
    }


    public enter(data?: any): void {
        // console.log("1 alert剩余数量：" + WindowManager.instance.alertDataList.length);
        if (this.isShow == false) {
            this.isShow = true;
            var info: Object = WindowManager.instance.alertDataList.shift();
            console.warn("Alert的enter方法，info：" + info)
            if (info != null) {
                this.contentSp.alpha = 0;
                this.alpha = 1;
                this.context.text = info["text"];
                this.context.size = 26;
                this.context.textColor = 0xffffff;
                this.context.y = (Main.GAME_HEIGHT - this.context.textHeight) >> 1;
                this.imageBg.y = this.context.y - 1;
                egret.Tween.removeTweens(this.contentSp);
                egret.Tween.get(this.contentSp).to({ alpha: 1 }, 100);
                egret.Tween.removeTweens(this);
                egret.Tween.get(this).wait(Alert.SHOW_TIME - 300).to({ alpha: 0 }, 150).wait(0).call(this.onShowComplete, this);
            } else {
                this.isShow = false;
                ClientModel.instance.openWindow(null);
            }
        }
    }

    public execute(data?: any): void {

    }

    private onShowComplete(): void {
        this.isShow = false;
        if (WindowManager.instance.alertDataList.length > 0) {
            this.enter();
        } else {
            ClientModel.instance.openWindow(null);
        }
    }

    public exit(data?: any): void {
        this.context.text = "";
        TimerManager.instance.clearTimer(ClientModel.instance.openWindow);
    }

    public destroy(): void {
        this.exit();
    }

    public init(): void {
        this.contentSp = new egret.Sprite();
        this.addChild(this.contentSp);

        this.imageBg = BitMapUtil.createBitmapByName("alert_bg_png");
        this.contentSp.addChild(this.imageBg);

        this.context = new egret.TextField();
        this.context.textColor = 0x000000;
        this.context.width = 290;
        this.context.height = Main.GAME_HEIGHT;
        this.context.textAlign = egret.HorizontalAlign.CENTER;
        this.contentSp.addChild(this.context);

        this.bg = new egret.Sprite();
        this.bg.graphics.beginFill(0xffffff, 0);
        this.bg.graphics.drawRect(0, 0, Main.GAME_WIDTH, Main.GAME_HEIGHT);
        this.bg.graphics.endFill();
        this.addChildAt(this.bg, 0);
    }
}
