/**
 * 消息号
 * @author sxt
 */
class MsgType {
    /**
     * 游戏消息的基准值
     */
    public static GLID_BASE_FISH: number = 0x000FF000;
    /**
     * C->C 客户端本地消息
     */
    public static GLFS_NetworkEvent: number = MsgType.GLID_BASE_FISH + 0x00000001;
    /**
     * 登陆海岛通知服务器Username 
     */
    public static GLFS_FishIslandRegistMailOBReq: number = MsgType.GLID_BASE_FISH + 0x9A2;
}
