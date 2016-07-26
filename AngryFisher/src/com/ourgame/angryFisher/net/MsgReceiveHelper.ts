/**
* @author  sxt
*/
class MsgReceiveHelper {
    private static instance: MsgReceiveHelper;

    private clientModel: ClientModel;
    private userModel: UserModel;
    private _message: any;
    private _sender: any;

    public constructor(message: any) {
        MsgReceiveHelper.instance = this;
        this._message = message;
        this.userModel = UserModel.instance;
        this.clientModel = ClientModel.instance;
    }

    public get msg(): any {
        return this._message;
    }
    public sender(value: any): void {
        this._sender = value;
    }

    /**
     * 数据处理，反序列化
     */
    public onMessage(type: number, body?: any): void {
        var msg: any = MsgReceiveHelper.instance.msg;
        var cls: any;
        switch (type) {
            case 1:
                //心跳
                cls = msg.build("DuxLiveTick");
                var tick = cls.decode(body.buffer);
                var temp: number = parseInt(tick.time);
                break;
            case MsgType.ACK_LOGIN:
                // cls = msg.build("AckLogin");
                // var login = cls.decode(body.buffer);
                // if (login.result == 0) {
                //     UserModel.instance.money = parseInt(login.userMoney);
                //     UserModel.instance.userName = login.username;
                //     // ClientModel.instance.setLoginState(login.result);
                //     // ClientModel.instance.setFree(login.freeInfo);
                // } else {//登陆失败
                //     // login.reason
                //     console.warn("登陆服务器失败");
                //     InterfaceManager.instance.closeApp();
                //     switch (login.reason) {
                //         case 0://成功
                //             break;
                //         case 1://游戏维护中
                //             InterfaceManager.instance.closeApp();
                //             break;
                //         case 2://解析证书失败
                //             InterfaceManager.instance.closeApp();
                //             break;
                //     }
                //     // ClientModel.instance.openAlert();
                // }
                break;
            case MsgType.ACK_JPPOOL:
                cls = msg.build("AckHandselPool");
                var pool = cls.decode(body.buffer);
                // ClientModel.instance.pool = pool.pool;
                break;
            case MsgType.ACK_CHIPIN:
                cls = msg.build("AckChipIn");
                var bet = cls.decode(body.buffer);
                // ClientModel.instance.betResult = bet;
                // UserModel.instance.money = bet.userMoney;
                // ClientModel.instance.setFree(bet.freeInfo);
                break;
            case MsgType.ACK_HEGUAWARD:
                cls = msg.build("AckHugeAward");
                var data = cls.decode(body.buffer);
                // ClientModel.instance.addHegu(data);
                break;
            case MsgType.ACK_FREEHIT_INFO:
                cls = msg.build("AckUserFreeInfo");
                var data = cls.decode(body.buffer);
                // ClientModel.instance.setFree(data.free, true);
                break;
            case MsgType.ACK_MESSAGE:
                cls = msg.build("AckNoteMessage");
                var data = cls.decode(body.buffer);
                // ClientModel.instance.alert = data;
                break;
            case MsgType.ACK_ALERT:
                cls = msg.build("AckAlertMessage");
                var data = cls.decode(body.buffer);
                // ClientModel.instance.functionAlert = data.msgType;
                break;
            case MsgType.ACK_ANTEINFO:
                cls = msg.build("AckAnteInterval");
                var data = cls.decode(body.buffer);
                // ConfigModel.instance.setBetConfig(data.antelist);
                break;
            case MsgType.REQ_DUXLIVETICK:
                cls = msg.build("DuxLiveTick");
                var data = cls.decode(body.buffer);
                ClientModel.instance.onLiveTick(data.time);
                break;
            case MsgType.ACK_HELP:
                cls = msg.build("AckGameHelpInfo");
                var data = cls.decode(body.buffer);
                // ClientModel.instance.helpData = data;
                break;

        }
    }
}
