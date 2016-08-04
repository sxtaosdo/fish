/*****************************************************************************\
北京联众电脑技术有限责任公司 版权所有
GLGamesProtocol.h
创建: （姓名） （日期）
检查: （姓名） （日期）
说明：(类的功能说明，使用说明)
更改记录-----------------------------------------------------------------------
修改:（日期）  （姓名）  （内容：修改或添加的函数或结构名称）
2002-5-20 王勇民
添加
	GLID_GAMECANEXIT  tagGLREQGAMECANEXIT
2002-5-22 王勇民
修改
	GLACKENTERCHANNEL中成员的定义
	GLREQENTERCHANNELEX中成员的定义
检查:（日期）  （姓名）  （内容）
\*****************************************************************************/

#ifndef __GLGAMESPROTOCOL_H__
#define __GLGAMESPROTOCOL_H__

#include "glprotocol.h"
//#include "largefixlistdyna.h"
//#include "glcheckccprotocol.h"

#define	UM_SOCKET_CLOSE			(WM_APP + 300)

//---------------------------------------------------------------------------
//	客户端请求连接通道
//---------------------------------------------------------------------------
#define GLID_ENTERCHANNEL				(GLID_BASEGAMES+0x00000000)	// 进入指定通道
#define GLBIT_ENTERCHANNEL_SUCCESS		GLBIT_SUCCESS	// 成功
#define GLBIT_ENTERCHANNEL_FAILURE		0x00000002		// 失败
#define GLBIT_ENTERCHANNEL_ILLEGALUSER	0x00000004		// 非法用户

#define	GLBIT_STATICGAME				0x80000000		// 是否静态游戏

//---------------------------------------------------------------------------
//	通知服务器 Client 未断线，每隔15分钟由Client端类向GamesServer发送一次
//	以Req头发送消息，无等待，无回应
//---------------------------------------------------------------------------
#define GLID_IDLE						(GLID_BASEGAMES+0x00000001)	

//---------------------------------------------------------------------------
// 客户端(旁观模式不用)使用此ID正常退出 GameServer，发送方可立即退出
// 其他方将接收到 GLID_ACK | GLID_EXITCHANNEL，一旦接收到则可以提示直接退出程序
//---------------------------------------------------------------------------
#define GLID_EXITCHANNEL				(GLID_BASEGAMES+0x00000002)	

typedef GLACKERR GLEXITCHANNEL,*PGLEXITCHANNEL;

//---------------------------------------------------------------------------
// 客户端(旁观模式不用)使用此ID | GLID_REQ 在游戏未结束时退出 GameServer，被扣分, 发送方接着LeaverServer
// 其他方将接收到 GLID_ACK | GLID_EXITCHANNEL，一旦接收到则可以提示直接退出程序
//---------------------------------------------------------------------------
#define GLID_ESCAPE						(GLID_BASEGAMES+0x00000003)
//#define GLID_TRUSTEXIT							(GLID_BASEGAMES+0x0000001A)	托管退出,这样客户端就有了三种退出方式

//---------------------------------------------------------------------------
// 客户端在收到此ID | GLID_ACK 时
// 旁观者表明已经和其他玩家同步
// 游戏者表明已经和断线前的状态同步
//---------------------------------------------------------------------------
#define GLID_HISTORY					(GLID_BASEGAMES+0x00000004)

// ============================================================
// 结构定义

//---------------------------------------------------------------------------
// 客户端请求进入游戏通道
//---------------------------------------------------------------------------
typedef struct tagGLREQENTERCHANNEL
{
	GLREQHEADER header;
	char	szUserName[GL_BUFLEN_USERNAME];		// 用户名
	char	szChatRoomName[GL_BUFLEN_ROOMNAME]; // 用此名字来验证通道号的合法性
												// 这是一个用字符串表示的GUID
	char	szRoomName[GL_BUFLEN_ROOMNAME];		// 请求者所在的房间名字
	WORD	wChannel;							// 通道号
	WORD	wOrder;
}GLREQENTERCHANNEL, *PGLREQENTERCHANNEL;

// 只有游戏主角全部进入后才发送
// ENTERCHANNEL 成功后返回的 Player (主角) 的 NickName (用于显示在游戏界面)
// GLID_ENTERCHANNEL
// 在Player信息之后，还紧跟私有数据的长度和内容
typedef struct tagGLACKENTERCHANNEL
{
	GLACKHEADER header;
	//DWORD	dwCount;							// 后跟主角数, PLAYERNAME
	// 下面两个是把dwCount拆分的  wym 2002-5-22 14:18:26
	WORD wCount;								// 后跟主角数, PLAYERNAME
	WORD wChatChannel;							// 聊天室通道设置  wym 2002-5-22 14:17:43
}GLACKENTERCHANNEL, *PGLACKENTERCHANNEL;

// 游戏主角的姓名, 跟在GLACKPLAYERINFO之后, 有几个主角就跟几个此结构
typedef struct tagPLAYERNAME
{
	DWORD	dwOrder;		// 主角顺序
	char	szUserName[GL_BUFLEN_USERNAME];
	char	szNickName[GL_BUFLEN_NICKNAME];
}PLAYERNAME, *PPLAYERNAME;

//---------------------------------------------------------------------------
//	新增EnterChannel消息
//	消息ID不变，改变reqEnterChannel消息的长度使服务器识别，ackEnterChannel消息
//	返回的是PLAYERNAMEEX结构
//				chenzd		2001.5.22
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// 客户端请求进入游戏通道
//---------------------------------------------------------------------------
typedef struct tagGLREQENTERCHANNELEX
{
	GLREQHEADER header;
	char	szUserName[GL_BUFLEN_USERNAME];		// 用户名
	char	szChatRoomName[GL_BUFLEN_ROOMNAME]; // 用此名字来验证通道号的合法性
												// 这是一个用字符串表示的GUID
	char	szRoomName[GL_BUFLEN_ROOMNAME];		// 请求者所在的房间名字
	WORD	wChannel;							// 通道号
	WORD	wOrder;
	BYTE	uchGetImage;						// 倒数第一位表示是否要头像，
												// 倒数第二位表示是否由服务器控制客户端的聊天室通道  wym 2002-5-22
												// 倒数第三位表示客户端是否是unicode  wym add 2003-3-15
}GLREQENTERCHANNELEX, *PGLREQENTERCHANNELEX;

// 游戏主角的姓名, 跟在GLACKPLAYERINFO之后, 有几个主角就跟几个此结构
typedef struct tagPLAYERNAMEEX
{
	DWORD	dwOrder;		// 主角顺序
	char	szUserName[GL_BUFLEN_USERNAME];
	char	szNickName[GL_BUFLEN_NICKNAME];
	int		nImage;			//人物形象
}PLAYERNAMEEX, *PPLAYERNAMEEX;

//---------------------------------------------------------------------------
// 通用的命令行传递参数(Room->GameClient)
//---------------------------------------------------------------------------
typedef struct tagARGUMENT
{
	int		nSeat;								// 本方位置(从1开始)，通过判断可以知道是不是旁观
	char	szUserName[GL_BUFLEN_USERNAME];		// 用户名
	char	szNickName[GL_BUFLEN_NICKNAME];		// 中文名
	char	szRoomName[GL_BUFLEN_ROOMNAME];		// 所在 Room Name
	WORD	wChannel;							// 通道号
	char	szChatRoomName[GL_BUFLEN_ROOMNAME];	// Chat Room Name
	char	szHost[GL_BUFLEN_HOST];				// Game Host
	WORD	wPort;								// Game Port
	char	szHtml[GL_BUFLEN_HTML];
// 1998.4.29 增加
// --------------
	char	szChatHost[GL_BUFLEN_HOST];			// Chat Host
	WORD	wChatPort;							// Chat Port
	char	szRank[GL_BUFLEN_RANKNAME];			// 等级
	DWORD	dwScore;							// 积分
	int		nStartForBreak;						// 是否断线续玩 0:正常 1:断线续玩 2:转播 3:断线续转播
//增加财富
//chenzd	2001.5.12
	DWORD	dwMoney;
}ARGUMENT, *PARGUMENT;


//---------------------------------------------------------------------------
// 通用的版本信息
//---------------------------------------------------------------------------
typedef struct tagGLEXEVERSION
{
	DWORD	dwExeLang;				//语言
	DWORD	dwDllLang;
	DWORD	dwExeFileVersionMS;		//文件的版本号
	DWORD	dwExeFileVersionLS;
	DWORD	dwDllFileVersionMS;		//动态连接库文件的版本号
	DWORD	dwDllFileVersionLS;
	char	szExeFileVersion[GL_BUFLEN_VERSION];	//文件的版本号"1.10.0.5"
	char	szDllFileVersion[GL_BUFLEN_VERSION];
	char	szExeInternalName[GL_BUFLEN_NAMES];	//内部名称"MJ"
	char	szDllInternalName[GL_BUFLEN_NAMES];	//内部名称"MJ936Resource"

	char	szFileVersion[GL_BUFLEN_VERSION];	//文件的版本号"1.10 Beta5"

	char	szDescription[GL_BUFLEN_NAMES];	//描述"联众网络游戏世界"
	char	szProductName[GL_BUFLEN_NAMES];	//名称"麻将"
	char	szSpecialBuild[GL_BUFLEN_NAMES];	//biuld num
	char	szCompanyName[GL_BUFLEN_NAMES];	//公司名称"北京联众电脑技术有限责任公司"
	char	szCopyright[GL_BUFLEN_NAMES];	//版权"版权所有 (C)1998-2000.4"
	char	szComments[GL_BUFLEN_NAMES];	//注释//开发时间"2000.4.4"
}GLEXEVERSION, *PGLEXEVERSION;


//---------------------------------------------------------------------------
//	更换广告消息
//---------------------------------------------------------------------------
#define GLID_ADVERT							(GLID_BASEGAMES+0x00000005)
#define GLID_TEXTADVERT						(GLID_BASEGAMES+0x00000006)
#define GLID_LARGEADVERT					(GLID_BASEGAMES+0x00000007)
#define GLID_GETALLADVERT					(GLID_BASEGAMES+0x00000008)		//客户端刚启动时请求服务器发送所有的广告下来  wym 2002-5-16 9:50:20

typedef struct tagGLREQADVERT
{
	GLREQHEADER header;
	char szAdvert[GL_BUFLEN_HOST];
	int nID;
	int nPlaySecond;
}GLREQADVERT, *PGLREQADVERT;

typedef struct tagGLREQNEWADVERT
{
	DWORD       ChannelID;        //对应频道
    DWORD       AdvertID;         //对应广告ID
    WORD        PopupWidth;       //弹出窗口宽度
	WORD        PopupHeight;      //弹出窗口高度
	WORD        LargeType;        //全屏广告类型
	WORD        LargeShowTime;    //全屏广告显示时间
	WORD        LargeWidth;       //全屏广告宽度
    WORD        LargeHeight;      //全屏广告高度
    char        MainURL[256];
    char        PopupURL[256];
	char        LargeURL[256];
	char        Tips[256];
}GLREQNEWADVERT,*PGLREQNEWADVERT;

#define	UM_ADCTRLNTYMSG				 WM_USER+301 
                                         //广告通知消息
#define	UM_WORLDSYSTRAYNOTIFY		 WM_USER+303 
                                         //任务栏图标通知消息
#define	UM_AVATARDOWNLOADNOTIFY		 WM_USER+304 
                                         //avatar控件通知大厅下载文件消息

//---------------------------------------------------------------------------
//	棋类比赛文件结构//牌类比赛也用同一个结构
//---------------------------------------------------------------------------
typedef struct tagCHESSMATCHFILEINFO
{
	WORD wHeader;							//must be 'GL'
	DWORD dwSize;							//total length
	int cnRoom;								//total room
	int cnPlayer;							//total player
	int cnNoMatchPlayers;					//no match player
	int cnSaveFile;							//total already save file
	BOOL bDelaySetted;
	DWORD dwMaxPlayCount;
	//PMATCHPLAYERINFO pmpi;					//first playerinfo
}CHESSMATCHFILEINFO,*PCHESSMATCHFILEINFO;

//---------------------------------------------------------------------------
//	瑞士移位比赛文件结构
//---------------------------------------------------------------------------
typedef struct tagSWISSMATCHFILEINFO
{
	WORD wHeader;							//文件头,必须为'GL'
	DWORD dwSize;							//文件总长度
	int cnRoom;								//这轮比赛有多少个比赛房间
	int cnPlayer;							//总共多少位选手参加
	int cnGame;
	BOOL bDelaySetted;						//是否已经设置了弃权选手的标志
	DWORD dwOffsetOfData;					//私有数据起始地址
}SWISSMATCHFILEINFO,*PSWISSMATCHFILEINFO;

//---------------------------------------------------------------------------
//	比赛每副牌的结构，最多打4副牌的
//---------------------------------------------------------------------------
typedef struct tagSWISSMATCHCARDINFO
{
	int cnGame;
	char achCard[54*4];
}SWISSMATCHCARDINFO,*PSWISSMATCHCARDINFO;

#define	GL_SWISSMATCHSCOREFILESIGN	"SwissScoreDatFile"
#define GL_SWISS_SIGNUP_FILE 0
#define GL_SWISS_PLAYER_FILE 1
#define GL_SWISS_QUITER_FILE 2
#define GL_SWISS_TEAM_FILE	 3

typedef struct tagSWISSMATCHSCOREFILEHEAD
{
	char szSign[32];
	int cnGame;
	int cnPlayer;
}SWISSMATCHSCOREFILEHEAD,*PSWISSMATCHSCOREFILEHEAD;

typedef struct tagSWISSMATCHSCOREINFO
{
	int nGame;
//	char aszUserName[GL_MAX_PLAYERSPERTABLE][GL_BUFLEN_USERNAME];
	int anTeamID[4];		//如果是分组赛，2个Team，个人赛，4个Team
	int anScore[4];			//分组赛，anScore[0]就是一组的分
	int anMatchScore[4];	//分组赛，anMatchScore[0]就是一组的比赛分
}SWISSMATCHSCOREINFO,*PSWISSMATCHSCOREINFO;

//瑞士比赛中恶意弃权的ID名单，用来给出惩罚措施
typedef struct tagSWISSBADPLAYER
{
	char szUserName[GL_BUFLEN_USERNAME];
	int nCount;
	DWORD dwStartDate;
}SWISSBADPLAYER,*PSWISSBADPLAYER;

typedef struct tagPARTNERSIGNUP
{
	char aszUserName[3][GL_BUFLEN_USERNAME];
}PARTNERSIGNUP,*PPARTNERSIGNUP;

typedef struct tagSWISSMATCHSIGNUP
{
	DWORD dwTeamID;			//数据库中使用的唯一的TeamID
	char aszUserName[3][GL_BUFLEN_USERNAME];
}SWISSMATCHSIGNUP,*PSWISSMATCHSIGNUP;

//gao, 瑞士移位比赛的数据结构定义
#define SWISS_MATCH_MAX_CARDS 56
typedef struct tagSWISSMATCHPLAYER
{
	char aszUserName[3][GL_BUFLEN_USERNAME];
	int nTeamNo;		//对序列号，GameServer端用的
	DWORD dwTeamID;		//数据库中使用的唯一的TeamID
	int nStartStage;
	int nEndStage;
	//！注意，这里只记录实际打过的牌数，
	//不用来作是否完成比赛的判断标准
	//因为对手弃权时此值不加，但增加他们的副数
	int nFinishedHands;		//目前为止，打过的牌数
	int nScore[SWISS_MATCH_MAX_CARDS];	//每副得分
	int nTotalScore;
}SWISSMATCHPLAYER,*PSWISSMATCHPLAYER;

//---------------------------------------------------------------------------
//	***周志超加入以下的所有消息，为了牌类新版的客户端 2000/10/12***
//---------------------------------------------------------------------------

// 这个消息是当用户按下开始按钮以后的发送的(Client->Server)
#define GLID_GAMECONTINUE						(GLID_BASEGAMES+0x0000000A)

// 这个消息是当用户出牌(Client->Server)，服务器转发出牌(Server->Client)
#define GLID_GAMETAKEOUTCARD					(GLID_BASEGAMES+0x0000000B)

// 发牌的消息 (Server->Client)
#define GLID_GAMEINITCARD						(GLID_BASEGAMES+0x0000000C)

//客户端发送退出请求到服务器(Client->Server)，服务广播这个请求(Server->Client)
#define GLID_GAMEREQEXIT						(GLID_BASEGAMES+0x0000000E)

// 客户端发送同意退出请求(Client->Server)
// 如果其他的玩家都同意退出，服务发送这个请求给请求退出的客户(Server->Client)
#define GLID_GAMEAGREEDEXIT						(GLID_BASEGAMES+0x0000000F)

//一幅牌结束，(Client->Server)
#define GLID_GAMEOVERTHIS						(GLID_BASEGAMES+0x00000010)

//游戏结束(Client->Server)或(Server->Client)
#define GLID_GAMEEXIT							(GLID_BASEGAMES+0x00000011)//GLID_EXITCHANNEL

//错误消息 (Client->Server)
#define GLID_GAMEERRMESS						(GLID_BASEGAMES+0x00000012)
//错误消息结构 这个结构后面可以附带相关错误消息的详细信息
typedef struct tagGLACKGAMEERR
{
	GLACKERR	ErrHead;
//	GLREQHEADER header;
	DWORD dwSeat;
	DWORD dwErr;	//错误码
}GLACKGAMEERR, *PGLACKGAMEERR;

//旁观者或者断线续玩的玩家接受消息结束的消息
#define GLID_GAMEWATCHINFOEND					(GLID_BASEGAMES+0x00000013)

//允许玩家旁观的消息
#define GLID_GAMEWATCHABLE						(GLID_BASEGAMES+0x00000014)

//游戏结束传送结果到客户端的消息
#define	GLID_GAMERESULTTOCLIENT					(GLID_BASEGAMES+0x00000015)

//游戏者超时的消息
#define GLID_GAMEOVERTIME						(GLID_BASEGAMES+0x00000016)

//同步客户端当前状态的消息
#define GLID_GAMESYNCEXIT						(GLID_BASEGAMES+0x00000017)

#define GLID_GAMERESULT							(GLID_BASEGAMES+0x00000018)

// wym add 2001.2.23    GLID_GAMEOVERALL
// 游戏结束消息
// 一般在比赛时使用,到指定的比赛盘数后发这个消息
// 客户端收到这个消息后自动退出程序
// 服务器发出这个消息后退出game
#define GLID_GAMEOVERALL						(GLID_BASEGAMES+0x00000019)
//比赛结束消息,wuqy,2001.12.5
typedef struct tagGLACKMATCHNEWSTAGEOVER
{
	GLACKHEADER header;
	BOOL	bExit;					//当前是否立即退出
}GLACKMATCHNEWSTAGEOVER,*PGLACKMATCHNEWSTAGEOVER;//后跟退出提示字符串

// wym add 2004.2.26
// 托管退出，托管退出后不再有断线续玩，但是服务器不结束该client，直到一局游戏结束后自动结束游戏，这样客户端就有了三种退出方式
#define GLID_TRUSTEXIT							(GLID_BASEGAMES+0x0000001A)
typedef struct tagGLREQTRUSTEXIT
{
	GLREQHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];
}GLREQTRUSTEXIT, *PGLREQTRUSTEXIT;
// 服务器可以不允许客户端托管退出，所以客户端必须等待返回确认消息
typedef struct tagGLACKTRUSTEXIT
{
	GLACKHEADER header;			//header.dwResult 取值GLBIT_SUCCESS GLBIT_FAIL
	char szUserName[GL_BUFLEN_USERNAME];
	// 消息后面可以跟不允许退出的提示字符串，通过header.dwLength判断
}GLACKTRUSTEXIT, *PGLACKTRUSTEXIT;

#ifndef _MATCHSYSTEM
#define MAX_TRUSTPLAY_COUNT						3	// 最多允许三次托管
#else
#define MAX_TRUSTPLAY_COUNT						0xffff	// 比赛系统不限次数
#endif

// 托管游戏 wym add 2004.2.26
#define GLID_TRUSTPLAY							(GLID_BASEGAMES+0x0000001B)
typedef struct tagGLREQTRUSTPLAY
{
	GLREQHEADER header;
	DWORD	dwType;		// 1=手动托管 0=解除托管 2=超时托管
	char szUserName[GL_BUFLEN_USERNAME];
}GLREQTRUSTPLAY, *PGLREQTRUSTPLAY;
typedef struct tagGLACKTRUSTPLAY
{
	GLACKHEADER header;	//header.dwResult 取值GLBIT_SUCCESS GLBIT_FAIL
	WORD	wType;		// 1=手动托管 0=解除托管 2=超时托管
	WORD	wCount;		// 0 表示服务器不允许托管
						// 其他 =(托管的次数 + 允许托管的次数<<8)
	char szUserName[GL_BUFLEN_USERNAME];
}GLACKTRUSTPLAY, *PGLACKTRUSTPLAY;

// 服务器要告诉客户端能否托管和托管退出 wym 2004.3.4
//#define GLID_CANTRUSTPLAYEXIT					(GLID_BASEGAMES+0x0000001C)
// 将上面的消息改定义成服务器属性，用位表示 wym 2004.4.13
#define GLID_SVRPROPERTY						(GLID_BASEGAMES+0x0000001C)
#define SVRPROPERTY_CANTRUSTPLAY		1	// 允许托管和托管退出退出
#define SVRPROPERTY_SCORETOMONEY		2	// 财富版，分数直接对应财富
#define SVRPROPERTY_MASTERTEACH			4	// 大师指导游戏
#define SVRPROPERTY_GAMECOIN			8	// 是否是游戏豆游戏服务器 wym 2005.4.4
#define SVRPROPERTY_INDICT_INROOM		16	// 是否可以在ROOM内投诉
#define SVRPROPERTY_INDICT				SVRPROPERTY_INDICT_INROOM	// 为兼容
#define SVRPROPERTY_INDICT_INGAME		32	// 是否可以在GAME内投诉

// wym begin add 2001.4.10 为了下注功能添加下面的消息
//-------------------------------------------------------------------------
// 房间是否支持下注 进入游戏时把上面的消息发给客户端，客户端根据这个消息决定下注button是否enable
//-------------------------------------------------------------------------
#define	GLID_GAMECANBET							(GLID_BASEGAMES+0x00000020)
typedef struct tagGLACKGAMECANBET
{
    GLACKHEADER header ;	//header.dwType = GLID_GAMECANBET ;
							//header.dwResult = 0 ;   // 可以下注
							//header.dwResult = 1 ;   // 不可以下注
}GLACKGAMECANBET,*PGLACKGAMECANBET ;

typedef struct tagGLPLAYERBET
{
	char szUserName[GL_BUFLEN_USERNAME];
	int nMoney;				// 压UserName赢的赌注
}GLPLAYERBET,*PGLPLAYERBET;

#define BET_ERROR_SUCCESS		0		// 下注成功
// 下面都是下注失败的原因
#define BET_FAIL				1		// 未知的失败
#define BET_ROOMCANNOTBET		2		// 房间不允许下注
#define BET_DISAGREE			3		// 对方不同意下注
#define BET_NOMONEY1			4		// 下棋者Bet1钱不够，旁观者自己钱不够
#define BET_NOMONEY2			5		// 下棋者Bet2钱不够
#define BET_NOMONEYALL			6		// 钱都不够
#define BET_BETTIMEOVER			7		// 已经过了下注时间
#define BET_ROOMCANNOTTEACH		8		// 房间不允许下指导棋
#define BET_CHANGEBETTYPE		9		// 中途修改了下注的类型(是否指导棋)
#define BET_OPCLIENTCANNOTBET	10		// 对方客户端不支持下注
#define BET_MAXPLAYER			11		// 竞猜的人数已满
#define BET_MAXBET				12		// 竞猜的项目已满
#define BET_BETSTOP				13		// 暂停竞猜
#define BET_SERVERBUSY			14		// 服务器忙
#define BET_PLAYERBUSY			15		// 对方正忙，顾不着处理请求
#define BET_CHANGETEACHER		16		// 已经定了由谁付指导费，不可以再修改
#define BET_NOTMEMBER			17		// 不是会员 不可以下注

//-------------------------------------------------------------------------
// 游戏者下注的消息，包括指导棋
//-------------------------------------------------------------------------
#define GLID_GAMEBETPLAYER						(GLID_BASEGAMES+0x00000021)

typedef struct tagGLREQGAMEBETPLAYER
{
    GLREQHEADER header ;    // header.dwType = GLID_GAMEBETPLAYER
	GLPLAYERBET Bet1 ;		// Bet1.szUserName 发出请求的人的ID
	GLPLAYERBET Bet2 ;
    DWORD		dwType ;        // 下注的类型 0=正常下注 1=指导棋
}GLREQGAMEBETPLAYER, *PGLREQGAMEBETPLAYER ;

// 下棋者的赌注回复消息
typedef struct tagGLACKGAMEBETPLAYER
{
    GLACKHEADER	header ;    // header.dwType = GLID_GAMEBETPLAYER
	DWORD		dwResult ;	// 0下注成功 下注失败时有意义 1=房间不允许下注 2=Bet1钱不够 3=已经过了下注的时间 4=Bet2钱不够 5=钱都不够 6=对方不同意 7=房间不允许下指导棋 8=改了dwType 9=服务器忙 10=对方客户端不支持下注
	GLPLAYERBET	Bet1 ;		// Bet1.szUserName 发出请求的人的ID
	GLPLAYERBET	Bet2 ;
    DWORD		dwType ;	// 下注的类型 0=正常下注 1=指导棋 第一次定了以后就不能改
    int			nMoney1 ;	// 如果是钱不够是Bet1剩的钱, 如果下注成功是前面押player1赢的赌注，如果不是会员失败标志1=bet1不是会员2＝bet2不是会员
    int			nMoney2 ;	// 如果是钱不够是Bet2剩的钱, 如果下注成功是前面押player2赢的赌注
}GLACKGAMEBETPLAYER, *PGLACKGAMEBETPLAYER ;

//-------------------------------------------------------------------------
// 旁观者下注的消息
//-------------------------------------------------------------------------
#define GLID_GAMEBETSPECTATOR					(GLID_BASEGAMES+0x00000022)

typedef struct tagGLREQGAMEBETSPECTATOR
{
    GLREQHEADER header ;		// header.dwType = GLID_GAMEBETSPECTATOR
	char	szUserName[GL_BUFLEN_USERNAME] ;	// 下注人的ID
	GLPLAYERBET Bet1 ;
	GLPLAYERBET Bet2 ;
    int			nMoneyDraw ;   // 押和棋的赌注
}GLREQGAMEBETSPECTATOR, *PGLREQGAMEBETSPECTATOR ;

// 旁观者下注的回复消息
typedef struct tagGLACKGAMEBETSPECTATOR
{
    GLACKHEADER	header ;		// header.dwType = GLID_GAMEBETSPECTATOR
	char	szUserName[GL_BUFLEN_USERNAME] ;	// 下注人的ID
	DWORD		dwResult ;		// 0=下注成功 下注失败时有意义 1=房间不允许下注 2=自己的钱不够 3=已经过了下注的时间(旁观者有用) 4=服务器忙
	GLPLAYERBET	Bet1 ;
	GLPLAYERBET	Bet2 ;
    int			nMoneyDraw ;	// 和棋的赌注
    int			nMoney1 ;		// 以前押player1赢的赌注, 如果钱不够代表自己当前可用的钱
    int			nMoney2 ;		// 以前押player2赢的赌注
    int			nMoney3 ;		// 以前押和棋的赌注
}GLACKGAMEBETSPECTATOR, *PGLACKGAMEBETSPECTATOR ;

//-------------------------------------------------------------------------
// 一盘棋结束后下注的开盘结果
//-------------------------------------------------------------------------
#define GLID_GAMEBETRESULT						(GLID_BASEGAMES+0x00000023)

#define GAMERESULT_NULL		0	// 游戏无效
#define GAMERESULT_DRAW		1	// 和棋
#define GAMERESULT_WIN		2	// 分出胜负
#define GAMERESULT_ESC		3	// 有人逃跑,一般判逃跑的人输
#define GAMERESULT_TEACH	4	// 是指导棋

typedef struct tagGLACKGAMEBETRESULT
{
    GLACKHEADER header ;		// header.dwType = GLID_GAMEBETRESULT 
    char	szUserName[GL_BUFLEN_USERNAME] ;  // 赢棋人的ID
    DWORD	dwResultType ;		// 比赛的结果 看上面的定义
    int		iMoneyBet ;			// 自己押的总钱数,包括无效的下注
    int		iMoneyWin ;			// 自己赢的钱(包括压的钱)
	int		iTaxRate ;			// 对赢的钱收的税率 最大10000
	//  wym 2001-7-27
	int		iMoneyInv ;			// 无效的下注 
}GLACKGAMEBETRESULT, *PGLACKGAMEBETRESULT ;

//-------------------------------------------------------------------------
// 游戏者向服务器查询已经下的赌注
//-------------------------------------------------------------------------
#define GLID_GAMEBETRETRIEVEPLY					(GLID_BASEGAMES+0x00000024)

//-------------------------------------------------------------------------
// 旁观者向服务器查询已经下的赌注
//-------------------------------------------------------------------------
//#define GLID_GAMEBETRETRIEVESPE					(GLID_BASEGAMES+0x00000026)

// 游戏者查询下注的返回
typedef struct tagGLACKGAMEBETRETRIEVEPLY
{
	GLACKHEADER	header ;	// header.dwType = GLID_GAMEBETRETRIEVEPLY
	GLPLAYERBET Bet1 ;		// 游戏者1的下注
	GLPLAYERBET Bet2 ;		// 游戏者2的下注
}GLACKGAMEBETRETRIEVEPLY, *PGLACKGAMEBETRETRIEVEPLY ;

// 旁观者查询下注的返回
typedef struct tagGLACKGAMEBETRETRIEVESPE
{
	GLACKHEADER		header ;	// header.dwType = GLID_GAMEBETRETRIEVESPE
	char	szUserName1[GL_BUFLEN_USERNAME];	// 游戏者User1
	char	szUserName2[GL_BUFLEN_USERNAME];	// 游戏者User2
	int		iMoneyPly1 ;	// 游戏者1的下注
	int		iMoneyPly2 ;	// 游戏者2的下注
	int		iMoneyMy1 ;		// 旁观者自己压User1的总钱数
	int		iMoneyMy2 ;		// 旁观者自己压User2的总钱数
	int		iMoneyMy3 ;		// 旁观者自己压和的总钱数
	int		iMoneyAll1 ;	// 所有旁观者压User1的总钱数
	int		iMoneyAll2 ;	// 所有旁观者压User2的总钱数
	int		iMoneyAll3 ;	// 所有旁观者压和的总钱数
	int		iCount1 ;		// 旁观者压User1的总人数 
	int		iCount2 ;		// 旁观者压User2的总人数
	int		iCount3 ;		// 旁观者压和的总人数
	BOOL	bTeach ;		// 是否指导棋, 这是后加的	wym 2001-7-3 10:32:08
}GLACKGAMEBETRETRIEVESPE, *PGLACKGAMEBETRETRIEVESPE ;

// 旁观者押注的信息
typedef struct tagGLBETSPECTATOR
{
	char		szUserName[GL_BUFLEN_USERNAME];		// 下注人的ID
	GLPLAYERBET Bet1 ;
	GLPLAYERBET Bet2 ;
	int			nMoney3 ;							// 押和棋的钱
	// wym 2001-7-27 
	union{
		int		nHands ;							// 下注时是第几手棋 wym 2001-7-27 13:41:22
		int		nMoneyInv;							// 只在计算竞猜结果时用
	};
}GLBETSPECTATOR, *PGLBETSPECTATOR ;

// 下棋者压注的信息
typedef struct tagGLBETPLAYER
{
	GLPLAYERBET Bet1 ;
	GLPLAYERBET Bet2 ;
	BOOL		bTeach ;	// 是否是指导棋 0=不是 1=是
							// bTeach=0 钱都给赢棋者 
							// bTeach=1 不管输赢钱都给nMoney=0的人
}GLBETPLAYER, *PGBETPLAYER ;

typedef struct tagGLBETPLAYERCHK
{
	BOOL		bReq ;	// 有人发出了请求
	char szReqUserName[GL_BUFLEN_USERNAME];	// 发请求的人
	GLPLAYERBET Bet1 ;
	GLPLAYERBET Bet2 ;
}GLBETPLAYERCHK, *PGBETPLAYERCHK ;

// wym end 2001.4.10

//---------------------------------------------------------------------------
//	2001.4.20 byq，通用的服务器端向客户端发送的命令消息
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//	服务器端向客户端发出的命令
//	1.是否需要提示信息
//	2.如果需要提示信息，提示信息中的按钮有些什么
//	3.用户按了按钮后，需要做什么动作
//	4.在处理完后是否需要关闭socket
//	5.在处理完后是否需要退出程序
//---------------------------------------------------------------------------
#define	GLID_SVRCMD							(GLID_BASEGAMES+0x00000025)

//---------------------------------------------------------------------------
//	nMsgID	-1		表示不提示信息
//			0		本消息尾跟提示信息，以0结尾，
//			其它	从LangRsc.ini文件中的[String]节中读取这个数值的项值来进行提示
//	nAction	0		显示URL，URL的地址在消息后跟上，如果出现两个字符串，则分别以0结尾，顺序排列
//			-1		什么都不做
//---------------------------------------------------------------------------
typedef struct tagGLREQSVRCMD
{
	GLREQHEADER header;
	int nMsgID;
	int nMsgFlags;							//如果有提示信息，是MessageBox的flag值
	int nActionResult;						//如果有提示信息，当MessageBox返回该值时执行nAction命令，-1什么都不做
	int nAction;							//即使没有提示信息，也可能有需要显示URL的
	BOOL bClose;							//处理完消息后，是否需要关闭socket
	BOOL bTerminate;						//处理完消息后，是否需要退出程序
	DWORD dwDataLength;						//尾跟数据的长度
}GLREQSVRCMD,*PGLREQSVRCMD;

//-------------------------------------------------------------------------
// 旁观者向服务器查询已经下的赌注
//-------------------------------------------------------------------------
#define GLID_GAMEBETRETRIEVESPE					(GLID_BASEGAMES+0x00000026)

// 刷新客户端的钱  wym 2001-6-19 14:50:37
#define GLID_GAMEREFRESHMEONY					(GLID_BASEGAMES+0x00000027)
typedef struct tagGLACKREFRESHMONEY
{
	GLACKHEADER header ;
	char	szUserName[GL_BUFLEN_USERNAME] ;
	int		iMoney ;		// username的财富
}GLACKREFRESHMONEY, *PGLACKREFRESHMONEY ;

// 通知旁观者有人下了注: 1.旁观者进入时, 2.游戏者或旁观者下了注广播给所以其他旁观者  wym 2001-7-2 15:30:15
#define GLID_GAMEBETNOTIFY						(GLID_BASEGAMES+0x00000028)

#define BETNOTIFY_ENTERGAME		0x10			// 旁观者进入时
#define BETNOTIFY_PLAYER		0x11			// 游戏者下注
#define BETNOTIFY_SPECTATOR		0x12			// 旁观者下注

// wym 2002-1-7 17:48:47
// 广播给其他人某人断线或断线续玩    
#define GLID_GAMEBREAK                          (GLID_BASEGAMES+0x00000029)
#define GLID_GAMEREENTER                        (GLID_BASEGAMES+0x0000002A)
typedef struct tagGLREQBREAK
{
    GLREQHEADER header ;
    char szUserName[GL_BUFLEN_USERNAME] ;
}GLREQBREAK, *PGLREQBREAK ;
typedef struct tagGLREQREENTER
{
    GLREQHEADER header ;
    char szUserName[GL_BUFLEN_USERNAME] ;
}GLREQREENTER, *PGLREQREENTER ;
// 下面用不同的位表示玩家不同的状态
#define ST_NORMAL       0       // 正常游戏还没有开始也没有举手
#define ST_PLAYING      1       // 正在游戏
#define ST_START        2       // 按了开始按钮(举手了)
#define ST_OFFLINE      4       // 断线 break
#define ST_ESCAPE       8       // 逃跑
#define ST_AUTOPLAY		16		// 自动托管，如果ST_OFFLINE是服务器在自动出牌，否则是客户端自动出牌 wym 2002-9-19
#define ST_TRUSTPLAY	32		// 托管游戏 wym 2004-2-29
#define ST_TRUSTEXIT	64		// 托管退出 wym 2004-2-29
// wym end

// 游戏者的状态，用于旁观或断线续玩时发给客户端每个人的状态  wym 2002-4-15 11:03:02
#define GLID_GAMEUSERSTATUS						(GLID_BASEGAMES+0x0000002B)
typedef struct tagGLACKGAMESTATUS	// 游戏者的状态，数据长度可变
{
	GLACKHEADER header;
	BOOL		bIsGaming;		// 是否游戏在进行中
	int			cnUser;			// 后面跟了几个人的状态 USERSTATUS
	// 后面跟数个人的状态信息，长度为 sizeof(USERSTATUS) * n
	// USERSTATUS aUserStatus[n];
	struct USERSTATUS
	{
		char szUserName[GL_BUFLEN_USERNAME];
		DWORD	dwStatus;	// ST_NORMAL ST_OFFLINE 等见上面的定义
	};
	tagGLACKGAMESTATUS()
	{
		header.dwType = GLID_ACK | GLID_GAMEUSERSTATUS;
		header.dwLength = sizeof(tagGLACKGAMESTATUS) - sizeof(header);
		cnUser = 0;
	}
} GLACKGAMESTATUS, *PGLACKGAMESTATUS;	// wym 2002-4-15 11:03:02

// 限制的类型  wym 2002-4-15 14:23:13
#define	GL_LIMIT_NULL		0		// 不限制
#define GL_LIMIT_PERMIT		1		// 只允许...
#define GL_LIMIT_FORBID		2		// 不允许...

//返回游戏服务器的版本和类库的版本 shil 2002.4.20
//增加返回游戏服务器的Client连接个数 shil 2002.7.15
// 增加返回游戏基类版本。 liujx 2005.4.27
#define GLID_GETSVRVERSION						(GLID_BASEGAMES+0x0000002C)	
typedef struct tagGLACKGETSVRVERSION
{
	GLACKHEADER header;
	DWORD dwSvrVersion;				// 服务器版本。
	DWORD dwSvrBaseVersion;			// 基类库 ServiceBase 版本。
	DWORD dwSvrClientCount;			// 连结的客户端数量。
	DWORD dwSvrGameBaseVersion;		// 基类库 GameBase 版本。 - add by liujx: 2005.4.27
}GLACKGETSVRVERSION,*PGLACKGETSVRVERSION;

// 服务器发给客户端是否允许客户端退出消息
#define GLID_GAMECANEXIT						(GLID_BASEGAMES+0x0000002D)
typedef struct tagGLREQGAMECANEXIT
{
	GLREQHEADER header;
	BOOL bCanExitGame	;	// =TRUE可以退出游戏，=FALSE不可以退出游戏
	tagGLREQGAMECANEXIT()
	{
		header.dwType = GLID_REQ | GLID_GAMECANEXIT;
		header.dwLength = sizeof(tagGLREQGAMECANEXIT) - sizeof(header);
		bCanExitGame = TRUE;
	}
}GLREQGAMECANEXIT, *PGLREQGAMECANEXIT;

// 这个消息不在网上发送，是CGLSocket::OnClose() 人为产生的消息，
// 目的是使OnClose也在消息队列中执行 wym
#define GLID_CLIENTSOCKETCLOSE					(GLID_BASEGAMES+0x0000002E)

//服务器发给客户端的询问请求 wuqy 2003.04.03 add
#define	GLID_SVRQUERY							(GLID_BASEGAMES+0x00000030)
typedef struct tagGLREQSVRQUERY
{
	GLREQHEADER header;
	DWORD dwQueryID;						//请求序列号
	int nMsgFlags;							//如果有提示信息，是MessageBox的flag值
	UINT nWaitSeconds;						//询问框等待时间
	BOOL bRetString;						//需要返回应答字符串
	//后跟询问字符串
}GLREQSVRQUERY,*PGLREQSVRQUERY;
typedef struct tagGLACKSVRQUERY
{
	GLACKHEADER header;
	DWORD dwQueryID;
	int nResult;							//返回值
	//后跟应答字符串
}GLACKSVRQUERY,*PGLACKSVRQUERY;

//服务器取客户端的地址和端口 wuqy 2003.04.03 add
#define	GLID_GETCLIENTADDRPORT							(GLID_BASEGAMES+0x00000031)
typedef struct tagGLREQGETCLIENTADDRPORT
{
	GLREQHEADER header;
}GLREQGETCLIENTADDRPORT,*PGLREQGETCLIENTADDRPORT;
typedef struct tagGLACKGETCLIENTADDRPORT
{
	GLACKHEADER header;
	DWORD dwAddr;
	UINT m_nPort;
}GLACKGETCLIENTADDRPORT,*PGLACKGETCLIENTADDRPORT;

// wym add 2003-4-21
// 指定定允许(不允许)旁观者列表，可以是多人		
// 在基类处理缺省是按原来的方案(AssignWatcher=0)，如果服务器ini里写了AssignWatcher=1
// 则只允许指定的人看棋（牌）
#define GLID_ASSIGNWATCHERS								(GLID_BASEGAMES+0x00000032)
typedef struct tagGLREQASSIGNWATCHERS
{
	GLREQHEADER header;
	WORD	wCanWatch;	// !0 代表允许下面的人旁观，0 不允许下面的人旁观
	WORD	wCount;		// 后面跟多少个旁观者的username
}GLREQASSIGNWATCHERS, *PGLREQASSIGNWATCHERS;
// 后面跟wCount个username，每个username用\0间隔

#define GLID_MONEYCHANGE								(GLID_BASEGAMES+0x00000033)
typedef struct tagMONEYCHANGE
{
	char szUserName[GL_BUFLEN_USERNAME];
	DWORD dwMoney;
	DWORD dwMoneyDelta;
}MONEYCHANGE, *PMONEYCHANGE;
typedef struct tagGLACKMONEYCHANGE
{
	GLACKHEADER header;		// header->dwResult =1代表客户端是否出提示财富变化的对话框
	// 后面跟 n 个MONEYCHANGE
}GLACKMONEYCHANGE, *PGLACKMONEYCHANGE;

// 服务器发给客户端的提示信息，客户端基类用MsgBox显示
#define GLID_MSGBOX										(GLID_BASEGAMES+0x00000034)
typedef struct tagREQMSGBOX
{
	GLREQHEADER header;
	DWORD dwIDPrompt;		// 0==消息后面跟提示字符串，!0==用这个id资源对应的字符串MsgBox(dwIDPrompt, ...)
	DWORD dwType;			// 按钮的类型
	DWORD dwTime;			// MsgBox显示几秒后自动关闭 0==不自动关闭
	// szPrompt[];			如果 dwIDPrompt==0 后面跟的是提示字符串
}GLREQMSGBOX, *PGLREQMSGBOX;

//wuqy add2005.1.24
//随机取得一个用户，用于抽奖赠送
#define GLID_GETRANDOMUSER					(GLID_BASEGAMES+0x00000035)
#define GETRANDOMUSER_GAME		0x00000000	//游戏中的用户
#define GETRANDOMUSER_ROOM		0x80000000	//房间在线用户
typedef struct tagGLREQGETRANDOMUSER
{
	GLREQHEADER header;

	DWORD	dwGameID;		//游戏
	DWORD	dwUserType;		//用户类型

	int		nMinGameCount;
	int		nMinTime;//秒
	int		nMemberRate;
}GLREQGETRANDOMUSER, *PGLREQGETRANDOMUSER;
typedef struct tagGLACKGETRANDOMUSER
{
	GLACKHEADER header;
	char	szUserName[GL_BUFLEN_USERNAME];
	char	szNickName[GL_BUFLEN_NICKNAME];		// 中文名
	DWORD	dwUserIP;	//用户IP
	long	timeGet;	//获得的时间
}GLACKGETRANDOMUSER, *PGLACKGETRANDOMUSER;

//游戏赠送，玩游戏时，当摸到某张牌时，得到一个“游戏泡泡”，可以参加点击泡泡获取奖品的活动
#define GLID_GETGAMEBUBBLE					(GLID_BASEGAMES+0x00000036)
//游戏赠送类型
#define BUBBLETYPE_GOLDEGG			1	//金蛋
#define BUBBLETYPE_SILVERNEGG		2	//银蛋
#define BUBBLETYPE_COPPEREGG		3	//铜蛋
#define BUBBLETYPE_NORMALEGG		4	//普通蛋
typedef struct tagGLREQGETGAMEBUBBLE
{
	GLREQHEADER header;
	DWORD	dwGameID;		//游戏
	DWORD	dwBubbleType;	//“游戏泡泡”类型
	char	szUserName[GL_BUFLEN_USERNAME];
	char	szNickName[GL_BUFLEN_NICKNAME];		// 中文名
	DWORD	dwUserIP;		//
	long	timeGet;		//获得的时间
}GLREQGETGAMEBUBBLE,*PGLREQGETGAMEBUBBLED;
//如果需要，可以将以下消息广播给游戏客户端
typedef struct tagGLREQGETGAMEBUBBLE2CLIENT//发送到客户端的赠送消息
{
	GLREQHEADER header;
	char	szUserName[GL_BUFLEN_USERNAME];
	DWORD	dwBubbleType;	//“游戏泡泡”类型
}GLREQGETGAMEBUBBLE2CLIENT,*PGLREQGETGAMEBUBBLE2CLIENT;
//wuqy end

typedef struct tagGLUSERNIPID
{
	char szUserName[GL_BUFLEN_USERNAME];
	char szNipID[GL_BUFLEN_NIPID];
}GLUSERNIPID, *PGLUSERNIPID;
// 通告所有游戏者的 nipID, 客户端收到这个消息后上报自己的设备信息
#define GLID_NIP_NOTIFYNIPID				(GLID_BASEGAMES+0x00000037)
typedef struct tagGLREQNIPNOTIFYNIPID
{
	GLHEADER header;
	int		cnCount;
	// 后面跟cnCount个GLUSERNIPID
}GLREQNIPNOTIFYNIPID, *PGLREQNIPNOTIFYNIPID;

// 用户的nip设备状态，这个消息通用于服务器和客户端，标识某人的nip设备状态
#define GLID_NIP_DEVICEINFO					(GLID_BASEGAMES+0x00000038)
typedef struct tagGLREQNIPDEVICEINFO
{
	GLREQHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];	// 在服务器收到的消息中，如果是空字符串标识username是发消息的人
	DWORD	dwDeviceInfo;					// 0标识没有任何设备 &0x00000001标识有音频可用 &0x00000002表示有设备可用
}GLREQNIPDEVICEINFO, *PGLREQNIPDEVICEINFO;

// 请求对方进行nip音视频
#define GLID_NIP_INVITE						(GLID_BASEGAMES+0x00000039)
typedef struct tagGLREQNIPINVITE
{
	GLREQHEADER header;
	USHORT bInviteAudio;					// 邀请音频。
	USHORT bInviteVideo;					// 邀请视频。
} GLREQNIPINVITE, *PGLREQNIPINVITE;
// 返回消息GLACKHEADR
// dwResult 0=失败 1＝对方接受邀请， 2＝对方拒绝邀请 3=对方未登录 4=不能邀请自己。

/*// 取消对话。
#define GLID_NIP_CANCEL						(GLID_BASEGAMES+0x0000003A)
typedef struct tagGLREQNIPCANCEL
{
	GLHEADER header;
	DWORD dwReason;							// 原因，0 - 未知原因，1 - 超时， 2 - 对方已经注销。
} GLREQNIPCANCEL, *PGLREQNIPCANCEL;
#define NIP_CANCEL_UNKNOWN			0		// 未知原因。
#define NIP_CANCEL_TIMEOUT			1		// 超时。
#define NIP_CANCEL_LOGOUT			2		// 对方已经注销。

// 注销。
#define GLID_NIP_LOGOUT						(GLID_BASEGAMES+0x0000003B)
typedef struct tagGLREQNIPLOGOUT
{
	GLREQHEADER header;
}GLREQNIPLOGOUT, *PGLREQNIPLOGOUT;*/

// 
#define GLID_CLIENTSETUP					(GLID_BASEGAMES+0x0000003A)
// 服务器发给客户端下面的消息后，客户端象服务器报告用户的客户端配置选项，room报大厅的，游戏客户端报游戏客户端的
typedef struct tagGLREQCLIENTSETUP
{
	GLREQHEADER header;
}GLREQCLIENTSETUP, *PGLREQCLIENTSETUP;
// 客户端返回下面的消息给服务器
typedef struct tagGLACKCLIENTSETUP
{
	GLACKHEADER header;
	DWORD dwLength;
	DWORD dwVersion;	// 客户端的版本号
	// 后面跟dwLength字节长的数据，表示客户端的设置
}GLACKCLIENTSETUP, *PGLACKCLIENTSETUP;

// 游戏豆不够了，必须兑换游戏豆，这个消息发给大厅或游戏客户端
// 大厅直接提示兑换
// 游戏中提示兑换，如果不兑换要结束游戏
// 可充值游戏豆游戏也用这个消息 wangym 2005.7.15
#define GLID_NEEDEXCHANGCOIN				(GLID_BASEGAMES+0x0000003B)
typedef struct tagGLREQNEEDEXCHANGECOIN
{
	GLREQHEADER header;
	DWORD	dwMinCoin;			// 最少兑换这么多
	DWORD	dwExchangeRate;		// 当前的兑换率 100个财富值买多少个游戏豆
	// 后面跟 \0 结尾提示字符串
}GLREQNEEDEXCHANGECOIN, *PGLREQNEEDEXCHANGECOIN;

// 客户端发到游戏服务器的兑换游戏豆的消息
#define GLID_GAMEEXCHANGECOIN				(GLID_BASEGAMES+0x0000003C)
typedef struct tagGLREQGAMEEXCHANGECOIN
{
	GLREQHEADER header;
	DWORD dwCoin;				// 要兑换多少个游戏豆，首位表示是游戏豆不够的情况下服务器强制兑换的
}GLREQGAMEEXCHANGECOIN, *PGLREQGAMEEXCHANGECOIN;
// 游戏服务器返回给大厅或游戏客户端下面的消息，如果兑换成功，在游戏中还要广播给其他人
typedef struct tagGLACKGAMEEXCHANGECOIN
{
	GLACKHEADER header;	// header.dwResult值
						// 0=不允许兑换
						// 1=成功，必须用下面的dwCoin和dwMoney更新本地的数据
						// 2=财富值不够，必须用下面的dwCoin和dwMoney更新本地的数据
						// 3=服务器忙，稍后再试，一般是dbservice忙
						// 4=必须兑换最少dwCoin个币，这是防止用户改消息的
						// 5=正在游戏，不允许在这里兑换游戏豆
	char szUserName[GL_BUFLEN_USERNAME];	// 是这个人的值有变化，加这个主要为了更新其他人的显示数据
	// 当header.dwResult=1或2时，下面两个值是有用的，用来更新客户端显示的数据
	DWORD dwCoin;				// 当前拥有的游戏豆
	DWORD dwMoney;				// 当前拥有的财富值
}GLACKGAMEEXCHANGECOIN, *PGLACKGAMEEXCHANGECOIN;

// 客户端刚进入时发给客户端游戏豆的兑换率，让客户端可以自由兑换
#define GLID_GAMECOINEXCHANGERATE			(GLID_BASEGAMES+0x0000003D)
typedef struct tagGLREQGAMECOINEXCHANGERATE
{
	GLREQHEADER header;
	DWORD dwExchangeRate;		// 当前的兑换率 100个财富值买多少个游戏豆
	//后面跟\0结束的字符串的提示信息 zy add 2005.10.17
}GLREQGAMECOINEXCHANGERATE, *PGLREQGAMECOINEXCHANGERATE;

// 让客户端更新显示的游戏豆，一般用户的游戏豆在服务器和客户端显示不同步时用这个消息
#define GLID_GAMECOINCHG					(GLID_BASEGAMES+0x0000003E)
typedef struct tagGLREQGAMECOINCHG
{
	GLREQHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];
	DWORD dwCoin;	// 更新后的游戏豆
}GLREQGAMECOINCHG, *PGLREQGAMECOINCHG;

// 服务器收到这个消息后统计用户的客户端设置
#define GLID_STATSETUP						(GLID_BASEGAMES+0x0000003F)
// 请求发GLREQHEADER就行
// 回复的GLACKHEADER dwResult高WORD表示大厅的人数，低WORD表示游戏客户端的人数

// 服务器收到这个消息后统计用户网速 wym 2005.5.12
#define GLID_STATNETSPEED					(GLID_BASEGAMES+0x00000040)
// 请求发GLREQHEADER就行
// 回复的GLACKHEADER dwResult表示参与统计的人数

//{ 游戏豆充值相关 wangym 2005.7.15
// 服务器提示客户端必须充值游戏豆，大厅和游戏客户端都用这个消息
#define GLID_NEEDCHARGEGAMECOIN				(GLID_BASEGAMES+0x00000041)


// 客户端发到服务器的游戏豆充值消息 大厅和游戏客户端相同
#define GLID_CHARGEGAMECOIN					(GLID_BASEGAMES+0x00000042)

// 客户端请求消息使用 GLREQHEADER 消息，后跟验证码
#define GLREQCHARGEGAMECOIN GLREQHEADER
#define PGLREQCHARGEGAMECOIN PGLREQHEADER


//外包游戏的消息ID wuqy add 2005.10.20
#define GLID_OURSOURCEGAME					(GLID_BASEGAMES+0x00000043)

//游戏客户端刚进入时发送他的 财富值/联众币 等 给他 wangym 2005.12.8
#define GLID_USERBASEINFO					(GLID_BASEGAMES+0x00000044)
typedef struct tagUSERBASEINFO
{
	char szUserName[GL_BUFLEN_USERNAME];
	DWORD dwMoney;	//财富值
	DWORD dwCoin;	//联众币
	DWORD dwReserve1;	//保留1
	DWORD dwReserve2;	//保留2
	DWORD dwReserve3;	//保留3
	DWORD dwReserve4;	//保留4
}USERBASEINFO, *PUSERBASEINFO;
typedef struct tagGLREQUSERBASEINFO
{
	GLREQHEADER header;
	USERBASEINFO ubi;
}GLREQUSERBASEINFO, *PGLREQUSERBASEINFO;

//用户投诉花费,在客户端登录时/进入房间时通知
#define GLID_GAMEINDICTCOST					(GLID_BASEGAMES+0x00000045)
typedef struct tagGAMEINDICTCOST
{
	GLREQHEADER header;
	DWORD	dwIndictCostM;	//会员投诉费用
	DWORD	dwIndictCostF;	//非会员投诉费用
	DWORD   dwReserved;		//保留字段。
	DWORD   dwReasonNum;	//下发的原因数量,后面跟多个原因字符串,\0分隔
}GAMEINDICTCOST,*PGAMEINDICTCOST;

//检测服务器获得此服务系统状态
#define GLID_SERVICESYSINFO					(GLID_BASEGAMES+0x00000046)
//请求 GLREQHEADER
//回馈
typedef struct tagSERVICESYSINFO
{
	GLACKHEADER header;
	DWORD		dwSockets;
	DWORD		dwOgMem;
	DWORD		dwAllMem;
	DWORD		dwTotalPhys;
	int			cnOgProc;
	int			cnAllProc;
	int			cnOgThrd;
	int			cnAllThrd;
	int			cnOgHandle;
	int			cnAllHandle;
	DWORD		dwNumberOfProcessors;
	LONGLONG	llOgUserTime;
	LONGLONG	llOgKernelTime;	
	LONGLONG	llotUserTime;
	LONGLONG	llotKernelTime;
	LONGLONG	llIdleUserTime;
	LONGLONG	llIdleKernelTime;
	LONGLONG	llAllTime;
	int			cnFailCount;
	int			cnErrType;
	DWORD		dwErrStartTime;
	int			cnThisThread;
	int			cnThisHandle;
	int			cnThisMemoryKB;
	LONGLONG	llThisTime;
}SERVICESYSINFO,*PSERVICESYSINFO;


// 反外挂服务器的IP地址列表
/// 这个消息是在一局游戏开始时发送给所有用户，或者当旁观者开始旁观，或者断线续玩回来时，服务器发送给客户端的。
/// 它告诉客户端当前可用的反外挂服务器的IP地址有哪些。
/// 客户端在收到这个消息之后，随机的选择这些服务器中的几个来初始化反外挂系统（当使用一个IP初始化失败时再选择
/// 使用另外一个IP地址）。
/// 客户端在收到这个消息之后，就可以开始初始化反外挂系统了。收到这个消息本身也就预示着需要客户端加载反外挂系统。
#define GLID_GUARDSVRLIST					( GLID_BASEGAMES + 0x00000047)
// server->client
typedef struct tagGLReqGuardSvrList
{
	GLREQHEADER header ;
	int nSize ;				// GLREQGUARDSVRLIST结构的大小，客户端应该根据这个大小来决定服务器IP信息的开始位置
	int nCount ;			// 这个结构后续跟的服务器IP信息个数，每个信息是一个SVRINFO结构（glbase05.h中定义）
} GLREQGUARDSVRLIST , *PGLREQGUARDSVRLIST ;

//服务器下发给客户端的皮肤配置信息(按lijun换肤协议添加) wuqy add 2006.11.09
#define GLID_SENDSKININFO					( GLID_BASEGAMES + 0x00000048)
// server->client
typedef struct tagGLREQSENDSKININFO
{
	GLREQHEADER stHeader;
	DWORD	    dwDataLen;//后跟字符串长度 + 2(即:strlen() + 2)	，这里加2（最后两个字符都是0）的原因在于方便客户端把这个信息写到ini文件中去
}GLREQSENDSKININFO,*PGLREQSENDSKININFO;
//游戏服务器的从GameSkin.ini配置文件中属于自己游戏GameID的数据,把N个皮肤方案发送给客户端.
//后跟的一个字符串,以0结尾,数据如下（截止到2006.11.10）:每条皮肤之间换行
// skin1=是否使用这个皮肤,皮肤标志名,皮肤ID,时间段,皮肤包名,皮肤版本,皮肤内容
// skin2=是否使用这个皮肤,皮肤标志名,皮肤ID,时间段,皮肤包名,皮肤版本,皮肤内容
// 其中：
// 0.是否使用这个皮肤取值为0或者1
// 1.皮肤标志名和皮肤ID不能超过32字符
// 2.皮肤ID同时也是子目录名
// 3.时间段格式为：
//   yyyy.mm.dd hh:mm - yyyy.mm.dd hh:mm 或者 yyyy.mm.dd - yyyy.mm.dd & hh:mm - hh:mm
//   分别表示：从某年某月某日某时某分到某年某月某日某时某分，或者从某年某月某日到某年某月某日，每天从某时某分到某时某分
// 4.皮肤包名和皮肤版本会传递给大厅供下载使用
// 5.皮肤内容是按位使用的，目前含义是：
//   bit0－1表示包含客户端皮肤，0表示不包含客户端皮肤
//   bit1－1表示包含邬启友的基类的对话框、边框的皮肤，0表示不包括这样的皮肤
//由客户端基类来解析这个字符串.

//tanglong add 2007.01.19
//服务器下发给大厅和客户端的快购弹出框信息 
#define GLID_SENDQUICKBUY					( GLID_BASEGAMES + 0x00000049)
// server->client


 
// 通知大厅下载文件的WM_COPYDATA消息结构
// WM_COPYDATA消息的pCopyDataStruct->dwData定义
#define COPYDATA_DWDATA_DOWNLOAD	0xFFF03001	//游戏下载请求
typedef struct tagDOWNLOADPACKET
{
	char szPacketName[GL_BUFLEN_GAMENAME];	// 包的名字，用于大厅匹配具体的下载文件
	DWORD dwVersion;	// 包的版本号
	DWORD dwReserve;
}DOWNLOADPACKET,*PDOWNLOADPACKET;

//wangcheng yxjz
#define GLID_REMOVEUSER    ( GLID_BASEGAMES + 0x00000050)
//有用户离开时,发送该消息
typedef struct tagRemoveUser
{
	GLREQHEADER stHeader;
	int			nSeat;
	char		szUserName[GL_BUFLEN_USERNAME];
}REMOVEUSER,*PREMOVEUSER;
#endif	// __GLGAMESPROTOCOL_H__

