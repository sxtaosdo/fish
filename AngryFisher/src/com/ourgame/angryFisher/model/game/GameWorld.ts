class GameWorld extends egret.Sprite implements IBase {

    private static that: GameWorld;
    private client: ClientModel;

    public constructor() {
        super();
        GameWorld.that = this;
        this.client = ClientModel.instance;
        this.client.fishList = new Array<FishRenderer>();
        this.client.playerList = new Array<PlayerGunRenderer>();
        TimerManager.instance.doLoop(500, this.test, this);
    }

    private test(): void {
        if (this.client.fishList.length > 50) {
            TimerManager.instance.clearTimer(this.test);
        }
        this.addFish();
    }

    public enter(data?: any): void {
        var player: PlayerGunRenderer = new PlayerGunRenderer();
        this.addChild(player);
        player.enter();
        // if (this.client.playerList.indexOf(player) > -1) {
        this.client.playerList.push(player);
        TimerManager.instance.doFrameLoop(1, this.onEnterFrame, this);
        GameDispatcher.addEventListener(TestEvent.ADD_FISH_EVENT, this.addFish, this);
        // }
    }

    public exit(data?: any): void {

    }

    public execute(): void {

    }

    private addFish(): void {
        var fish: FishRenderer = EntityManager.instance.getAvailableEntity<FishRenderer>(FishRenderer);
        fish.entityType = EntityType.FISH;
        fish.setData(ConfigModel.instance.fishList[RandomUtil.randInt(0, 5)]);
        GameWorld.that.addChild(fish.getDisplayObject());
        fish.getFSM().ChangeState(FishStateSeek.instance);
        GameWorld.that.client.fishList[fish.sid] = fish;
    }

    private onEnterFrame(evt?: egret.Event): void {
        this.client.fishList.forEach(element => {
            element.getFSM().Update();
        });

        this.client.playerList.forEach(element => {
            element.execute();
        });
    }
}