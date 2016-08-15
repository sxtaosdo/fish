class GameWorld extends egret.Sprite implements IBase {

    public static GAME_WIDTH: number = 730;
    public static GAME_HEIGHT: number = 530;

    private static that: GameWorld;
    private client: ClientModel;
    private bg: DeabedPanel;
    private createList: Array<FishCreateVo>;
    private jpBar: JpBarPanel;
    private right: PlayerList;
    private contentSp: egret.Sprite;

    public constructor() {
        super();
        GameWorld.that = this;
        this.client = ClientModel.instance;
        this.client.fishList = new Array<FishRenderer>();
        this.createList = new Array<FishCreateVo>();
        this.client.playerList = new Array<PlayerGunRenderer>();
        this.bg = new DeabedPanel();
        this.y = 40;

        this.jpBar = new JpBarPanel();
        this.jpBar.x = 200;
        this.jpBar.y = 70;
        this.addChild(this.jpBar);

        this.right = new PlayerList();
        this.right.x = Main.STAGE_WIDTH - this.right.width;
        this.addChild(this.right);

        this.contentSp = new egret.Sprite();
        this.contentSp.touchChildren = this.contentSp.touchEnabled = false;
        this.addChildAt(this.contentSp, 0);
    }

    private test(): void {
        var obj: Object = {};
        while (this.createList.length < 3) {
            var key = RandomUtil.randInt(0, ConfigModel.instance.createList.length - 1);
            if (obj[key]) {
                continue;
            } else {
                obj[key] = true;
            }
            var vo: FishCreateVo = ConfigModel.instance.createList[key]
            // console.log(vo.fishType);
            this.createList.push(vo);
            this.drawPathPoint(ConfigModel.instance.pathList[vo.pathID]);
        }
    }

    private addFish(id: number, path: Array<any>): void {
        var fish: FishRenderer = EntityManager.instance.getAvailableEntity<FishRenderer>(FishRenderer);
        fish.entityType = EntityType.FISH;
        var vo: FishVo = ConfigModel.instance.fishList[id];
        try {
            vo.path = path[RandomUtil.randInt(0, path.length - 1)];
            fish.setData(vo);
            GameWorld.that.contentSp.addChild(fish.getDisplayObject());
            fish.getFSM().ChangeState(FishStateSeek.instance);
            GameWorld.that.client.fishList[fish.sid] = fish;
        } catch (e) {
            console.error(e);
        }
    }

    public enter(data?: any): void {
        var player: PlayerGunRenderer = new PlayerGunRenderer(this.contentSp);
        this.addChild(player);
        player.enter();
        this.client.playerList.push(player);
        this.addChildAt(this.bg, 0);
        this.bg.enter();
        this.jpBar.enter();

        TimerManager.instance.doOnce(1000, this.test, this);
        TimerManager.instance.doFrameLoop(1, this.execute, this);
        GameDispatcher.addEventListener(TestEvent.ADD_FISH_EVENT, this.addFish, this);
        GameDispatcher.addEventListener(TestEvent.CHANGE_PATH, this.changePath, this);
        GameDispatcher.addEventListener(TestEvent.CHANGE_MAP, this.changeMap, this);
        GameDispatcher.addEventListener(BaseEvent.LEVEL_UP_EVENT, this.onLevelUp, this);
    }

    public exit(data?: any): void {
        if (this.parent != null) {
            this.parent.removeChild(this);
        }
        this.bg.exit();
        this.jpBar.exit();
        TimerManager.instance.clearTimer(this.test);
        TimerManager.instance.clearTimer(this.execute);
        GameDispatcher.removeEventListener(TestEvent.ADD_FISH_EVENT, this.addFish, this);
        GameDispatcher.removeEventListener(TestEvent.CHANGE_PATH, this.changePath, this);
        GameDispatcher.removeEventListener(TestEvent.CHANGE_MAP, this.changeMap, this);
    }

    public execute(): void {
        this.createList.forEach(element => {

            if (element.currentCount < element.fishCount) {
                if (egret.getTimer() - element.createTime > element.interval) {
                    element.createTime = egret.getTimer();
                    element.currentCount++;
                    this.addFish(element.fishType, ConfigModel.instance.pathList[element.pathID]);
                }
            } else {
                element.currentCount = 0;
                delete this.createList[this.createList.indexOf(element)];//数量够了,删除
            }
        });

        this.client.fishList.forEach(element => {
            if (element.isDestroy == false) {
                element.getFSM().Update();
                // if(ConfigModel.instance.showTest){

                // }
            }
        });

        this.client.playerList.forEach(element => {
            element.execute();
        });
    }

    private changePath(): void {
        this.graphics.clear();
        this.createList = [];
        this.test();
    }

    private drawPathPoint(path: any): void {
        if (ConfigModel.instance.showPathPoint) {
            if (this.bg) {   //显示路径点则不显示背景
                this.bg.execute(false);
            }

            var color: number = 0x000000;
            // console.log(this.currentPath.length);
            path.forEach(element => {
                var index: number = 0;
                element.forEach(element => {
                    // color += 9;
                    this.graphics.beginFill(color, 0.8);
                    this.graphics.drawCircle(element.x, element.y, 2);
                    this.graphics.endFill();
                    index++;
                });
                color += 0x88;
            });
        }
    }

    private changeMap(): void {
        this.bg.execute(true);
    }
    private onLevelUp(): void {
        ClientModel.instance.openWindow(LevelUpPanel);
    }

}