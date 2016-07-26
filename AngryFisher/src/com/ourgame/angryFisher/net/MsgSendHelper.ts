/**
 * @author  sxt
 */
class MsgSendHelper {
    private static _instance: MsgSendHelper;

    private clientModel: ClientModel = ClientModel.instance;
    private userModel: UserModel = UserModel.instance;
    private _message: any;
    private _sender: any;
    private static instance: MsgSendHelper;

    public constructor(message: any) {
        MsgSendHelper.instance = this;
        this._message = message;
    }

    public get msg(): any {
        return this._message;
    }

    public sender(value: any): void {
        this._sender = value;
    }

	/**
	 * 请求登陆
	 */
    public login(): number {
        if (ConnectionManager.CONN_TYPE == 2) {
            if (!ConnectionManager.instance.isConnected) {
                return 1;
            }
        }
        var login_class = MsgSendHelper.instance.msg.build("ReqLogin");
        var userId: egret.ByteArray = new egret.ByteArray();
        var login: any = new login_class({
            "roleName": UserModel.instance.roleName,
            "userName": UserModel.instance.userName,
            "nikeName": UserModel.instance.nickName,
            "ticket": UserModel.instance.ticket,
            "channel": ClientModel.instance.channel,
            "clientType": 0//ClientModel.instance.clientType
        });

        var byts: ArrayBuffer = login.toArrayBuffer();
        ConnectionManager.instance.send(MsgType.REQ_LOGIN, byts);
        return 2;
    }

    public heartbeat(): void {
        var clazz = MsgSendHelper.instance.msg.build("DuxLiveTick");
        var proto: any = new clazz({
            "time": TimeUtils.timestampDate()
        });

        var byts: ArrayBuffer = proto.toArrayBuffer();
        ConnectionManager.instance.send(MsgType.REQ_DUXLIVETICK, byts);
    }

    /**
     * 请求下注区间
     */
    public anteInfo(): void {
        var clazz = MsgSendHelper.instance.msg.build("ReqAnteInterval");
        var req: egret.ByteArray = new egret.ByteArray();
        var proto: any = new clazz({
        });
        var byts: ArrayBuffer = proto.toArrayBuffer();
        ConnectionManager.instance.send(MsgType.REQ_ANTEINFO, byts);
    }

    /**
     * hit
     */
    public hit(bet:number): void {
        var clazz = MsgSendHelper.instance.msg.build("ReqChipIn");
        var req: egret.ByteArray = new egret.ByteArray();
        var proto: any = new clazz({
            // "anteType": ClientModel.instance.gameType,
            "ante": bet
        });
        var byts: ArrayBuffer = proto.toArrayBuffer();
        ConnectionManager.instance.send(MsgType.REQ_CHIPIN, byts);
    }

    /**
     * 帮助面板倍率
     */
    public help(): void {
        var clazz = MsgSendHelper.instance.msg.build("ReqGameHelpInfo");
        var req: egret.ByteArray = new egret.ByteArray();
        var proto: any = new clazz({
        });
        var byts: ArrayBuffer = proto.toArrayBuffer();
        ConnectionManager.instance.send(MsgType.REQ_HELP, byts);
    }
}
