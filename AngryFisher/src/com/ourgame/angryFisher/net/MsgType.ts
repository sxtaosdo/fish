/**
 * 消息号
 * @author sxt
 */
class MsgType {
    /**请求基本消息号*/
    public static REQ_BASE: number = 10000;
    /**服务器返回基本消息号*/
    public static ACK_BASE: number = 30000;

    /**心跳*/
    public static REQ_DUXLIVETICK: number = MsgType.REQ_BASE + 0;

    /**登陆*/
    public static REQ_LOGIN: number = MsgType.REQ_BASE + 1;
    public static ACK_LOGIN: number = MsgType.ACK_BASE + 1;

    /**下注区间信息*/
    public static REQ_ANTEINFO: number = MsgType.REQ_BASE + 2;
    public static ACK_ANTEINFO: number = MsgType.ACK_BASE + 2;

    /**请求下注*/
    public static REQ_CHIPIN: number = MsgType.REQ_BASE + 3;
    public static ACK_CHIPIN: number = MsgType.ACK_BASE + 3;

    /**关闭游戏*/
    public static REQ_CLOSEGAME: number = MsgType.REQ_BASE + 4;
    public static ACK_CLOSEGAME: number = MsgType.ACK_BASE + 4;

    /**彩池值*/
    public static REQ_JPPOOL: number = MsgType.REQ_BASE + 5;
    public static ACK_JPPOOL: number = MsgType.ACK_BASE + 5;

    /** 帮助面板倍率*/
    public static REQ_HELP: number = MsgType.REQ_BASE + 6;
    public static ACK_HELP: number = MsgType.ACK_BASE + 6;

    /** 巨奖信息*/
    public static ACK_FREEHIT_INFO: number = MsgType.ACK_BASE + 7;

    /**巨奖消息*/
    public static ACK_HEGUAWARD: number = MsgType.ACK_BASE + 100;

    /**播报消息*/
    public static ACK_MESSAGE: number = MsgType.ACK_BASE + 101;

	/**
	 * 提示信息
	 * 止损、携带量不足、关闭链接等
	 */
    public static ACK_ALERT: number = MsgType.ACK_BASE + 102;
}
