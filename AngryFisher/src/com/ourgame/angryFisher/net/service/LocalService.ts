/**
 * 本地测试
 * @author sxt
 */
class LocalHandler implements ISocket {
    private static MAX_CARDS: number = 5;
    public static that: LocalHandler;
    private message: any;
    private tempCls: any;
    private callback: Function;

    //================================
    private userMoney: number = 888999777;
    private baseAnte: number = 0;
    private batTimes: number = 0;
    private pool: number = 9589000001;
    private awardMoney: number = 0;
    private name: string = "";

    public constructor(callback?: Function) {
        LocalHandler.that = this;
        this.callback = callback;
        this.message = dcodeIO.ProtoBuf.loadProto(RES.getRes("PokerSlotsMessage_proto"));
    }

    public close(): void {

    }

    public send(type: number, body: any): void {
        var callback;
        switch (type) {
            case MsgType.REQ_LOGIN:
                callback = this.login;
                break;
            case MsgType.REQ_ANTEINFO:
                callback = this.anteInfo;
                break;
            case MsgType.REQ_CHIPIN:
                callback = this.shipIn;
                break;
            case MsgType.REQ_DUXLIVETICK:
                callback = this.liveTick;
                break;
            case MsgType.REQ_HELP:
                callback = this.help;
                break;
        }
        // try {
        callback(type, body);
        // } catch (e) {
        //     console.error("Local本地处理失败" + e);
        // }
    }

    public conn(ip: string, port: number): void {

    }

    private returnMsg(type: number, body: any): void {
        if (LocalHandler.that.callback != null) {
            var temp: egret.ByteArray = new egret.ByteArray();
            temp.buffer = body.toArrayBuffer();
            LocalHandler.that.callback(type, temp);
        }
    }

    private login(type: number, body: any): void {
        LocalHandler.that.tempCls = LocalHandler.that.message.build("ReqLogin");
        var login = LocalHandler.that.tempCls.decode(body);

        var reqCls: any = LocalHandler.that.message.build("AckLogin");
        var req = new reqCls({
            "result": 0,
            "reason": 0,
            "userMoney": LocalHandler.that.userMoney,
            "username": login.userName,
            "rolename": login.userName,
            "freeInfo": LocalHandler.that.getFreeHit()
        });
        LocalHandler.that.name = login.roleName;
        LocalHandler.that.returnMsg(MsgType.ACK_LOGIN, req);
        LocalHandler.that.jpPool();
        TimerManager.instance.doLoop(1500, LocalHandler.that.jpPool);
        // TimerManager.instance.doOnce(4000, LocalHandler.that.loseTooMuch);

    }

    private help(type: number, body: any): void {
        var reqCls: any = LocalHandler.that.message.build("AckGameHelpInfo");
        var req = new reqCls({
            "mlist": LocalHandler.that.getHelpList()
        });
        LocalHandler.that.returnMsg(MsgType.ACK_HELP, req);
    }

    private shipIn(type: number, body: any): void {
        LocalHandler.that.tempCls = LocalHandler.that.message.build("ReqChipIn");
        var chipin = LocalHandler.that.tempCls.decode(body);

        var chipinCls: any = LocalHandler.that.message.build("AckChipIn");
        var key: boolean = Math.random() > 0.5 ? true : false;
        var cards: Array<any> = [];
        if (key) {
            LocalHandler.that.userMoney += parseInt(chipin.ante);
            LocalHandler.that.awardMoney = parseInt(chipin.ante);
        } else {
            LocalHandler.that.awardMoney = 0;
            if (chipin.anteType == 0) {
                LocalHandler.that.userMoney -= parseInt(chipin.ante);
            }
        }
        cards = LocalHandler.that.getCards(key);
        if (chipin.anteType == 0) {//下注类型	0：普通 1：FreeHit
            LocalHandler.that.freeValue++;
            if (LocalHandler.that.freeValue >= LocalHandler.FREE_MAX) {
                LocalHandler.that.freeTime = LocalHandler.FREE_TIME_MAX;
            }
        } else {
            LocalHandler.that.freeTime--;
            if (LocalHandler.that.freeTime == 0) {
                LocalHandler.that.freeValue = 0;
            }
        }
        var req = new chipinCls({
            "cards": cards,
            "awardMoney": LocalHandler.that.awardMoney,
            "userMoney": LocalHandler.that.userMoney,
            "cardType": key ? 4 : 0,//[0-9 : 高牌,一对,两对,三条,顺子,同花,葫芦,四条,同花顺,皇家同花顺]
            "gameType": chipin.anteType,//1：FreeHit 
            "freeInfo": LocalHandler.that.getFreeHit()
        });
        if (chipin.anteType == 0) {
            if (Math.random() < 0.9) {
                LocalHandler.that.checkBigWin(true);
            }
        }
        LocalHandler.that.returnMsg(MsgType.ACK_CHIPIN, req);
    }

    private anteInfo(): void {
        // var clazz: any = LocalHandler.that.message.build("AckAnteInterval");
        // var dataList: Array<any> = new Array<any>();
        // for (var i: number = 0; i < 3; i++) {
        //     var dataClz: any = LocalHandler.that.message.build("AnteInfo");
        //     var vo: AnteVo = ConfigModel.instance.betConfigList[i]
        //     var data = new dataClz({
        //         "limitMin": vo.min,
        //         "linitMax": vo.max,
        //         "values": vo.level
        //     });
        //     dataList.push(data);
        // }
        // var ack = new clazz({
        //     "antelist": dataList
        // });
        // LocalHandler.that.returnMsg(MsgType.ACK_ANTEINFO, ack);
    }

    private liveTick(type: number, body: any): void {
        LocalHandler.that.tempCls = LocalHandler.that.message.build("DuxLiveTick");
        var proto = LocalHandler.that.tempCls.decode(body);
        LocalHandler.that.returnMsg(MsgType.REQ_DUXLIVETICK, proto);
    }

    private jpPool(): void {
        var betCls: any = LocalHandler.that.message.build("AckHandselPool");
        if (LocalHandler.that.pool < 99999999999) {
            LocalHandler.that.pool += Math.floor(Math.random() * 666);
            var ack = new betCls({
                "pool": LocalHandler.that.pool
            });
            LocalHandler.that.returnMsg(MsgType.ACK_JPPOOL, ack);
        } else {
            LocalHandler.that.pool = Math.floor(Math.random() * 555555555);
        }
        if (Math.random() < 0.5) {
            LocalHandler.that.checkBigWin(false);
        }
    }

    private checkBigWin(isSelf: boolean = false): void {
        var key: number = Math.random() * 1000;
        if (((key < 900) || (isSelf)) && (LocalHandler.that.pool > 555555)) {
            var is1k: boolean = Math.random() < 0.5 ? true : false;//千万大奖
            var bigwinCls: any = LocalHandler.that.message.build("AckHugeAward");
            var ack = new bigwinCls({
                "username": isSelf ? LocalHandler.that.name : "其他人" + parseInt((Math.random() * 100) + StringUtils.randomChinese()),
                "awardMoney": is1k ? 10000000 : LocalHandler.that.pool * 0.3
            });
            LocalHandler.that.pool -= parseInt(ack.awardMoney);
            if (LocalHandler.that.pool < 1) {
                LocalHandler.that.pool = Math.floor(Math.random() * 555555555);
            }
            LocalHandler.that.returnMsg(MsgType.ACK_HEGUAWARD, ack);
        }
    }
    //================================================以下都是辅助方法====================================================
    private getLottery(key: boolean): string {
        if (key) {
            var value: number = Math.floor(Math.random() * 9) + 1;
            return value + "," + value + "," + value;
        }
        return Math.floor(Math.random() * 9 + 1) + "," + Math.floor(Math.random() * 9 + 1) + "," + Math.floor(Math.random() * 9 + 1);
    }

    private getActivity(): any {
        var listCls: any = LocalHandler.that.message.build("EntityAward");
        var data: Array<any> = [];
        for (var i: number = 0; i < 10; i++) {
            var ack = new listCls({
                "id": i,
                "nickname": "nick名字(" + Math.floor((Math.random() * 999)) + ")",
                "date": (new Date().getTime()) + "",
                "amount": i,
                "unit": (i * Math.floor(Math.random() * (999 - (i * 100)))) + "",
                "name": "name" + i
            });
            data.push(ack);
        }
        return data;
    }

    private getJpData(type: number): any {
        var listCls: any = LocalHandler.that.message.build("HandselAward");
        var data: Array<any> = [];
        for (var i: number = 0; i < 10; i++) {
            var ack = new listCls({
                "serial": i,
                "username": "nick名字(" + Math.floor((Math.random() * 999)) + ")",
                "happenTime": (new Date().getTime()) + "",
                "awardMoney": type == 0 ? 10000 : (LocalHandler.that.pool * 0.2),
                "handselPool": LocalHandler.that.pool
            });
            data.push(ack);
        }
        return data;
    }

    private getRankData(type: number): any {
        var listCls: any = LocalHandler.that.message.build("RankInfo");
        var data: Array<any> = [];
        for (var i: number = 0; i < 10; i++) {
            var ack = new listCls({
                "serial": i,
                "roleName": "nick名字(" + Math.floor((Math.random() * 999)) + ")",
                "userId": 0,
                "value": Math.floor(Math.random() * 5000 * (10 - i)),
                "subValue": LocalHandler.that.pool
            });
            data.push(ack);
        }
        return data;
    }

    public isConnected(): boolean {
        return true;
    }

    private getCards(key: boolean): Array<any> {
        var list: Array<any> = [];
        if (key) {
            for (var i: number = 0; i < LocalHandler.MAX_CARDS; i++) {
                //                var vo: any = LocalHandler.that.message.build("CardEntity");
                //                var type: number = RandomUtil.randInt(1,4);
                //                var port: number = (i+1);
                //                var ack = new vo({
                //                    "type": type,
                //                    "port": port
                //                });
                list.push(i);
            }
        } else {
            for (var i: number = 0; i < LocalHandler.MAX_CARDS; i++) {
                //                var vo: any = LocalHandler.that.message.build("CardEntity");
                //                var type: number = RandomUtil.randInt(1,4);
                //                var port: number = RandomUtil.randInt(1,13);
                //                var ack = new vo({
                //                    "type": type,
                //                    "port": port
                //                });
                var temp: number = Math.floor(Math.random() * 51);
                list.push(temp);
            }
        }
        return list;
    }

    private static FREE_MAX: number = 8;
    private static FREE_TIME_MAX: number = 8;
    private freeTime: number = 0;
    private freeValue: number = 0;

    private getFreeHit(): any {
        var clazz: any = LocalHandler.that.message.build("FreeHit");
        var ack = new clazz({
            "valueMax": LocalHandler.FREE_MAX,
            "currentValue": LocalHandler.that.freeValue,
            "counts": LocalHandler.that.freeTime,
            "freeAnte": 0,
            "freeState": LocalHandler.that.freeTime > 0 ? 1 : 0
        });
        return ack;
    }

    private getHelpList(): Array<any> {
        var list: Array<any> = new Array<any>();
        for (var i: number = 0; i < 9; i++) {
            var clazz: any = LocalHandler.that.message.build("Multiples");
            var ack = new clazz({
                "key": i,
                "value": i * 10,
            });
            list.push(ack);
        }
        return list;
    }

    private loseTooMuch(): void {
        var clazz: any = LocalHandler.that.message.build("AckAlertMessage");
        var data = new clazz({
            "msgType": 1
        });
        LocalHandler.that.returnMsg(MsgType.ACK_ALERT, data);
    }
}
