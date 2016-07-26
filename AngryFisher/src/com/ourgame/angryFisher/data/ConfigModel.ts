/**
 * @author sxt
 */
class ConfigModel {
    private static _instance: ConfigModel;
    /**路径文件名称 */
    private static pathNameList: Array<string> = ["A_star1[12]_track", "A_star2[12]_track"];

    /**路径列表 */
    private _pathList: Array<Object> = new Array<Object>();

    private _version: string = "";
    private _debug: boolean = false;
    private _isShowLogin: boolean = false;
    private _showTest: boolean = false;

    private _fishList: Array<FishVo>;


    public constructor() {
        this._fishList = new Array<FishVo>();
    }

    public static get instance(): ConfigModel {
        if (this._instance == null) {
            this._instance = new ConfigModel();
        }
        return this._instance;
    }

    public parse(data: any): void {
        var value: any;
        this._version = data.version;
        this._showTest = data.showTest;
        console.log("配置文件:" + this._version);
        if (data.debug) {
            this._debug = data.debug == "true" ? true : false;
            if (this._debug) {
                this._isShowLogin = true;
            }
            console.log("debug模式:" + this._debug);
        }
        GameDispatcher.send(BaseEvent.CONFIG_INIT_COMPLETE_EVENT);
    }

    public parseFish(data: any): void {
        var key: any;
        var index: number = 0;
        for (key in data.config) {
            var fish: FishVo = new FishVo();
            fish.analysis(data.config[key]);
            fish.index = index;
            this._fishList[fish.index] = fish;
            index++;
        }
    }

    public parseFishPath(): void {
        ConfigModel.pathNameList.forEach(element => {
            console.log("");
            // var data: ArrayBuffer = RES.getRes(element);
            var data: egret.ByteArray = new egret.ByteArray(RES.getRes(element));
            data.endian = egret.Endian.LITTLE_ENDIAN;

            var data1 = data.readUnsignedInt();         //32整数文件头   1667330676
            var version = data.readUnsignedInt();       //32位整数版本号  105
            var pathNum = data.readUnsignedInt();       //32整数路径数量  12
            for (var index = 0; index < pathNum; index++) {
                var len = data.readUnsignedInt();       //32大小  10
                var templist: Array<PathPoint> = new Array<PathPoint>();
                for (var i: number = 0; i < len; i++) {
                    var pp: PathPoint = new PathPoint();
                    pp.x = data.readFloat() * Main.GAME_WIDTH;
                    pp.y = data.readFloat() * Main.GAME_HEIGHT;
                    pp.speed = 5;
                    templist.push(pp);//32小数，32小数
                }
                this._pathList.push(templist);
                // continue;
                var data2 = data.readFloat();       //32小数
                var len2 = data.readUnsignedInt();  //32大小
                var tempList: Array<Object> = new Array<Object>();
                for (var j = 0; j < len2; j++) {
                    tempList.push({ x: data.readUnsignedInt(), y: data.readUnsignedInt() }) //32小数，32小数
                }


                var len3 = data.readUnsignedInt();              //32大小
                var tempList2: Array<Object> = new Array<Object>();
                for (var k = 0; k < len3; k++) {
                    tempList2.push(data.readUTF());
                }
            }
        });
        console.log(this._pathList);
    }

    public get version(): string {
        return this._version;
    }

    public get debug(): boolean {
        return this._debug;
    }

    public get isShowLogin(): boolean {
        return this._isShowLogin;
    }

    public get showTest(): boolean {
        return this._showTest;
    }

    public get fishList(): Array<FishVo> {
        return this._fishList;
    }

    public get pathList(): Array<Object> {
        return this._pathList;
    }

}
