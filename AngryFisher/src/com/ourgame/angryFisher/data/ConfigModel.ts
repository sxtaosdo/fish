/**
 * @author sxt
 */
class ConfigModel {
    private static _instance: ConfigModel;
    /**路径文件名称 */
    private static pathNameList: Array<string> = ["A_star1[12]_track", "A_star2[12]_track", "A_tai[2]_track", "A_w[2]_track", "A_w[8]_track", "A_wave1[8]_track", "A_wave2[6]_track", "A_wave3[6]_track", "A_wave4[6]_track", "A_well[8]_track", "A_wire[2]_track", "A_x[4]_track", "B99lb[5]_track", "B99lb_r[3]_track", "BombFish_track", "C04[6]_track", "Golden_Shark_track", "shark_track", "xiao1_track", "-4[13]_track", "A_a[24]_track"];

    /**路径列表 */
    private _pathList: Array<any> = new Array<any>();
    private _roomList: Array<RoomInfoVo> = new Array<RoomInfoVo>();

    private _version: string = "";
    private _debug: boolean = false;
    private _isShowLogin: boolean = false;
    private _showTest: boolean = false;
    private _showPathPoint: boolean = false;

    private _fishList: Array<FishVo>;
    private _deabedList: Array<DeabedVo>;
    private _createList: Array<FishCreateVo>;
    private _shellList: Array<ShellVo>;
    private _diceMapGrid: DiceVo;


    public constructor() {
        this._fishList = new Array<FishVo>();
        this._deabedList = new Array<DeabedVo>();
        this._createList = new Array<FishCreateVo>();
        this._shellList = new Array<ShellVo>();
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
        this._showPathPoint = data.showPathPoint;
        console.log("配置文件:" + this._version);
        if (data.debug) {
            this._debug = data.debug == "true" ? true : false;
            if (this._debug) {
                this._isShowLogin = true;
            }
            console.log("debug模式:" + this._debug);
        }
        GameDispatcher.send(GameEvent.CONFIG_INIT_COMPLETE_EVENT);
    }

    public parseFish(data: any): void {
        var key: any;
        var index: number = 0;
        for (key in data.config) {
            var fish: FishVo = new FishVo();
            fish.analysis(data.config[key]);
            fish.index = index;
            this._fishList[fish.id] = fish;
            index++;
        }
    }

    public parseCreate(data: any): void {
        var key: any;
        for (key in data.create) {
            var create: FishCreateVo = new FishCreateVo();
            create.analysis(data.create[key]);
            this._createList.push(create);
        }
    }

    public parseFishPath(): void {
        ConfigModel.pathNameList.forEach(element => {
            var data: egret.ByteArray = new egret.ByteArray(RES.getRes(element));
            data.endian = egret.Endian.LITTLE_ENDIAN;

            var data1 = data.readUnsignedInt();         //32整数文件头   1667330676
            var version = data.readUnsignedInt();       //32位整数版本号  105
            var pathNum = data.readUnsignedInt();       //32整数路径数量  12
            var tempList0: Array<any> = new Array<any>();
            for (var index = 0; index < pathNum; index++) {
                var len = data.readUnsignedInt();       //32大小  10
                var templist: Array<PathPointVo> = new Array<PathPointVo>();
                for (var i: number = 0; i < len; i++) {
                    var pp: PathPointVo = new PathPointVo();
                    pp.x = data.readFloat() * GameWorld.GAME_WIDTH;
                    pp.y = data.readFloat() * GameWorld.GAME_HEIGHT;
                    pp.speed = 6;
                    templist.push(pp);//32小数，32小数
                }
                /*****************************计算客户端需要的路径点*贝塞尔曲线*************************/
                var temp: Array<PathPointVo> = [];
                var temp1: Array<PathPointVo>;
                if (templist.length <= 3) {
                    temp = templist;
                    return;
                }

                for (var i = 0; i < templist.length - 1; i++) {
                    //首点
                    if (i == 0) {
                        temp.push(templist[0]);
                        var vo1: PathPointVo = new PathPointVo();
                        vo1.x = templist[0].x + (templist[0].x - templist[1].x) / 100;
                        vo1.y = templist[0].y + (templist[0].y - templist[1].y) / 100;
                        temp1 = FishPathUtil.createPath(1, vo1, templist[0], templist[1], templist[2])
                        temp = temp.concat(temp1);
                    }
                    //尾点
                    else if (i == templist.length - 2) {
                        var vo2: PathPointVo = new PathPointVo();
                        vo2.x = templist[i + 1].x + (templist[i + 1].x - templist[i].x) / 100;
                        vo2.y = templist[i + 1].y + (templist[i + 1].y - templist[i].y) / 100;
                        temp1 = FishPathUtil.createPath(temp.length, templist[i - 1], templist[i], templist[i + 1], templist[i + 1]);
                        temp = temp.concat(temp1);
                        break;
                    }
                    else {
                        temp1 = FishPathUtil.createPath(temp.length, templist[i - 1], templist[i], templist[i + 1], templist[i + 2]);
                        temp = temp.concat(temp1);
                    }
                }
                /*************************计算详细路径点取代原线**************************************/
                //计算客户端需要的路径点
                var lastPoint: PathPointVo = temp[0];
                var stepList: Array<PathPointVo> = [];
                for (var i: number = 0; i < temp.length; i++) {
                    var next: PathPointVo = temp[i + 1];
                    if (next != null) {
                        var disX: number = next.x - lastPoint.x;
                        var disY: number = next.y - lastPoint.y;
                        var distance: number = Math.sqrt(disX * disX + disY * disY);
                        var speedX: number = lastPoint.speed * disX / distance;
                        var speedY: number = lastPoint.speed * disY / distance;
                        var advanceTime: number = Math.floor(distance / lastPoint.speed);
                        var rotation: number = Math.atan2(disY, disX) * 57 + 0;
                        if (i == 0) {
                            lastPoint.rotation = rotation;
                            stepList.push(lastPoint);
                        }

                        //起始点为上次计算的终点，不计入
                        for (var j: number = 1; j < advanceTime; j++) {
                            var pp: PathPointVo = new PathPointVo();
                            pp.x = lastPoint.x + j * speedX;
                            pp.y = lastPoint.y + j * speedY;
                            pp.rotation = rotation;
                            pp.speed = lastPoint.speed;
                            stepList.push(pp);
                            if (j == advanceTime - 1) {
                                lastPoint = pp;
                            }
                        }
                    }
                }
                tempList0.push(stepList);
                // tempList0.push(templist);
                /**************************************************************************/
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
            this._pathList.push(tempList0);
        });
    }

    public parseRoomList(data: any): void {
        var key: any;
        for (key in data.room) {
            var vo: RoomInfoVo = new RoomInfoVo();
            vo.analysis(data.room[key]);
            this._roomList.push(vo);
        }
    }

    public parseDeabed(data: any): void {
        var key: any;
        for (key in data.deabed) {
            var vo: DeabedVo = new DeabedVo();
            vo.analysis(data.deabed[key]);
            this._deabedList.push(vo);
        }
    }

    public parseGridList(data: any, callback: Function, thisObj: any): void {
        this._diceMapGrid = new DiceVo();
        this._diceMapGrid.analysis(data.Grids);
        callback.apply(thisObj)
    }

    public parseShell(data: any): void {
        var key: any;
        for (key in data) {
            var vo: ShellVo = new ShellVo();
            vo.analysis(data[key]);
            this._shellList.push(vo);
        }
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

    public get pathList(): Array<any> {
        return this._pathList;
    }

    public get showPathPoint(): boolean {
        return this._showPathPoint
    }

    public get roomList(): Array<RoomInfoVo> {
        return this._roomList;
    }

    public get deabedList(): Array<DeabedVo> {
        return this._deabedList;
    }

    public get createList(): Array<FishCreateVo> {
        return this._createList;
    }

    public get diceMapGrid(): DiceVo {
        return this._diceMapGrid;
    }

    public get shellList(): Array<ShellVo> {
        return this._shellList;
    }

}
