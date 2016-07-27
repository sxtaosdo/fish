class GameWorld extends egret.Sprite implements IBase {


    private static that: GameWorld;
    private client: ClientModel;
    private currentPath: any;
    private bg: DeabedPanel;

    public constructor() {
        super();
        GameWorld.that = this;
        this.client = ClientModel.instance;
        this.client.fishList = new Array<FishRenderer>();
        this.client.playerList = new Array<PlayerGunRenderer>();
        this.bg = new DeabedPanel();
    }

    private test(): void {
        if (this.client.fishList.length > 50) {
            TimerManager.instance.clearTimer(this.test);
        }
        this.addFish();
    }

    public enter(data?: any): void {
        this.addChild(this.bg);
        this.bg.enter();
        var player: PlayerGunRenderer = new PlayerGunRenderer();
        this.addChild(player);
        player.enter();
        this.client.playerList.push(player);

        this.changePath();
        TimerManager.instance.doLoop(500, this.test, this);
        TimerManager.instance.doFrameLoop(1, this.onEnterFrame, this);
        GameDispatcher.addEventListener(TestEvent.ADD_FISH_EVENT, this.addFish, this);
        GameDispatcher.addEventListener(TestEvent.CHANGE_PATH, this.changePath, this);
    }

    public exit(data?: any): void {
        if (this.parent != null) {
            this.parent.removeChild(this);
        }
        TimerManager.instance.clearTimer(this.test);
        TimerManager.instance.clearTimer(this.onEnterFrame);
        GameDispatcher.removeEventListener(TestEvent.ADD_FISH_EVENT, this.addFish, this);
        GameDispatcher.removeEventListener(TestEvent.CHANGE_PATH, this.changePath, this);
    }

    public execute(): void {

    }

    private addFish(): void {
        var fish: FishRenderer = EntityManager.instance.getAvailableEntity<FishRenderer>(FishRenderer);
        fish.entityType = EntityType.FISH;
        var vo: FishVo = ConfigModel.instance.fishList[RandomUtil.randInt(0, 16)];
        var index2: number = RandomUtil.randInt(0, this.currentPath["length"] - 1);
        vo.path = this.currentPath[index2];
        fish.setData(vo);
        GameWorld.that.addChild(fish.getDisplayObject());
        fish.getFSM().ChangeState(FishStateSeek.instance);
        GameWorld.that.client.fishList[fish.sid] = fish;
    }

    private changePath(): void {
        var index: number = RandomUtil.randInt(0, ConfigModel.instance.pathList.length - 1);
        this.currentPath = ConfigModel.instance.pathList[index];
        // this.bg.texture = RES.getRes(GameWorld.bgNameList[RandomUtil.randInt(0, GameWorld.bgNameList.length - 1)]);
        // this.addChildAt(this.bg, 0);
        this.drawPathPoint();
    }

    private drawPathPoint(): void {
        if (ConfigModel.instance.showPathPoint) {
            if (this.bg) {   //显示路径点则不显示背景
                this.bg.execute(null);
            }
            this.graphics.clear();
            var color: number = 0x000000;
            console.log(this.currentPath.length);
            this.currentPath.forEach(element => {
                var index: number = 0;
                element.forEach(element => {
                    // color += 9;
                    this.graphics.beginFill(color, 0.8);
                    this.graphics.drawCircle(element.x, element.y, 5);

                    // this.graphics.lineStyle(1, color);
                    // this.graphics.lineTo(element.x, element.y)
                    // this.graphics.moveTo(element.x, element.y);
                    this.graphics.endFill();
                    index++;
                });
                color += 0x88;
            });
        }
    }

    private onEnterFrame(evt?: egret.Event): void {
        this.client.fishList.forEach(element => {
            if (element.isDestroy == false) {
                element.getFSM().Update();
            }
        });

        this.client.playerList.forEach(element => {
            element.execute();
        });
    }
}