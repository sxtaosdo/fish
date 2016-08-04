#ifndef __GLROOM_H__
#define __GLROOM_H__

#define GL_ROOMVER_LOGINONCE			0x02060004	//解决了一站登录的大厅的版本号 wangym 2005.11.7

#define GL_DISLIKE_ESCAPE				1
#define GL_DISLIKE_ENEMY				2
#define GL_DISLIKE_NETSPEED				3
#define GL_DISLIKE_OTHER				4
#define GL_DISLIKE_SCORE				5
//DYF.2003.03.31.Begin
//增加只与会员玩功能
#define GL_DISLIKE_NOFREE				6
//DYF.2003.03.31.End
#define GL_DISLIKE_KICKBYTABLELEADER	8
#define GL_DISLIKE_KICKBYMASTER			16
#define GL_DISLIKE_CHECK				32
#define GL_DISLIKE_MONEY				33//财富值
#define GL_DISLIKE_WINRATE				34//胜率


//---------------------------------------------------------------------------
//	比赛类型
//---------------------------------------------------------------------------
#define	GL_MATCHTYPE_FREE				0	//选手自己选择座位，自己找对手
#define	GL_MATCHTYPE_AUTOFREE			1	//选手同意开始比赛，由服务器分配座位
#define	GL_MATCHTYPE_AUTO				2	//服务器随机给选手分配座位
#define	GL_MATCHTYPE_FIX				3	//由组织者规定对手及座位情况的比赛
#define	GL_MATCHTYPE_ORDER				4	//根据选手成绩的排名，第一名和最后一名进行比赛
#define	GL_MATCHTYPE_SWISS				5	//根据选手成绩的排名，第一名和最后一名进行比赛

#define	GL_MATCHTYPE_MIN				0	//比赛类型最小值
#define	GL_MATCHTYPE_MAX				5	//比赛类型最大值

//---------------------------------------------------------------------------
//	比赛选手的状态GL_MATCHPLAYERSTATUS_NOTMATCHED的扩展
//---------------------------------------------------------------------------
#define	GL_NEWMATCHPLAYERSTATUS_NOTMATCHED		0x10	//轮空
#define	GL_NEWMATCHPLAYERSTATUS_MATCHED			0x20	//已经结束，但没有办法区分详细的状况
#define	GL_NEWMATCHPLAYERSTATUS_DELAY			0x30	//超时弃权
#define	GL_NEWMATCHPLAYERSTATUS_ESCAPE			0x40	//逃跑
#define	GL_NEWMATCHPLAYERSTATUS_WIN				0x50	//赢了
#define	GL_NEWMATCHPLAYERSTATUS_LOSS			0x60	//输了
#define	GL_NEWMATCHPLAYERSTATUS_DRAW			0x70	//和了
#define	GL_NEWMATCHPLAYERSTATUS_CLOSE			0x80	//封存，由裁判仲裁

//---------------------------------------------------------------------------
//	当前轮比赛状态
//---------------------------------------------------------------------------
#define	GL_STAGESTATUS_NOTSTART			0	//未开始
#define	GL_STAGESTATUS_ROOMCREATED		1	//比赛游戏室已经创建
#define	GL_STAGESTATUS_DOING			2	//正在比赛期间
#define	GL_STAGESTATUS_DELAY			3	//已经超过游戏启动的时间了
#define	GL_STAGESTATUS_ROOMNOTDELETED	4	//比赛已经结束，但比赛游戏室还未删除
#define	GL_STAGESTATUS_DONE				5	//比赛已经结束，游戏室也已经被删除了

//---------------------------------------------------------------------------
//wuqy2001-10-15报名房间状态
//---------------------------------------------------------------------------
#define GL_SIGNROOMSTATUS_NOTSTART		0	//报名房间，报名时间没有到
#define GL_SIGNROOMSTATUS_DOING			1	//报名房间，正在报名
#define GL_SIGNROOMSTATUS_OVER			2	//报名房间，报名结束
#define GL_SIGNROOMSTATUS_DELETED		3	//报名房间，已经被删除

//---------------------------------------------------------------------------
//wuqy2002-3-6一副牌或一盘棋结束后的下一步操作
//---------------------------------------------------------------------------
#define GL_MATCHHANDOVER_CONTINUEGAME	0	//继续打下一副牌或再下一盘棋
#define GL_MATCHHANDOVER_STOPGAME		1	//胜负已经决出，结束这一桌游戏

//---------------------------------------------------------------------------
//	游戏室类型
//---------------------------------------------------------------------------
#define GL_ROOMTYPE_SYSTEM				0	//普通游戏室，系统生成
#define	GL_ROOMTYPE_SHOW				1	//演示游戏室，只用来观赏
#define	GL_ROOMTYPE_MATCH				2	//比赛游戏室
#define GL_ROOMTYPE_USERDEFINE			3	//普通游戏室，用户创建
#define GL_ROOMTYPE_SINGLEPLAYER		4	//支持正在游戏的桌子也能坐到空椅子上的游戏室
#define	GL_ROOMTYPE_HIDENAMEMATCH		5	//隐名比赛游戏室
#define	GL_ROOMTYPE_NEWGAMEMODE			6	//新游戏机制房间


//---------------------------------------------------------------------------
//	游戏桌的状态(组合)
//---------------------------------------------------------------------------
#define	GL_MATCHTABLEFLAG_MATCHED		1	//已经结束
#define	GL_MATCHTABLEFLAG_WATCHABLE		2	//可以旁观

//---------------------------------------------------------------------------
//	比赛选手的状态
//---------------------------------------------------------------------------
#define	GL_MATCHPLAYERSTATUS_NOTPLAYER		0	//不是比赛选手
#define	GL_MATCHPLAYERSTATUS_NOMATCH		1	//轮空
#define	GL_MATCHPLAYERSTATUS_NOTMATCHED		2	//轮空
#define	GL_MATCHPLAYERSTATUS_NOTTHISROOM	3	//不是这个游戏室的选手
#define	GL_MATCHPLAYERSTATUS_MATCHED		4	//已经结束，但没有办法区分详细的状况
#define	GL_MATCHPLAYERSTATUS_DELAY			5	//超时弃权
#define	GL_MATCHPLAYERSTATUS_ESCAPE			6	//逃跑
#define	GL_MATCHPLAYERSTATUS_WIN			7	//赢了
#define	GL_MATCHPLAYERSTATUS_LOSS			8	//输了
#define	GL_MATCHPLAYERSTATUS_DRAW			9	//和了
#define	GL_MATCHPLAYERSTATUS_CLOSE			10	//封存，由裁判仲裁
#define	GL_MATCHPLAYERSTATUS_NOTPLAYER_NOPROMPT		11	//不是比赛选手(客户端不给提示，由服务器给提示) wuqy add 2005.8.26



//--------------------------------------------------------------------------
//	多人(大于3人)比赛选手的状态
//---------------------------------------------------------------------------
#define	GL_MATCHPLAYERSTATUS_MULTIPESCAPE			0	//逃跑
#define	GL_MATCHPLAYERSTATUS_MULTIPFIRST			1	//第1名
#define	GL_MATCHPLAYERSTATUS_MULTIPSECOND			2	//第2名
#define	GL_MATCHPLAYERSTATUS_MULTIPTHIRD			3	//第3名
#define	GL_MATCHPLAYERSTATUS_MULTIPFOUR				4	//第4名
#define	GL_MATCHPLAYERSTATUS_MULTIPFIFTH			5	//第5名
#define	GL_MATCHPLAYERSTATUS_MULTIPSIXTH			6	//第6名
#define	GL_MATCHPLAYERSTATUS_MULTIPSEVEN			7	//第7名
#define	GL_MATCHPLAYERSTATUS_MULTIPEIGHTH			8	//第8名


//--------------------------------------------------------------------------
//	比赛计分类型
//---------------------------------------------------------------------------
#define GL_MATCHSCORETYPE_1							1   //4人游戏有并列取平均分 zy add 2006.3.1（竞技麻将）
#define GL_MATCHSCORETYPE_2							2   //4人游戏根据小分正负分别计分,若有小分并列，取平均分 zy add 2006.7.4（飞行棋，大众麻将）
#define GL_MATCHSCORETYPE_3							3   //3人游戏有并列取平均分，并比较断线人、非断线人的小分计算各人的成绩 zy add 2006.7.13（挖坑）
#define GL_MATCHSCORETYPE_4							4   //5人游戏有并列取平均分 zy add 2006.8.24 (保皇)


//---------------------------------------------------------------------------
//	用户类型
//---------------------------------------------------------------------------
#define GL_USERTYPEFLAG_SELF			0x01		//自己
#define	GL_USERTYPEFLAG_SUPER			0x02		//特权用户
#define	GL_USERTYPEFLAG_FRIEND			0x80		//朋友
#define	GL_USERTYPEFLAG_ENEMY			0x40		//不受欢迎
#define	GL_USERTYPEFLAG_FACTION			0x20		//帮派
#define	GL_USERTYPEFLAG_HONGUEST		0x08		//嘉宾
#define GL_USERTYPEFLAG_PARTNER			0x10		//搭档

#define GL_USERTYPEFLAG_HAND			0x10
#define GL_USERTYPEFLAG_MIC				0x04

#define GL_PRIVILEGE_CORE				0
#define GL_PRIVILEGE_SETUSER			5
#define GL_PRIVILEGE_PASSWORD			10

#define	GL_PRIVILEGE_KICKUSER			70
#define GL_PRIVILEGE_SUPER				70

#define GL_PRIVILEGE_MASTERSTART				0
#define GL_PRIVILEGE_MASTEREND					70	

#define GL_PRIVILEGE_MATCHMASTER				11
#define GL_PRIVILEGE_MASTER						16
#define GL_PRIVILEGE_GOODUMPIREHEAD				21
#define GL_PRIVILEGE_UMPIREHEAD					22
#define GL_PRIVILEGE_GOODMASTER					23
#define GL_PRIVILEGE_ONWATCHGROUPHEAD			24
#define GL_PRIVILEGE_GOODMASTERFOREVER			28	//终身优秀室主	// DYF 2004.05.08
#define GL_PRIVILEGE_GOODMASTER1				29
#define GL_PRIVILEGE_ONWATCHCLASSHEAD			30
#define GL_PRIVILEGE_GOODUMPIRE					33
#define GL_PRIVILEGE_ASSISTANTGOODUMPIRE		34
#define GL_PRIVILEGE_GOODUMPIRE1				37
#define GL_PRIVILEGE_STAIRUMPIRE				38
#define GL_PRIVILEGE_GOODUMPIRE2				41
#define GL_PRIVILEGE_BIVALENTUMPIRE				42
#define GL_PRIVILEGE_THIRDCLASSUMPIRE			45
#define GL_PRIVILEGE_GOODMASTER2				48
#define GL_PRIVILEGE_INDUEFORMMASTER			49

#define GL_PRIVILEGE_COMPERE					51		//主持人 Add by DYF 2004/08/24
#define GL_PRIVILEGE_NOVICIATE					52		//见习
#define GL_PRIVILEGE_TEACHER					56		//讲师 Add by DYF 2004/08/24
#define GL_PRIVILEGE_LGSHOUTER					60		//仅可以使用lgshout命令的权限 add by wangning 09105
#define GL_PRIVILEGE_CHECKREFRESHLOW			70		//不检测刷屏的最低权限

#define GL_PRIVILEGE_GUESTSTART					71		//嘉宾?
#define GL_PRIVILEGE_GUESTEND					80		//嘉宾?

#define GL_PRIVILEGE_GUEST						71		//嘉宾
//#define GL_PRIVILEGE_?						72		//职业桥牌手
//#define GL_PRIVILEGE_?						73		//职业围棋手
//#define GL_PRIVILEGE_?						74		//职业五子棋手
//#define GL_PRIVILEGE_?						75		//职业国际象棋手
#define GL_PRIVILEGE_CHESSCARDGUEST				76		//职业中国象棋手
#define GL_PRIVILEGE_LOVER						77		//联众情侣(联众有情)	//DYF 2004.05.18
#define GL_PRIVILEGE_FORLIFECREDIT				78		//终身荣誉
#define GL_PRIVILEGE_EXCELLENCECONTRIBUTE		79		//卓越贡献
#define GL_PRIVILEGE_ESPECIALLYCONTRIBUTE		80		//特殊贡献

#define GL_PRIVILEGE_NORMALSTART				81		//特殊标记用户
#define GL_PRIVILEGE_NORMALEND					198		//特殊标记用户

//----------------------------------------------------------------
//	新增级别界定，主要用于显示不同图标81--198
//----------------------------------------------------------------
#define GL_PRIVILEGE_GUEST_GOODBBSEDITOR		81
#define GL_PRIVILEGE_GUEST_DIAMONDBBSEDITOR		82
#define GL_PRIVILEGE_GUEST_GOODBBSEDITOR1		83
#define GL_PRIVILEGE_GUEST_GOLDBBSEDITOR		84
#define GL_PRIVILEGE_GUEST_GOODBBSEDITOR2		85
#define GL_PRIVILEGE_GUEST_SILVERBBSEDITOR		86
#define GL_PRIVILEGE_GUEST_GOODBBSEDITOR3		87
#define GL_PRIVILEGE_GUEST_BBSEDITOR			88
#define GL_PRIVILEGE_GUEST_OURGAMEHERO			92
#define GL_PRIVILEGE_GUEST_OURGAMEBIGERRANTRY	93
#define GL_PRIVILEGE_GUEST_OURGAMEERRANTRY		94
#define GL_PRIVILEGE_GUEST_OURGAMEHERO1			95
#define GL_PRIVILEGE_GUEST_DUNPAI				100//荣誉质检员//shil.2003.9.10
#define GL_PRIVILEGE_GUEST_NEWSTAR				101
#define GL_PRIVILEGE_GUEST_SHANDIAN				105//优秀闪客//shil.2003.9.10
#define GL_PRIVILEGE_GUEST_GOODAUTHOR			106
#define GL_PRIVILEGE_GUEST_COOPERATEASSOCIATE	111
#define GL_PRIVILEGE_GUEST_CRYSTALEX			120 //把164显示调到120  (10大门派令持有者)
#define GL_PRIVILEGE_GUEST_ZZL					121	//至尊令wangcheng 2005.2.3
#define GL_PRIVILEGE_GUEST_TZJ					122	//天子剑wangcheng 2005.2.3
#define GL_PRIVILEGE_GUEST_WZL					123	//王者令wangcheng 2005.2.3
#define GL_PRIVILEGE_GUEST_KMSH					124	//孔明扇wangcheng 2005.2.3
#define GL_PRIVILEGE_GUEST_ZHL					125	//诸侯令wangcheng 2005.2.3
#define GL_PRIVILEGE_GUEST_ZYF					128	//忠义符wangcheng 2005.2.3 wangcheng 2005.3.14 客服让从126改成128
#define GL_PRIVILEGE_GUEST_TSL					127	//太守令wangcheng 2005.2.3
#define GL_PRIVILEGE_GUEST_SWJ					126	//苏武符wangcheng 2005.2.3 wangcheng 2005.3.14 客服让从128改成126
#define GL_PRIVILEGE_GUEST_TGYH					150	//铁杆用户wangcheng 2005.3.3
#define GL_PRIVILEGE_GUEST_ROSE2				155 //玫瑰城主//shil.2003.9.10
#define GL_PRIVILEGE_GUEST_ROSE3				156 //玫瑰天使//shil.2003.9.10
#define GL_PRIVILEGE_GUEST_MONEYHOME			157	//金融@家之星		// DYF 2004.08.10
#define GL_PRIVILEGE_GUEST_GROUP				158 //江湖令//wangch.2004.1.7
#define GL_PRIVILEGE_GUEST_OVERFLOW				159 //超值令//wangch.2004.1.7
#define GL_PRIVILEGE_GUEST_GKEY					160 //金钥匙//wangch.2004.1.7
#define GL_PRIVILEGE_GUEST_ROSE5				161 //火热玫瑰//shil.2003.9.10
#define GL_PRIVILEGE_GUEST_CRYSTAL				164	//10大门派令持有者
#define GL_PRIVILEGE_GUEST_EXTEND				167	//江湖超值礼包
#define GL_PRIVILEGE_JHLP						170	//江湖令牌
#define GL_PRIVILEGE_GUEST_XXL					171 //新秀令//wangcheng 2005.2.3
#define GL_PRIVILEGE_LORDTY						177 //斗地主功勋赛退役 2005.6.30
#define GL_PRIVILEGE_LORDJC						178 //斗地主功勋赛金锄 2005.6.30
#define GL_PRIVILEGE_LORDYC						179 //斗地主功勋赛银锄 2005.6.30
#define GL_PRIVILEGE_GUEST_RICH0				180 //短信大富翁至尊门派//shil.2003.9.10
#define GL_PRIVILEGE_GUEST_RICH1				181 //短信大富翁至尊王者//shil.2003.9.10
#define GL_PRIVILEGE_GUEST_RICH2				182	//短信大富翁超级富豪//shil.2003.9.10
#define GL_PRIVILEGE_GUEST_RICH3				183 //短信大富翁财富英雄//shil.2003.9.10
#define GL_PRIVILEGE_ZHIHUAN_J					184	//金指环				// DYF 2004.04.23
#define GL_PRIVILEGE_ZHIHUAN_Y					185	//银指环				// DYF 2004.04.23
#define GL_PRIVILEGE_DIZHU						186	//武汉斗地主大赛冠军	// DYF 2004.05.18
#define GL_PRIVILEGE_SUPERSTAR					187	//超级幸运星			// wangcheng 2004.12.27
#define GL_PRIVILEGE_LOCKYSTAR_J				188	//无敌幸运星(金)		// DYF 2004.08.10
#define GL_PRIVILEGE_LOCKYSTAR_Y				189	//无敌幸运星(银)		// DYF 2004.08.10
#define GL_PRIVILEGE_JUNQI_BABY					190	//四国军棋宝贝		// DYF 2004.03.10
#define GL_PRIVILEGE_BRIDGE_TEAM				191	//桥牌队式赛参赛选手	// DYF 2004.03.19
#define GL_PRIVILEGE_BRIDGE_TWIN				192	//桥牌双人赛参赛选手	// DYF 2004.03.19
#define GL_PRIVILEGE_TET3						193	//梦幻俄罗斯			// wuqy 2004.12.07
#define GL_PRIVILEGE_JUNQI_1					194	//军棋网优秀工作人员	// wym 2003.11.24
#define GL_PRIVILEGE_JUNQI_2					195	//军棋网工作人员		// wym 2003.11.24
#define GL_PRIVILEGE_JUNQI_3					196	//擂台赛擂主			// wym 2003.11.24	
#define GL_PRIVILEGE_JUNQI_4					197	//功勋英雄				// wym 2003.11.24
#define GL_PRIVILEGE_GUEST_MATCH				198 //比赛报名后授予的权限（水晶）

#define GL_PRIVILEGE_NORMAL				199		//正常的用户

#define GL_PRIVILEGE_SPECIALSTART		200		//特殊处理
#define GL_PRIVILEGE_SPECIALEND			255		//

#define GL_PRIVILEGE_RECORD				230		//跟踪这个用户	chenzd	2001.7.13
#define GL_PRIVILEGE_DISABLESTART		240
#define GL_PRIVILEGE_DISABLEEND			254
#define GL_PRIVILEGE_DISABLE			254
#define GL_PRIVILEGE_DISABLENOPROMPT	253		//baoyq 2004.9.23,原来的GL_PRIVILEGE_DISABLENOTIP
#define GL_PRIVILEGE_DISABLEIP			252		//baoyq 2004.9.23,用户IP地址被禁止说话,是有提示的
#define GL_PRIVILEGE_NONE				255

//----------------------------------------------------------------
//	扩展图标256--511
//----------------------------------------------------------------
#define GL_PRIVILEGE_NEWICONSTART				256
#define GL_PRIVILEGE_NEWICONEND					4095


#define GL_RPIVILEGE_PRIORITYBEGIN		171		//申请优先开始级别
#define GL_RPIVILEGE_PRIORITYEND		180		//申请优先结束级别

#define	GL_CHECKUSER_EQUAL				0
#define	GL_CHECKUSER_HIGH				1
#define	GL_CHECKUSER_LOWE				2

#define	GL_LANGRSC_BASEMASTER			1000
#define	GL_LANGRSC_BASEMEMBER			2000

#define	GL_MEMBER_FREE					0
#define	GL_MEMBER_NORMAL				10
#define GL_MEMBER_MOBILE				11	// 移动用户，他们上来都是交费的
#define	GL_MEMBER_VIP					20
#define	GL_MEMBER_LIEFLONG				30
#define	GL_MEMBER_HONOR					40



typedef	union tagEXTENDFIELD
{
	char cContent;
	BYTE uchContent;
	WORD perContent;
	short unContent;
	WORD wContent;
	LONG lContent;
	DWORD dwContent;
	float fContent;
	char szContent[256];
} EXTENDFIELD, FAR *PEXTENDFIELD;

//---------------------------------------------------------------------------
//	用户信息结构
//---------------------------------------------------------------------------
typedef struct tagROOMPLAYERINFOEX
{
	char szUserName[GL_BUFLEN_USERNAME];				// 用户名
	char szNickName[GL_BUFLEN_NICKNAME];				// 呢称
	int nImage;											// 头像
	DWORD dwRank;										// 级别
	int nScore;										// 积分
	DWORD dwWins;										// 赢的局数
	DWORD dwLosses;										// 输的局数
	DWORD dwDraws;										// 平局数
	DWORD dwGameCount;									// 游戏次数
	int nBreakRate;										// 断线率
	DWORD dwMoney;										// 财富
	WORD wSpeed;										// 网速
	char szFaction[GL_BUFLEN_FACTION];					// 帮派
	BYTE uchMember;										// 会员
	BYTE uchPrivilege;									// 特权
	DWORD dwLanguage;									// 语言

	BYTE uchStatus;										// 用户状态
	WORD wTable;										// 桌号
	BYTE uchSeat;										// 座位号
	BOOL bTablePassword;								// 当前桌子是否有口令
	BOOL bReady;										// 是否已经准备好

	BYTE cUserType;										// 玩家属性，是否朋友和敌人, 0=什么都不是，1=朋友，2=敌人

	PEXTENDFIELD pExntendField;							// 扩展字段
} ROOMPLAYERINFOEX, FAR *PROOMPLAYERINFOEX;

typedef struct tagNEWROOMPLAYERINFOEX
{
	char szUserName[GL_BUFLEN_USERNAME];				// 用户名
	char szNickName[GL_BUFLEN_NICKNAME];				// 呢称
	int nImage;											// 头像
	DWORD dwRank;										// 级别
	int nScore;										// 积分
	DWORD dwWins;										// 赢的局数
	DWORD dwLosses;										// 输的局数
	DWORD dwDraws;										// 平局数
	DWORD dwGameCount;									// 游戏次数
	int nBreakRate;										// 断线率
	DWORD dwMoney;										// 财富
	WORD wSpeed;										// 网速
	char szFaction[GL_BUFLEN_FACTION];					// 帮派
	BYTE uchMember;										// 会员
	BYTE uchPrivilege;									// 特权
	DWORD dwLanguage;									// 语言

	BYTE uchStatus;										// 用户状态
	WORD wTable;										// 桌号
	BYTE uchSeat;										// 座位号
	BOOL bTablePassword;								// 当前桌子是否有口令
	BOOL bReady;										// 是否已经准备好

	BYTE cUserType;										// 玩家属性，是否朋友和敌人, 0=什么都不是，1=朋友，2=敌人

	PEXTENDFIELD pExntendField;							// 扩展字段
	BOOL bMobile;                                       //是否关联了手机
	WORD	*pwAvatarItems;								//用户当前的佩戴Avatar物品ID列表
	BYTE	bySex;										//用户性别
											//格式  wCount  wItemID ....  wItemID 
	LONGLONG	lDigitalID;					//数字id wuqy add 2005.3.8
} NEWROOMPLAYERINFOEX, FAR *PNEWROOMPLAYERINFOEX;

//byq 2002.9.27 游戏室扩展菜单回调函数(用来发送消息的)
typedef BOOL (WINAPI *PGLPLUGINCALLBACK)(void * pParam,const void *pMsg,void **pRecvMsg,DWORD dwWaitMsgID);
                         //回调函数定义
                         //参数含义:pParam为PGLPLUGINFUNC时传递的参数指针fParam
						 //pMsg为要发送的包
                         //pRecvMsg为需等待接收的包地址
						 //dwWaitMsgID为需等待的包消息ID
typedef void (WINAPI *PGLPLUGINFUNC)(HWND hMainWnd,void* SelfInfo,void *OtherInfo,LPCTSTR lParam,
									 PGLPLUGINCALLBACK  pFunc,void *fParam);
						//为主程序调用PlugIn函数
						//传递参数意义如下
						//hMainWnd为主窗口句柄   SelfInfo为自身的PNEWPLAYERINFOEX指针  
						//OtherInfo为点击对象的自身的PNEWPLAYERINFOEX指针   lParam为注册表中写入的一个串参数
						//pFunc为调用网络发送包回调函数地址   fParam为需传给pFunc回调函数的参数

//---------------------------------------------------------------------------
//	Login过程，IP和Port由GameList.ini文件指定
//---------------------------------------------------------------------------
#define	GLID_LOGIN						(GLID_BASEROOM+0x00000000)	//Login

#define GLBIT_LOGIN_SUCCESS				GLBIT_SUCCESS	// Login成功
#define GLBIT_LOGIN_SVRBUSY				0x00000002		// 服务器忙，提示用户稍候再试
#define GLBIT_LOGIN_INVALIDGAMEVERSION	0x00000003		// 需要新版本的游戏
#define GLBIT_LOGIN_EXPIRED				0x00000004		// 用户使用期限已满
#define GLBIT_LOGIN_TRIALEXPIRED		0x00000005		// 试用版到期，需要重新下载缴费版或缴费 wym 2003-8-5 
														// 具体应该如何做在返回GLACKLOGIN消息后面附加说明 
#define GLBIT_LOGIN_VERIFYFAIL			0x00000006		// 服务器二次认证失败，针对移动和杰讯手机收费，服务器二次认证用的 wym 2004.3.26
#define GLBIT_LOGIN_NOREGISTER			0x00000008		// 此游戏没有注册过//从代码中看应该是用户没有注册过,曾西发现此问题 chairmin 2009.02.20
#define GLBIT_LOGIN_NOLICENCE			0x00000009		// 未经联众授权的oem客户端 wym 2002-10-10
//---------------------------------------------------------------------------
//	GLBIT_LOGIN_USEREXIST仅仅当服务器被配置成无数据库版本时才会发生,
//	在Internet版本中, 当一个用户名已经在服务器中存在时, 服务器将杀死原来
//	存在的、有相同用户名的线程
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_USEREXIST			0X00000010		// 已经有一个相同名字的在此服务器中存在
#define GLBIT_LOGIN_INVALIDUSER			0X00000020		// 用户名或口令错误
#define GLBIT_LOGIN_USERNOTACTIVE		0X00000021		// 帐号没有激活（主要针对图游 wuqy add 2007.7.27）
//---------------------------------------------------------------------------
//	version >= 0x011e05ff
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_FULL				0x00000040		// 服务器人满
//---------------------------------------------------------------------------
//	version >= 0x011e08ff
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_INVALIDROOMVERSION	0x00000080
//---------------------------------------------------------------------------
//	2000.4.23新版大厅
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_CLOSED				0x00000100		// 这台机器已经被封闭，只能用其它机器上
//---------------------------------------------------------------------------
//	2001.11.21,byq限制某些IP非会员用户进入
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_NOTFREE				0x00000200		// 这台机器已经被封闭，只能用其它机器上
//---------------------------------------------------------------------------
//	2001.12.14,byq增加闭关修练
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_PAUSE				0x00000400		// 这台机器已经被封闭，只能用其它机器上
//---------------------------------------------------------------------------
//	2001.12.27,byq增加闭关修练
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_PROMPT				0x00000800		// 向用户提示信息，同时允许登录
#define GLBIT_LOGIN_PROMPTIMP			0x00000801		// 向用户提示很重要的信息（比如至尊靓号过期的提示），同时允许登录 wuqy add 2006.10.26
//---------------------------------------------------------------------------
//	2002.11.20,shil 进入服务器的时候game版本不对的时候可以去下载
//	version >= 0x0201000d
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_ROOMVERSIONTOOHIGH	0x00001001		// 大厅版本太高了
#define GLBIT_LOGIN_GAMEVERSIONTOOHIGH	0x00001002		// 游戏版本太高了
//---------------------------------------------------------------------------
//	baoyq 2004.12.17 为了ID保护时保护大厅登录添加,GLRegisterService根据大厅版本返回不同的消息
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_PROTECTLOGIN		0x00001003
#define GLBIT_LOGIN_INVALIDTICKET		0x00001004		// ticket验证失败 wym 2005.10.20
#define GLBIT_LOGIN_INVALIDTICKETTIME	0x00001005		// ticket验证失败,过了有效期,必须重新登陆 wym 2005.10.20
#define GLBIT_LOGIN_ONCEPROTECT			0x00001006		//用户有按次登录保护 wuqy 2006.9.15
#define GLBIT_LOGIN_GAMECLOSED			0x00001007		//该用户在特定游戏中被封闭 wuqy 2006.11.28
#define GLBIT_LOGIN_ABNORMALUSER		0x00001008		//异常用户，提示用户进行验证 chairmin 2008.5.6

//---------------------------------------------------------------------------
//	wuqy 2005.1.6 与加密狗登录相关的返回值
//---------------------------------------------------------------------------
#define GLBIT_LOGIN_MUSTSOFTDOG			0x00002001	//该登录用户已经和一个加密狗绑定，必须用户加密狗登录
#define GLBIT_LOGIN_SOFTDOGEXPIRED		0x00002002	//该加密狗已经过期，不能再用该加密狗登录，必须冲值或解除用户名绑定
#define GLBIT_LOGIN_SOFTDOGMD5ERROR		0x00002003	//客户加密狗端运算错误（可能是错误的加密狗）
#define GLBIT_LOGIN_SOFTDOGNOTBIND		0x00002004	//该用户没有绑定

//	Login过程，请求结构，注意前面部分必须与GLREQSVRLOGIN相同
typedef struct tagGLREQLOGIN
{
	GLREQHEADER header;
	DWORD dwGameID;										//游戏ID
	char szUserName[GL_BUFLEN_USERNAME];				//用户名
	char szPassword[GL_BUFLEN_PASSWORD];				//口令
	DWORD dwRegisterIP;									//用于校验RegisterServer是否合法
	DWORD dwMachineIDLo;
	DWORD dwMachineIDHi;
	// 如果是手机用户还会跟下面的信息 wym add 2003.8.14
	//三个0结尾字符串分别是:IMSI\0machineID\0PhoneNumber\0
	//如果哪一项没有也要保留该项的\0，原则是要么一个也不写，要么只要写了一项其他两项的\0就必须有
}GLREQLOGIN, *PGLREQLOGIN;

//大厅版本0x0201000C后用下面的消息了
typedef struct tagGLREQLOGINEX
{
	GLREQHEADER header;
	DWORD dwGameID;										//游戏ID
	char szUserName[GL_BUFLEN_USERNAME];				//用户名
	char szPassword[GL_BUFLEN_PASSWORD];				//口令
	DWORD dwRegisterIP;									//用于校验RegisterServer是否合法
	DWORD dwMachineIDLo;
	DWORD dwMachineIDHi;
	DWORD dwRoomEncrypt;               
}GLREQLOGINEX, *PGLREQLOGINEX;

//Login 代替老版本的 GLID_LOGIN
#define	GLID_ROOMLOGIN						(GLID_BASEROOM+0x00000030)	

//用ticket登录游戏服务器 2.6.0.4以后的版本用 wangym 2005.11.7
#define GLID_ROOMLOGIN2						(GLID_BASEROOM+0x00000031)
//登录消息修改如下 
typedef struct tagGLREQLOGINEX2
{
	GLREQHEADER header;
	DWORD dwGameID;										//游戏ID
	char szUserName[GL_BUFLEN_USERNAME];				//用户名
	//char szPassword[GL_BUFLEN_PASSWORD];				//口令
	char szTicket[GL_BUFLEN_TICKET];					//长效ticket
	DWORD dwRegisterIP;									//用于校验RegisterServer是否合法
	DWORD dwMachineIDLo;
	DWORD dwMachineIDHi;
	DWORD dwRoomEncrypt;
}GLREQLOGINEX2, *PGLREQLOGINEX2;
//回复消息还是GLACKLOGIN

#define GLBIT_LOGIN_ITEM_ENABLE		0x00000001		//服务器支持道具
#define GLBIT_LOGIN_WEBNOTIFY		0x00000002		//是否需要WEB通知，幸运点游戏兑换时会直接调用网页不走原有游戏豆兑换流程，网页需要判断dwGameCoinID来区别处理幸运点或者xx点
//	Login过程，应答结构
typedef struct tagGLACKLOGIN
{
	GLACKHEADER header;
	DWORD dwFreeDays;				// 剩余天数
	BOOL bFreeWatch;				
	DWORD dwLoginTime;
	DWORD dwMachineIDLo;
	DWORD dwMachineIDHi;
	DWORD dwServerVersion;			//当大厅或游戏的版本不对的时候，这里返回的是可以进入的大厅或游戏的版本
	DWORD dwFlags;					//新增标志双字，最低位被用来指定是否配置了支持道具，如果不支持客户端不调用道具控件，防止控件发消息出错 chairmin 2006.11.2
	DWORD dwGameCoinGameID;			//指定游戏豆的ID，在服务器ini中配置，如果没有配置此值为dwGameID
}GLACKLOGIN, *PGLACKLOGIN;
// 如果header.dwResult==GLBIT_LOGIN_TRIALEXPIRED,表明手机用户免费试用期已到，需要缴费或升级
// 在上面的消息后面附加下面的信息
/*
{
	char* pszPrompt;	// \0结尾的提示信息,没有提示也要写\0
	BYTE byType;		// 1==显示上面的提示后退出程序
						// 2==短信缴费，需要提示pszPrompt，用户确认后才能发短信
	char pszSmsAddress;	// 短信发到哪里
	char pszSms;		// 短信的业务编码
}
*/
//如果header.dwResult=GLBIT_LOGIN_VERIFYFAIL消息后面跟\0结尾的提示字符串

//---------------------------------------------------------------------------
//	读取RoomList过程，IP和Port由ServerList指定
//---------------------------------------------------------------------------
#define	GLID_READROOMLIST				(GLID_BASEROOM+0x00000002)	//RoomList

//---------------------------------------------------------------------------
//	读取RoomList请求结构，只要返回正常，只表明成功
//---------------------------------------------------------------------------
typedef struct tagGLREQREADROOMLIST
{
	GLREQHEADER header;
	DWORD dwGameID;
}GLREQREADROOMLIST, *PGLREQREADROOMLIST;

#define		GLBIT_SERVERFULL		2					// 人满为患

//---------------------------------------------------------------------------
//	读取RoomList返回结构，紧跟dwTotalRoom个BASEROOMINFO
//---------------------------------------------------------------------------
typedef struct tagGLACKREADROOMLIST
{
	GLACKHEADER header;
//---------------------------------------------------------------------------
//	原dwTotalRoom拆为两个变量，1.32之后有效
//---------------------------------------------------------------------------
	WORD wTotalRoom;									// 成功后发回的 Host 列表项个数
	WORD wLanguage;
}GLACKREADROOMLIST, *PGLACKREADROOMLIST;

//---------------------------------------------------------------------------
//	基本Room信息结构
//---------------------------------------------------------------------------
typedef struct tagBASEROOMINFO
{
	char szName[GL_BUFLEN_ROOMNAME];					// Room名称
	WORD bPassword;										// Room是否有口令
	WORD nType;
	WORD wPlayers;										// 该Room中有多少用户	
	WORD nRuler;
}BASEROOMINFO,FAR *PBASEROOMINFO;

//---------------------------------------------------------------------------
//	进入Default Room过程
//---------------------------------------------------------------------------
#define	GLID_ENTERDEFAULTROOM			(GLID_BASEROOM+0x00000003)
														// 进入Room
//定义进入房间标志位
#define GLBIT_ENTERROOM_FLAG_USEITEM	0x00000001		//使用道具进入人满房间

//---------------------------------------------------------------------------
//	进入Default Room过程，请求结构，返回内容与进入Room相同
//
//	1.EnterRoom(szRoomName)，如果成功则返回
//	2.搜索Room列表，分别调用EnterRoom，成功返回
//	3.所有尝试进入的Room都必须没有Password
//---------------------------------------------------------------------------
typedef struct tagGLREQENTERDEFAULTROOM
{
	GLREQHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];				// 用户名
	char szPassword[GL_BUFLEN_PASSWORD];				// 口令
	char szRoomName[GL_BUFLEN_ROOMNAME];				// 缺省的Room名，如果该Room不存在或有密码，则自动进入DefaultRoom
	DWORD dwFlags;										//标志双字，最低位指定是否使用道具进入；
														//用户点击游戏进入初次不自动使用道具，如果每个房间都人满，由客户端提示用户是否需要购买并使用道具，购买成功后指定此标志重进
														//当用户已进入服务器再点击人满房间时会自动使用道具，如果没有提示用户购买并使用
}GLREQENTERDEFAULTROOM, *PGLREQENTERDEFAULTROOM;

//---------------------------------------------------------------------------
//	进入Room过程
//---------------------------------------------------------------------------
#define	GLID_ENTERROOM					(GLID_BASEROOM+0x00000004)
														// 进入Room
#define GLBIT_ENTERROOM_SUCCESS			GLBIT_SUCCESS	// 成功
//---------------------------------------------------------------------------
//	以下三条错误信息仅用于进入Room
//---------------------------------------------------------------------------
#define GLBIT_ENTERROOM_INVALIDPASSWORD		0x00000002	// Password错误
#define GLBIT_ENTERROOM_ROOMFULL			0x00000004	// 房间人满
#define GLBIT_ENTERROOM_NOTEXIST			0x00000008	// 房间不存在
//进入房间时使用畅通无阻道具，增加错误信息码 chairmin 2006.10.16
#define GLBIT_ENTERROOM_ROOMFULL_TRUTH		0x00010000	//房间确实已满，已进入人数1.5倍，即使会员也没法进了
#define GLBIT_ENTERROOM_SCI_USEFAIL			0x00020000	//使用畅通无阻道具出错
#define GLBIT_ENTERROOM_SCI_NONE			0x00040000	//用户没有畅通无阻道具

//---------------------------------------------------------------------------
//	以下一条错误信息仅用于进入Default Room
//---------------------------------------------------------------------------
#define GLBIT_ENTERROOM_SERVERBUSY			0x00000010	// 服务器不能再创建ROOM了
//---------------------------------------------------------------------------
//	以下一条错误信息仅用于创建ROOM
//---------------------------------------------------------------------------
#define GLBIT_ENTERROOM_EXIST				0x00000020	// 想创建的ROOM已存在
#define GLBIT_ENTERROOM_CANNOTCREATE		0x00000040	
#define GLBIT_ENTERROOM_INVALIDROOMVERSION	0x00000080	
#define GLBIT_ENTERROOM_ROOMVERSIONTOOHIGH	0x10000080	
#define GLBIT_ENTERROOM_INVALIDGAMEVERSION	0x00000100	
#define GLBIT_ENTERROOM_GAMEVERSIONTOOHIGH	0x10000100	
#define GLBIT_ENTERROOM_INVALIDNETSPEED		0x00000200	
#define GLBIT_ENTERROOM_INVALIDBREAKRATE	0x00000400	
#define GLBIT_ENTERROOM_INVALIDMEMBER		0x00000800	
#define GLBIT_ENTERROOM_INVALIDRANK			0x00001000	
#define GLBIT_ENTERROOM_INVALIDSCORE		0x00002000	
#define GLBIT_ENTERROOM_INVALIDMONEY		0x00004000	
#define GLBIT_ENTERROOM_NOTSAMEFACTION		0x00008000	// 帮派不符合
#define GLBIT_ENTERROOM_INVALIDPRIVILEGE	0x00100000	// 标志不符合
#define GLBIT_ENTERROOM_LIMITFREEDAYS		0x00120000	//会员天数不符合条件
#define GLBIT_ENTERROOM_LIMITMEMBERRANK		0x00140000	//会员等级不符合条件
#define GLBIT_ENTERROOM_FAILED				0xffffffff	

//---------------------------------------------------------------------------
//	进入Room过程，请求结构
//
//	1.检查RoomName是否存在
//	2.检查Password是否正确
//	3.检查游戏室人数是否已满
//	4.如果用户已经在另一个游戏室了，则先从原来的Room退出
//	5.加入该用户，同时向已经在该游戏室内的用户发送新用户消息
//	6.返回进入游戏室成功消息，并发送当前游戏室目前的用户信息
//---------------------------------------------------------------------------
typedef struct tagGLREQENTERROOM
{
	GLREQHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];				// 用户名
	char szPassword[GL_BUFLEN_PASSWORD];				// 口令
	char szRoomName[GL_BUFLEN_ROOMNAME];				// Room名称
	char szRoomPassword[GL_BUFLEN_PASSWORD];			// Room口令
}GLREQENTERROOM, *PGLREQENTERROOM;

//---------------------------------------------------------------------------
//	Room结构
//---------------------------------------------------------------------------
typedef struct tagROOMINFO
{
	char szName[GL_BUFLEN_ROOMNAME];
	WORD bPassword;
	WORD nType;
	WORD wPlayers;
	WORD nRuler;
//---------------------------------------------------------------------------
//	比BASEROOMINFO增加的内容，一定请放在最后
//---------------------------------------------------------------------------
	DWORD dwMaxPlayersAndTables;						// 最大的人数限制
	char szChatIP[GL_BUFLEN_HOST];						// 聊天室的IP和Port
	WORD wChatPort;
	char szChatRoom[GL_BUFLEN_ROOMNAME];				// 聊天室名称
}ROOMINFO,FAR *PROOMINFO;

//---------------------------------------------------------------------------
//	1.进入Room过程，应答结构，如果成功，该结构后跟有wPlayers个PLAYERINFO结构
//	2.如果进入成功，返回的PlayerInfo表中包含本地用户自己的内容
//---------------------------------------------------------------------------
typedef struct tagGLACKENTERROOM
{
	GLACKHEADER header;
	ROOMINFO sRoomInfo;
}GLACKENTERROOM, *PGLACKENTERROOM;

//---------------------------------------------------------------------------
//	进入Room过程成功后，客户端要读取该Room的所有Player的信息
//	bao 2000.10.16改动:
//	1.针对游戏室版本1.32.0.255之后版本
//	2.原BOOL bReady改为int nMoney
//	3.原BYTE bTablePassword改为BYTE bTablePassword : 4,BYTE bReady : 4
//  zengxi 2006.05.11 改动:
//  1.增加dwGameCoin字段
//---------------------------------------------------------------------------
typedef struct tagPLAYERINFO
{
	char szUserName[GL_BUFLEN_USERNAME];				// 用户名
	char szNickName[GL_BUFLEN_NICKNAME];				// 呢称
	DWORD dwRank;										// Rank
	DWORD dwScore;										// 积分
	DWORD dwWins;										// 赢的局数
	DWORD dwLosses;										// 输的局数
	DWORD dwDraws;										// 平局数
	DWORD dwGameCount;									// 游戏次数
	DWORD dwBreakCount;									// 逃跑次数

	BYTE uchStatus;										// 用户状态
	BYTE uchMember;										// 会员
	WORD wTable;										// 桌号
	BYTE uchSeat;										// 座位号
	BYTE uchPrivilege;									// 特权
	int nMoney;											// 财富
	BYTE bTablePassword : 4;							// 当前桌子是否有口令
	BYTE bReady : 4;									// 是否已经准备好了
	BYTE cUserType;										// 玩家属性，是否朋友和敌人, 0=什么都不是，1=朋友，2=敌人
	WORD wSpeed;
	DWORD dwGameCoin;									// 游戏豆 zengxi 2006.05.15
}PLAYERINFO,FAR *PPLAYERINFO;

//---------------------------------------------------------------------------
//	进入sSignRoomM和MatchRoom过程成功后，客户端要读取该Room的所有Player的信息
//---------------------------------------------------------------------------
typedef struct tagMDPLAYERINFO
{

	DWORD dwMatchScore;									// 总积分
	DWORD dwSecondScore;								// 小分
//	DWORD dwPlayerWins;									// 赢的盘数(保留)
//	DWORD dwPlayerLosses;								// 输的盘数(保留)
//	DWORD dwPlayerDraws;								// 和的盘数(保留)
//	DWORD dwPlayerPlace;								//个人排名(保留)
	DWORD dwMatchCount;									//比赛场数
	DWORD dwFirstCount;									//先手次数

	//为团体赛时才显示，并包含有效值
	char szTeamName[GL_BUFLEN_USERNAME];//先定为20		// 队名
//	DWORD dwTeamScore;									// 队积分(保留)
//	DWORD dwTeamSecondScore;							// 队小分(保留)
	DWORD dwTeamWins;									// 赢的场次
	DWORD dwTeamLosses;									// 输的场次
	DWORD dwTeamDraws;									// 平的场次
	DWORD dwTeamPlace;									// 队排名

}MDPLAYERINFO,FAR *PMDPLAYERINFO;

//---------------------------------------------------------------------------
//	增加用户过程，增加用户过程一定是服务器调用的，因此没有请求结构
//---------------------------------------------------------------------------
#define	GLID_ADDPLAYER					(GLID_BASEROOM+0x00000005)

//---------------------------------------------------------------------------
//	增加用户应答
//---------------------------------------------------------------------------
typedef struct tagGLACKADDPLAYER
{
	GLACKHEADER header;
	PLAYERINFO sPlayerInfo;
}GLACKADDPLAYER, *PGLACKADDPLAYER;
//为了能够比较方便地在GLACKADDPLAYER消息后面添加帮派等信息,定义另一个结构
typedef struct tagGLACKADDPLAYEREX
{
	GLACKADDPLAYER ap;
	char szFactionDuty[GL_BUFLEN_FACTION+GL_BUFLEN_DUTY];

	//zhp add 2014/05/05
	char szRoleName[GL_BUFLEN_ROLENAME];				// 角色名

}GLACKADDPLAYEREX,*PGLACKADDPLAYEREX;

//---------------------------------------------------------------------------
//	删除用户过程，增加用户过程一定是服务器调用的，因此没有请求结构
//---------------------------------------------------------------------------
#define	GLID_DELETEPLAYER				(GLID_BASEROOM+0x00000006)

//---------------------------------------------------------------------------
//	删除用户应答
//---------------------------------------------------------------------------
typedef struct tagGLACKDELETEPLAYER
{
	GLACKHEADER header;
	char szName[GL_BUFLEN_USERNAME];
}GLACKDELETEPLAYER, *PGLACKDELETEPLAYER;

//---------------------------------------------------------------------------
//	改变用户状态过程
//---------------------------------------------------------------------------
#define	GLID_CHANGEPLAYERSTATUS			(GLID_BASEROOM+0x00000007)

//---------------------------------------------------------------------------
//	改变用户状态过程
//
//	1.判断状态的合法性
//	2.根据不同的状态进行不同的处理
//		1.Standing
//			1.当前状态必须为Waiting
//		2.Waiting
//			1.当前状态必须为Standing
//		3.Playing
//			1.无效，不能由客户端设置，只有在游戏开始时服务器端自动设置
//		4.Watching
//			1.当前状态必须为Standing
//			2.检查指定游戏桌是否正在游戏过程中
//			3.广播该用户处于Watching状态
//			4.给该用户发送GameStart消息
//---------------------------------------------------------------------------
typedef struct tagGLREQCHANGEPLAYERSTATUS
{
	GLREQHEADER header;

	WORD wStatus;										// 用户状态
	WORD wTable;										// 桌号
	WORD wSeat;											// 椅子号
	char szTablePassword[GL_BUFLEN_PASSWORD];			// 桌子的Password, 只有第一个用户才允许Password
}GLREQCHANGEPLAYERSTATUS, *PGLREQCHANGEPLAYERSTATUS;

//---------------------------------------------------------------------------
//	改变用户状态过程，应答结构
//---------------------------------------------------------------------------
typedef struct tagGLACKCHANGEPLAYERSTATUS
{
	GLACKHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];				// 用户名

	WORD wStatus;										// 用户状态
	WORD wTable;										// 桌号
	WORD wSeat;											// 椅子号

	BOOL bTablePassword;								// 当前桌子是否有口令
}GLACKCHANGEPLAYERSTATUS, *PGLACKCHANGEPLAYERSTATUS;

//---------------------------------------------------------------------------
//	启动游戏，没有请求消息，Room接收到该命令后执行下列动作：
//	1.改变该桌子上的用户状态为Playing
//	2.启动客户端程序
//---------------------------------------------------------------------------
#define	GLID_GAMESTART					(GLID_BASEROOM+0x00000008)

//---------------------------------------------------------------------------
//	客户端请求启动游戏
//
//	1.当前状态必须为Waiting状态
//	2.设置GameStart标志
//	3.如果该游戏桌的用户都已发回GameStart消息，则向所有客户端发送GameStart消息
//	4.在任何一个当前游戏桌的游戏者的状态发生变化后，都要清除相应每个游戏者的该标志
//---------------------------------------------------------------------------
typedef struct tagGLACKGAMESTART
{
	GLACKHEADER header;
	WORD wTable;	
	WORD wChannel;
	char szChatRoomName[GL_BUFLEN_ROOMNAME];
	char szGameAdvert[GL_BUFLEN_HOST];
}GLACKGAMESTART, *PGLACKGAMESTART;

typedef struct tagSTARTGAMEINFO
{
	const char *pszGameName;
	const char *pszGameIP;					//游戏服务器IP地址
	UINT nGamePort;							//游戏服务器端口
	const char *pszRoomName;				//游戏室名称
	int nTable;								//游戏桌号
	int nSeat;								//座位号，编号从1开始，旁观者要加游戏人数

	const char *pszChatIP;					//聊天服务器IP地址
	UINT nChatPort;							//聊天服务器端口
	const char *pszChatRoomName;			//聊天室名称

	const char *pszUserName;				//用户名
	const char *pszNickName;				//中文名字
	const char *pszRank;					//等级
	int nScore;								//积分

	const char *pszAdvertURL;				//客户端首个广告地址

	int nStartMode;							//启动方式：0、正常 1、断线续玩 2、转播
}STARTGAMEINFO,*PSTARTGAMEINFO;

#define STARTMODE_NORMAL		0
#define STARTMODE_CONTINUE		1
#define STARTMODE_BROADCAST		2
#define STARTMODE_BROADCASTSELF	3
//---------------------------------------------------------------------------
//	请求服务器启动游戏
//---------------------------------------------------------------------------
typedef struct tagGLREQGAMESTART
{
	GLREQHEADER header;
	WORD wTable;
	DWORD dwCount;
	DWORD dwCheck;
}GLREQGAMESTART, *PGLREQGAMESTART;

//---------------------------------------------------------------------------
//	结束游戏，没有请求消息，Room接收到该命令后执行下列动作：
//	1.改变该桌子上的所有状态为Standing
//	2.客户端游戏程序已经自动结束
//	3.后跟每个游戏者的积分
//---------------------------------------------------------------------------
#define	GLID_GAMEOVER					(GLID_BASEROOM+0x00000009)

typedef struct tagSCOREINFO
{
	DWORD dwSeat;
	DWORD dwScore;										// 积分
	DWORD dwWins;										// 赢的局数
	DWORD dwLosses;										// 输的局数
	DWORD dwDraws;										// 平局数
	DWORD dwRank;										// 级别
	DWORD dwGameCount;									// 游戏次数
	DWORD dwBreakCount;									// 逃跑次数
}SCOREINFO,*PSCOREINFO;

//---------------------------------------------------------------------------
//	游戏结束后，向客户端发送该消息
//---------------------------------------------------------------------------
typedef struct tagGLACKGAMEOVER
{
	GLACKHEADER header;
	WORD wTable;
	DWORD dwCount;
	SCOREINFO sScoreInfo[GL_MAX_PLAYERSPERTABLE];
}GLACKGAMEOVER, *PGLACKGAMEOVER;

//---------------------------------------------------------------------------
//	创建Room，同时自动进入该Room
//---------------------------------------------------------------------------
#define	GLID_CREATEROOM					(GLID_BASEROOM+0x0000000a)

//---------------------------------------------------------------------------
//	用GLACKENTERROOM作为返回的信息包, dwType用GLID_ENTERROOM | GLID_ACK
//
//	1.检查游戏室是否已经存在
//	2.创建新的游戏室
//	3.调用EnterRoom
//---------------------------------------------------------------------------
typedef struct tagGLREQCREATEROOM
{
	GLREQHEADER header;
	char szName[GL_BUFLEN_ROOMNAME];
	char szPassword[GL_BUFLEN_PASSWORD];
	int nMaxTable;
	int nMaxPlayer;
	int nNetSpeed;
	int nBreakRate;
	DWORD cnProperty;
}GLREQCREATEROOM, *PGLREQCREATEROOM;

//---------------------------------------------------------------------------
//	邀请参与
//---------------------------------------------------------------------------
#define	GLID_INVITE						(GLID_BASEROOM+0x0000000b)

//---------------------------------------------------------------------------
//	转发消息
//---------------------------------------------------------------------------
typedef struct tagGLREQINVITE
{
	GLREQHEADER header;
	char szSrcUserName[GL_BUFLEN_USERNAME];
	char szDstUserName[GL_BUFLEN_USERNAME];
}GLREQINVITE, *PGLREQINVITE;

//---------------------------------------------------------------------------
//	改变用户状态过程
//---------------------------------------------------------------------------
#define	GLID_READY						(GLID_BASEROOM+0x0000000c)

//---------------------------------------------------------------------------
//	改变用户状态过程，请求结构，必定当前用户，客户端向服务器发送请求后，直到
//	服务器确认返回后才真正改变用户的状态
//
//	1.设置Ready标志，同时广播该用户状态
//---------------------------------------------------------------------------
typedef struct tagGLREQREADDY
{
	GLREQHEADER header;
	BOOL bReady;										// 是否已经准备好
}GLREQREADDY, *PGLREQREADY;

//---------------------------------------------------------------------------
//	客户端在收到该消息后，检查是否可以启动游戏了，如果可以，则向服务器发送GameStart请求消息
//---------------------------------------------------------------------------
typedef struct tagGLACKREADY
{
	GLACKHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];				// 用户名
	BOOL bReady;										// 是否已经准备好
}GLACKREADY, *PGLACKREADY;

//---------------------------------------------------------------------------
//	由于游戏客户端无法启动，因此要求服务器取消该局游戏
//
//	1.由于游戏客户端程序无法正常启动，向服务器发送游戏结束消息
//---------------------------------------------------------------------------
#define	GLID_CANCELGAME					(GLID_BASEROOM+0x0000000d)

typedef struct tagGLREQCANCELGAME
{
	GLREQHEADER header;
	DWORD dwTable;
}GLREQCANCELGAME, *PGLREQCANCELGAME;

//----------------------------------------------------------------------
//	通知游戏室的版本，注意只有游戏室版本大于0的才有可能实现游戏自动重新启动的功能
//----------------------------------------------------------------------
#define GLID_ROOMVERSION				(GLID_BASEROOM+0x0000000e)

typedef struct tagGLREQROOMVERSION
{
	GLREQHEADER header;
	DWORD dwVersion;
	DWORD dwLanguage;
	int nIPMaskByte;
	DWORD dwGameVersion;
	DWORD dwLocalIP;						//本地ip地址		chenzd	2001.7.13
}GLREQROOMVERSION, *PGLREQROOMVERSION;

typedef struct tagGLREQROOMVERSIONEX
{
	GLREQHEADER header;
	DWORD dwVersion;
	//DWORD dwLanguage;	//分成下面两个word wym 2003-3-5
	WORD wLanguage;			// 客户端的语言代码 936=中文
	WORD wMobileType;		// 手机的型号，每一种我们支持的手机都有一个唯一的编号 
							// pc客户端必须置0  wym 2003-3-5
	int   nIPMaskByte;
	DWORD dwGameVersion;
	DWORD dwLocalIP;		//本地ip地址		chenzd	2001.7.13
	WORD  dwRoomAdCount;	//当前大厅中添加的广告客户端控件数目(频道数目)   lvch 2002 04 05
    WORD  dwGameAdCount;	//当前该种游戏中广告客户端控件数目(频道数目) =0 不支持当前新广告形式
    //其后跟着dwRoomAdCount个DWORD值,分别为对应的频道ID
    //如果dwGameAdCount>0则在其后还跟着如果dwGameAdCount个DWORD值,分别为对应的游戏中频道ID
}GLREQROOMVERSIONEX, *PGLREQROOMVERSIONEX;
// wMobileType的定义见glregisterProtocol.h wym 2003-3-5
#define GL_RRVEX_MT_MOBILEPROXY		0x8000		//手机代理标识 chairmin 2004.6.2

/*  //对于0x0201000B以后的大厅,大厅等待一个回应消息 消息ID=GLID_ACK|GLID_ROOMVERSION
*/
typedef struct tagGLACKROOMVERSION
{
	GLACKHEADER header;
	DWORD RoomLoginSeed;  //返回登陆的校验码
	DWORD dwGenePlayerInfoVersion;//服务器生成用户信息的协议版本号，根据该版本号，客户端可以判断是否解析新增字段 wuqy add 2005.8.10
}GLACKROOMVERSION, *PGLACKROOMVERSION;

#define	GLID_GAMESTARTSELF				(GLID_BASEROOM+0x0000000f)
//---------------------------------------------------------------------------
//	自动启动游戏
//---------------------------------------------------------------------------
typedef GLACKGAMESTART GLACKGAMESTARTSELF,*PGLACKGAMESTARTSELF;

//---------------------------------------------------------------------------
//	用于测试玩家的网络速度，服务器端在收到该消息后，立即把该消息同样发回给客户端
//---------------------------------------------------------------------------
#define	GLID_NETSPEED					(GLID_BASEROOM+0x00000010)
typedef struct tagGLREQNETSPEED
{
	GLREQHEADER header;
	DWORD dwSpeed;
	DWORD dwTickCount;
}GLREQNETSPEED, *PGLREQNETSPEED;

typedef struct tagGLREQNETSPEEDEX//这个定义用户返回网速时，扣除延迟时间 wuqy add 2006.4.3
{
	GLREQHEADER header;
	DWORD dwSpeed;
	DWORD dwTickCount;
	DWORD dwTickCountWhenReceive;
}GLREQNETSPEEDEX, *PGLREQNETSPEEDEX;

//---------------------------------------------------------------------------
//	强行让人站起
//---------------------------------------------------------------------------
#define	GLID_STANDUP					(GLID_BASEROOM+0x00000011)
typedef struct tagGLREQSTANDUP
{
	GLREQHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];
	DWORD dwReason;
}GLREQSTANDUP,*PGLREQSTANDUP;

typedef struct tagGLACKSTANDUP
{
	GLACKHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];
	DWORD dwReason;
}GLACKSTANDUP,*PGLACKSTANDUP;

#define	GLID_SAMEIP						(GLID_BASEROOM+0x00000012)

//---------------------------------------------------------------------------
//	向玩家提示信息
//---------------------------------------------------------------------------
#define	GLID_PROMPTMSG					(GLID_BASEROOM+0x00000013)

#define	GL_PROMPTMSG_OTHER				0			//其它消息，由服务器端带来

#define	GL_PROMPTMSG_WATCHONLY			1			//这张椅子不能坐人！
#define	GL_PROMPTMSG_NODATA				2			//服务器数据已经改变，请先退出，再重新进入！

#define	GL_PROMPTMSG_NOTSTARTED			3			//比赛时间未到！
#define	GL_PROMPTMSG_FINISHED			4			//比赛时间未到！
#define	GL_PROMPTMSG_NOTPLAYER			5			//您不是参赛选手！
#define	GL_PROMPTMSG_NOMATCH			6			//这一轮您不用参加！
#define	GL_PROMPTMSG_MATCHED			7			//本轮比赛您已经完成了！
#define	GL_PROMPTMSG_FREE				8			//自由选择对手
#define	GL_PROMPTMSG_AUTOFREE			9			//随机选择对手
#define	GL_PROMPTMSG_NOTTHISROOM		10			//您的坐位不在这间游戏室内！
#define	GL_PROMPTMSG_NOTTHISSEAT		11			//请选择标有您自己名字的位置就坐！
#define	GL_PROMPTMSG_CANNOTSIT			12			//这个游戏室不能游戏，只能旁观！
#define	GL_PROMPTMSG_START				13			//比赛现在开始！
#define	GL_PROMPTMSG_DELAY				14			//过了比赛的等待期了

#define	GL_PROMPTMSG_SIGN_NOTSTART		15			//报名还没有开始
#define	GL_PROMPTMSG_SIGN_IPREFUSE		16			//报名IP地址受限
#define	GL_PROMPTMSG_SIGN_MASTERSCORE	17			//报名大师分受限
#define	GL_PROMPTMSG_SIGN_SCORE			18			//报名游戏积分受限
#define	GL_PROMPTMSG_SIGN_GAMECOUNT		19			//报名游戏总盘数受限
#define	GL_PROMPTMSG_SIGN_OTHERTABLE	20			//请另一桌报名
#define	GL_PROMPTMSG_SIGN_PDSEAT2		21			//请和搭档对坐
#define	GL_PROMPTMSG_SIGN_PDSEAT3		22			//请在同一阵营中
#define	GL_PROMPTMSG_SIGN_OVER			23			//报名结束
#define	GL_PROMPTMSG_SIGN_ERR			24			//出现错误
#define GL_PROMPTMSG_SIGN_NOADD			25			//你是种子选手，不能参加当前的比赛

#define	GL_PROMPTMSG_SIGN_ALREADY		26			//您已经报过名了，请准备参加下一轮比赛
#define	GL_PROMPTMSG_SIGN_FULL			27			//本场比赛的名额已满，请以后再来
#define	GL_PROMPTMSG_PAUSED				28			//比赛处于暂停阶段
#define	GL_PROMPTMSG_OLDSEAT			29			//比赛比赛重启了，要坐在原来的位子上

#define	GL_PROMPTMSG_ACHIEVE			30			//您在本阶段比赛中已经出线了
#define	GL_PROMPTMSG_COUNTOVER			31			//你已经完成了本阶段比赛的场次
#define GL_PROMPTMSG_SIGN_LASEPHASE		32			//只有上一阶段比赛出线的选手才能继续比赛
#define GL_PROMPTMSG_SIGN_WEB			33			//网页报名，房间签到

#define GL_PROMPTMSG_PLAYER_SEED		34			//你是种子选手，不能参加当前的比赛
#define GL_PROMPTMSG_SIGN_FUNCTION		35			//门派限制

#define	GL_PROMPTMSG_MATCH_NOPROMP		100			//不需要提示

typedef struct tagGLREQPROMPTMSG
{
	GLREQHEADER header;
	DWORD dwPromptMsg;
}GLREQPROMPTMSG,*PGLREQPROMPTMSG;

#define	GLID_ADDROOM					(GLID_BASEROOM+0x00000014)

typedef struct tagGLREQADDROOM
{
	GLREQHEADER header;
	BASEROOMINFO sRoom;
	int cnProperty;
}GLREQADDROOM,*PGLREQADDROOM;

#define	GLID_DELETEROOM					(GLID_BASEROOM+0x00000015)

typedef struct tagGLREQDELETEROOM
{
	GLREQHEADER header;
	char szName[GL_BUFLEN_ROOMNAME];
}GLREQDELETEROOM,*PGLREQDELETEROOM;

//---------------------------------------------------------------------------
//	存盘文件信息
//---------------------------------------------------------------------------
typedef struct tagSAVEFILEINFO
{
	int cnPlayer;
	char aszPlayerName[GL_MAX_PLAYERSPERTABLE][GL_BUFLEN_USERNAME];
	char szTitle[GL_BUFLEN_SAVEINDEXNAME];
	void *pwm;
	int cnMsg;
	char aszNickName[GL_MAX_PLAYERSPERTABLE][GL_BUFLEN_NICKNAME];
}SAVEFILEINFO,*PSAVEFILEINFO;

#ifdef _NEWSTAGE
#else
typedef struct tagMATCHPLAYERINFO
{
	char szUserName[GL_BUFLEN_USERNAME];
	WORD wRoom;
	WORD wTable;
	WORD wSeat;
	WORD wStatus;
	WORD wStatus2;
	int nSaveFile;
	DWORD dwPlayedCount;
	DWORD dwScore;
	//DWORD* pdwOtherPlayers;
	//所有的结构都连在一起所以可以通过序号找到对手的pmpi, 
	//一个dword数组要跟在结构最后面(因为结构是可以扩充的)， 存放对手的排序前的序号，也就是在内存中的偏移
}MATCHPLAYERINFO,*PMATCHPLAYERINFO;
#endif
//---------------------------------------------------------------------------
//	比赛选手记录，后面缀有对手号表,最多m_pMatchInfo->cnMatchGameCount*(cnSeat-1)个DWORD，由于
//  这个结构只保存本GameServer上的赛员，多不过3000条
//---------------------------------------------------------------------------
//#define MAX_OPPONENT_NUM	100
typedef struct tagNEWMATCHPLAYERINFO
{
	char szUserName[GL_BUFLEN_USERNAME];	//选手名称
	char szPartner[GL_BUFLEN_USERNAME];		//同伴名称(如果打对家就会有)
	char szPartner2[GL_BUFLEN_USERNAME];	//第二同伴名称(可能会3打3)--够级wuqy 2002.7.26
	DWORD dwTeamID;							//所属队号
	WORD wRoom;								//选手比赛房间号
	WORD wTable;							//选手比赛游戏桌
	WORD wSeat;								//选手比赛座位号
	WORD wStatus;							//选手比赛状态
	WORD wStatus2;							//其他状态信息
	WORD wPlace;
	int nScore;								//比赛积分
	int nSecondScore;						//小分
	DWORD dwLosses;							//输
	DWORD dwWins;							//赢
	DWORD dwDraws;							//和
	int nSaveFile;							//桌子上pNmpi的本地存盘文件编号
	DWORD dwFirstCount;						//先手次数
	int cnMatch;							//已经比赛多少次了
	int cnOpponent;							//对手数目
	DWORD dwFlag;							//位标志
	int	cnMatchCount;						//参赛记次
}NEWMATCHPLAYERINFO,*PNEWMATCHPLAYERINFO;

//NEWMATCHPLAYERINFO.dwFlag位标志含义
#define	GL_MATCH_PLAYER_SEED		0x00000001	//下一轮的比赛选手，不能参加当前比赛

//---------------------------------------------------------------------------
//	请求客户端设置用户的初始段位或积分值
//---------------------------------------------------------------------------
#define	GLID_INITIALRANKSCORE				(GLID_BASEROOM+0x00000016)

//---------------------------------------------------------------------------
//	nType=0	初始化段位
//	nType=1	初始化积分
//---------------------------------------------------------------------------
typedef struct tagGLREQINITIALRANKSCORE
{
	GLREQHEADER header;
	int nType;
	int nMin;
	int nMax;
	int nCur;
}GLREQINITIALRANKSCORE,*PGLREQINITIALRANKSCORE;

typedef struct tagGLACKINITIALRANKSCORE
{
	GLACKHEADER header;
	int nType;
	int nValue;
}GLACKINITIALRANKSCORE,*PGLACKINITIALRANKSCORE;

//---------------------------------------------------------------------------
//	查询两人对局，获胜后能赢多少分，输了后要丢多少分，或者和棋有多少分
//---------------------------------------------------------------------------
#define	GLID_QUERYGAMESCORE					(GLID_BASEROOM+0x00000017)

#define GLBIT_QUERYGAMESCORE_SUCCESS			GLBIT_SUCCESS	//成功
#define GLBIT_QUERYGAMESCORE_INVALIDUSERNAME	2				//用户名没有找到
#define GLBIT_QUERYGAMESCORE_NOTSUPPORT			4				//不支持

typedef struct tagGLREQQUERYGAMESCORE
{
	GLREQHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];
}GLREQQUERYGAMESCORE,*PGLREQQUERYGAMESCORE;

typedef struct tagGLACKQUERYGAMESCORE
{
	GLACKHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];
	DWORD dwLoseScore;
	DWORD dwWinScore;
	DWORD dwDrawScore;
}GLACKQUERYGAMESCORE,*PGLACKQUERYGAMESCORE;

//---------------------------------------------------------------------------
//	服务器端向新版客户端发送的游戏信息，服务器端主动推送
//---------------------------------------------------------------------------
#define	GLID_GAMEINFO						(GLID_BASEROOM+0x00000018)

typedef struct tagGLACKGEMEINFO
{
	GLACKHEADER header;
	int nTableNo;								//成绩表
	int nCreateRoomFee;							//创建游戏室的财富值
}GLACKGEMEINFO,*PGLACKGEMEINFO;

//DYF.2003.04.01.Begin
//增加会员设置密码桌收费功能
typedef struct tagGLACKGEMEINFOEX
{
	GLACKHEADER header;
	int nTableNo;								//成绩表
	int nCreateRoomFee;							//创建游戏室的财富值
	int nSetTablePwdFee;						//设置游戏桌密码的财富值
}GLACKGEMEINFOEX,*PGLACKGEMEINFOEX;
//DYF.2003.04.01.End

//---------------------------------------------------------------------------
//	在游戏结束后，或者中途，用户的信息发生改变时发送这个消息，这个消息后以串形式发送新的字段内容，每个用户的内容包括：
//	szUserName		不定长，0结尾
//	cnCol			1字节，字段个数，不同的用户字段数可能不一样
//	col1			第一个字段在进入游戏室时字段内的编号(可能是隐含字段)
//	content1		第一个字段的新值，类型和进入游戏室时描述的一样的
//	...
//---------------------------------------------------------------------------
#define	GLID_CHANGEINFO						(GLID_BASEROOM+0x00000020)

typedef struct tagGLREQCHANGEINFO
{
	GLREQHEADER header;
	DWORD dwCount;
}GLREQCHANGEINFO,*PGLREQCHANGEINFO;

//#define	GLID_ROOMLOGIN						(GLID_BASEROOM+0x00000030)	//Login 代替老版本的 GLID_LOGIN 在前面

//用ticket登录游戏服务器 wangym 2005.11.7
//#define GLID_ROOMLOGIN2						(GLID_BASEROOM+0x00000031) 在前面

//	向服务器请求坐下
#define	GLID_AUTOFREESIT					(GLID_BASEROOM+0x00000050)

//	读取比赛信息
#define	GLID_MATCHINFO						(GLID_BASEROOM+0x00000051)

typedef struct tagGLACKMATCHINFO
{
	GLACKHEADER header;
	DWORD dwLength;
	BOOL bHtml;
}GLACKMATCHINFO,*PGLACKMATCHINFO;

//---------------------------------------------------------------------------
//	当比赛游戏桌状态发生变化时发送
//---------------------------------------------------------------------------
#define	GLID_STATICINFO						(GLID_BASEROOM+0x00000052)
#define	GLID_MATCHPLAYERSTATUS				(GLID_BASEROOM+0x00000053)

typedef struct tagMATCHPLAYERSTATUSINFO
{
	char szUserName[GL_BUFLEN_USERNAME];
	char cUserType;
}MATCHPLAYERSTATUSINFO,*PMATCHPLAYERSTATUSINFO;

typedef struct tagGLREQMATCHPLAYERSTATUS
{
	GLREQHEADER header;
	int nTable;
	DWORD dwCount;
	MATCHPLAYERSTATUSINFO amps[GL_MAX_PLAYERSPERTABLE];
}GLREQMATCHPLAYERSTATUS,*PGLREQMATCHPLAYERSTATUS;

#define	GLID_BROADCAST						(GLID_BASEROOM+0x00000054)

typedef struct tagGLREQBROADCAST
{
	GLREQHEADER header;
	int nTable;
}GLREQBROADCAST,*PGLREQBROADCAST;

#define	GLID_GAMESTARTBROADCAST				(GLID_BASEROOM+0x00000055)
#define	GLID_GAMESTARTBROADCASTSELF			(GLID_BASEROOM+0x00000056)
//---------------------------------------------------------------------------
//	转播方式启动游戏客户端
//---------------------------------------------------------------------------
typedef GLACKGAMESTART GLACKGAMESTARTBROADCAST,*PGLACKGAMESTARTBROADCAST;
typedef GLACKGAMESTART GLACKGAMESTARTBROADCASTSELF,*PGLACKGAMESTARTBROADCASTSELF;

//---------------------------------------------------------------------------
//	游戏室请求转播，后面跟用户名
//---------------------------------------------------------------------------
typedef struct tagGLACKBROADCAST
{
	GLACKHEADER header;
	int nTable;
	char szTitle[GL_BUFLEN_SAVEINDEXNAME];
	int cnPlayer;
	char aszUserName[GL_MAX_PLAYERSPERTABLE][GL_BUFLEN_USERNAME];
}GLACKBROADCAST,*PGLACKBROADCAST;

#define	GLID_ENCRYPT						(GLID_BASEROOM+0x00000060)
//---------------------------------------------------------------------------
//	发送加密函数
//---------------------------------------------------------------------------
typedef struct tagGLREQENCRYPT
{
	GLREQHEADER header;
	DWORD dwEncryptSeed;
	DWORD dwDencryptSeed;
	UINT nEncryptLen;
	UINT nDencryptLen;
}GLREQENCRYPT,*PGLREQENCRYPT;


#define	GLID_USERCHANGEDRESS					(GLID_BASEROOM+0x00000065)
//-------------------------------------------------------------------------------------------------------
//	用户改变自身的物品佩戴
//	请求消息：
//	ackheader
//	string	pszUserName			//改变物品佩戴的用户名
//	WORD	wCount;				//佩戴物品的总数
//	随后跟着wCount个 wItemID ... wItemID
//服务器接收到该消息后,将直接把该消息转发给该游戏室所有用户

//用户的权限标志，用户登录游戏服务器时给room.ocx发送的该用户的所有权限标志
#define	GLID_USER_PRIVILEGEICO					(GLID_BASEROOM+0x00000066)
typedef struct tagGLACKUSERPRIVILEGEICO
{
    GLACKHEADER header;
	int		timeMemberStart;						//用户会员资历起始时间 wuqy add 2005.7.27
	int		nMemberRank;							//当前用户会员等级 wuqy add 2005.7.27
	int		nMemberStartDays;						//已经过去的会员天数(累计会员天数)
	int		nNextMemberRankNeedDays;				//下一次户会员等级升级还需要的天数

	int		nCoinScore;								//用户消费积分 wuqy add 2005.7.27
	int		nCoinScoreRank;							//当前消费等级
	int		nNextCoinScoreRankNeed;					//下一次消费等级升级还需要的消费积分

	int		cnPrivilegeIcon;						//权限标志数
	WORD	awPrivilege[GL_MAX_PRIVILEGE_COUNT];	//用户拥有的权限标志
	WORD	wIcoFlags;								//Icon显示标志，bit0是否显示会员等级,bit1是否显示消费等级，bit2是否显示会员标志，bit3是否显示权限标志

	int		timeMemberContinueStart;				//持续当会员的开始时间
	int		nMemberContinueDays;					//持续当会员数
	int		nMemberLeftDays;						//剩余会员天数
}GLACKUSERPRIVILEGEICO,*PGLACKUSERPRIVILEGEICO;

#define PRIVILEGEICO_MEMBERRANK		0x0001
#define PRIVILEGEICO_COINSCORERANK	0x0002
#define PRIVILEGEICO_MEMBER			0x0004
#define PRIVILEGEICO_PRIVILEGE		0x0008
#define PRIVILEGEICO_HAVEMEMBERDAYS	0x0010

//用户请求改变显示标志
#define	GLID_CHANGE_USER_PRIVILEGEICO			(GLID_BASEROOM+0x00000067)
typedef struct tagGLREQCHANGEPRIVILEGE
{
    GLREQHEADER header;
	WORD	wIcoFlags;								//Icon显示标志，bit0是否显示会员等级,bit1是否显示消费等级，bit2是否显示会员标志，bit3是否显示权限标志
	WORD	wPrivilege;								//用户希望显示的权限标志,GL_PRIVILEGE_NONE没有变化
}GLREQCHANGEPRIVILEGE,*PGLREQCHANGEPRIVILEGE;
//GLACKHEADER header;

//用户请求更新显示标志
#define	GLID_UPDATE_USER_PRIVILEGEICO			(GLID_BASEROOM+0x00000068)
//GLREQHEADER header;
typedef struct tagGLACKUPDATEPRIVILEGE
{
	GLACKHEADER header;
	char	szUserName[GL_BUFLEN_USERNAME];
	WORD	wIcoFlags;								//Icon显示标志，bit0是否显示会员等级,bit1是否显示消费等级，bit2是否显示会员标志，bit3是否显示权限标志
	WORD	wPrivilege;								//用户希望显示的权限标志,GL_PRIVILEGE_NONE没有变化
}GLACKUPDATEPRIVILEGE,*PGLACKUPDATEPRIVILEGE;

//Room.ocx请求用户的权限标志和会员等级信息 wuqy add 2005.12.15
#define	GLID_GETUSERPRIVILEGEICOANDMEMBERINFO				(GLID_BASEROOM+0x00000069)
typedef struct tagGLREQGETUSERPRIVILEGEICOANDMEMBERINFO
{
    GLREQHEADER header;
	char	szUserName[GL_BUFLEN_USERNAME];
}GLREQGETUSERPRIVILEGEICOANDMEMBERINFO,*PGLREQGETUSERPRIVILEGEICOANDMEMBERINFO;
typedef struct tagGLACKGETUSERPRIVILEGEICOANDMEMBERINFO
{
	GLACKHEADER header;
	char	szUserName[GL_BUFLEN_USERNAME];

	WORD	wIcoFlags;								//Icon显示标志，bit0是否显示会员等级,bit1是否显示消费等级，bit2是否显示会员标志，bit3是否显示权限标志
	int		cnPrivilegeIcon;						//权限标志数
	WORD	awPrivilege[GL_MAX_PRIVILEGE_COUNT];	//用户拥有的权限标志

	int		timeMemberStart;						//用户会员资历起始时间
	int		nMemberRank;							//当前用户会员等级
	int		nMemberStartDays;						//已经过去的会员天数(累计会员天数)
	int		nNextMemberRankNeedDays;				//下一次户会员等级升级还需要的天数

	int		nCoinScore;								//用户消费积分
	int		nCoinScoreRank;							//当前消费等级
	int		nNextCoinScoreRankNeed;					//下一次消费等级升级还需要的消费积分

	int		timeMemberContinueStart;				//持续当会员的开始时间
	int		nMemberContinueDays;					//持续当会员数
	int		nMemberLeftDays;						//剩余会员天数

}GLACKGETUSERPRIVILEGEICOANDMEMBERINFO,*PGLACKGETUSERPRIVILEGEICOANDMEMBERINFO;


//add by lvch  2002/04/01  新的广告系统数据结构
//#define  GLID_PUTADVERTFILELIST             (GLID_BASEROOM+0x00000070)//服务器向客户端发送需下载的广告文件列表
//使用原发送ID     GLID_FILEADVERT
typedef struct tagGLNEWADLOCALVERSION
{
	DWORD   AdvertID;
	DWORD   AdvertVersion;
}GLNEWADLOCALVERSION,*PGLNEWADLOCALVERSION;
typedef struct tagGLPUTADVERTFILELIST
{
	GLREQHEADER header;
	int     ADTotal;   //包中的文件信息总数
}GLPUTADVERTFILELIST,*PGLPUTADVERTFILELIST;//其后跟着ADTotal个GLNEWADLOCALVERSION


#define  GLID_GETADVERTFILEINFO             (GLID_BASEROOM+0x00000071)//客户端向服务器请求广告文件
typedef struct tagGLGETADVERTFILEINFO
{
    GLREQHEADER header;
	DWORD       AdvertID;
}GLGETADVERTFILEINFO,*PGLGETADVERTFILEINFO;

#define  GLID_PUTADVERTFILEINFO             (GLID_BASEROOM+0x00000072)//服务器向客户端发送指定广告文件
typedef struct tagGLPUTADVERTFILEINFO
{
    GLACKHEADER header;
    DWORD       AdvertID;
	DWORD       AdvertVersion;
}GLPUTADVERTFILEINFO,*PGLPUTADVERTFILEINFO;//其后跟着广告文件数据

//end lvch 2002/04/01

//add lvch 2002 08 30
#define  GLID_LOBBYADNOTIFYCMD              (GLID_BASEROOM+0x00000073)//大厅向服务器通知当前当前画中画广告的显示次数和点击数
typedef struct tagGLLOBBYADNOTIFYCMD
{
    GLREQHEADER header;
	char        UserName[GL_BUFLEN_USERNAME];
    DWORD       AdCount;
}GLLOBBYADNOTIFYCMD,*PGLLOBBYADNOTIFYCMD;//其后跟着AdCount个GLLOBBYADNOTIFYINFO结构

typedef struct tagGLROOMCLIENTADINFO
{
	DWORD   ChannelID;           //频道ID
	DWORD	GamePopupTime;		 //该频道是否受游戏开始和结束限制  
								//=0  正常广告
								//=1  该频道广告只有在游戏结束后才弹出
								//=2  该频道广告只有在游戏开始时才弹出
	DWORD	dwDeltaRefreshTime; //该频道设置的广告刷新时间间隔 wuqy add 2005.1.28
	DWORD   LastRefreshTime;     //该频道最近一次刷新时间
	DWORD   CurrentIndex;        //当前显示的广告索引
}GLROOMCLIENTADINFO,*PGLROOMCLIENTADINFO;   //add by lvch  2002 04 05

typedef struct tagGLLOBBYADNOTIFYINFO
{
	DWORD    ADID;
	WORD     ShowCount;
	WORD     ClickCount;
}GLLOBBYADNOTIFYINFO,*PGLLOBBYADNOTIFYINFO;

//end add lvch 2002 08 30

//shil.2002.11.8
//下边部分是从gameprotocol移过来的
//主要是因为使用了GLID_BASEROOM
//-----------------------------------------------------------------------
//     广告系统
//------------------------------------------------------------------------
//#define  GLID_NTYCLIENTPLAYAD               (GLID_BASEROOM+0x00000073)//服务器通知客户端播放指定广告
//使用原来的ID   GLID_ADVERT
typedef struct tagGLNTYCLIENTPLAYAD
{
    GLREQHEADER header;
	DWORD       ChannelID;
    DWORD       AdvertID;
    DWORD       PopupSize;          //高字为宽度  低字为高度
	DWORD       LargeType;          //高字为全屏广告类型 低字为全屏广告显示时间(秒)
	DWORD       LargeTopLeft;       //全屏广告左上角坐标 高位字为Left 低位字为Top
    DWORD       LargeBottomRight;   //全屏广告右下角坐标 高位字为Right 低位字为bottom
	DWORD       URLLength;          //四个字节意义如下(从低到高) MainURL串长度 PopupURL串长度,LARGEURL串长度,Tips串长度
}GLNTYCLIENTPLAYAD,*PGLNTYCLIENTPLAYAD;//其后依次跟着MainURL[],PopupURL[],LARGEURL[],Tips[];


typedef struct tagGLNTYLOBBYNEWAD
{
    GLREQHEADER header;
	DWORD       ChannelID;
    DWORD       AdvertCount;//随后跟着AdvertCount个DWORD值,表示广告ID
}GLNTYLOBBYNEWAD,*PGLNTYLOBBYNEWAD;//大厅画中画广告


#define  GLID_ROOMDOWNLOADSERVERIP           (GLID_BASEROOM+0x00000075)
										//当服务器的Advert.ini文件中存在一个[DownLoadServer]节时,当
							//大厅登陆以及进入游戏室时服务器主动向客户端发送GLID_ROOMDOWNLOADSERVERIP消息
							//服务器只发送一个Ip到客户端(服务器自身轮循DownLoadServer),保证最大限度均衡
typedef struct tagGL_NOTIFYDOWNLOAD_SERVERINFO
{
	GLACKHEADER		header;
	DWORD			ServerIP;
	DWORD			ServerPort;			
}GL_NOTIFYDOWNLOAD_SERVERINFO,*PGL_NOTIFYDOWNLOAD_SERVERINFO;
typedef struct tagGL_NOTIFYDOWNLOAD_SERVERINFO2//新版本大厅才用这个消息 wuqy add 2006.3.15
{
	GLACKHEADER	    header;
	int             nSvrCount;
}GL_NOTIFYDOWNLOAD_SERVERINFO2,*PGL_NOTIFYDOWNLOAD_SERVERINFO2;

#define  GLID_REPORTADINFO                   (GLID_BASEROOM+0x00000074)//客户端向服务器报告广告的点击次数及弹出次数
typedef struct tagGLREPORTADINFO
{
    GLREQHEADER header;
	DWORD  AdvertID;   //广告ID
    DWORD  MainShow;   //主窗口上广告显示次数
	DWORD  MainClick;  //主窗口上广告点击次数
    DWORD  PopupShow;  //弹出窗口上广告显示次数
	DWORD  PopupClick; //弹出窗口上广告点击次数
    DWORD  LargeShow;  //全屏窗口上广告显示次数
	DWORD  LargeClick; //主窗口上广告点击次数
}GLREPORTADINFO,*PGLREPORTADINFO;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//客户端向服务器索要P2P下载广告需要的信息
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  GLID_GETADP2PINFO                   (GLID_BASEROOM+0x00000076)

//客户端->服务器
typedef struct tagGLREQADP2PRESOURCE
{
    GLREQHEADER header;
	DWORD	dwADID;					//广告ID
}GLREQADP2PRESOURCE,*LPGLREQADP2PRESOURCE;

//服务器->客户端

//资源文件的结构
typedef struct tagGLP2PRESOURCE
{
	char szSrcPath[MAX_PATH];		//资源文件在其它客户上的相对位置（文件的相对路径）
	BYTE byMd5[16];					//资源文件的MD5值，用来做资源的唯一标识
	DWORD dwResourceSize;			//资源文件的大小
	DWORD dwOffsetSize;				//下载偏移量，这个值用来表示从多少偏移量开始下载，用于断点续传（暂不使用，保留）
	char szSavePath[MAX_PATH];		//资源文件下载到本地的保存路径（文件的相对路径）
}GLP2PRESOURCE,*LPGLP2PRESOURCE;

typedef struct tagGLACKADP2PRESOURCE
{
    GLACKHEADER header;
	DWORD	dwADID;					//广告ID
	INT		nCount;					//包含广告文件的数量，后面跟着nCount个GLP2PRESOURCE文件
}GLACKADP2PRESOURCE,*LPGLACKADP2PRESOURCE;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//客户端向服务器上传下载情况
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define  GLID_ADDOWNLOADINFO                   (GLID_BASEROOM+0x00000077)

//客户端->服务器
typedef struct tagGLREQADDOWNLOADINFO
{
    GLREQHEADER header;
	DWORD	dwP2PSuccessed;			//P2P成功下载的广告ID数量
	DWORD	dwP2PFailed;			//P2P失败下载的广告ID数量
	DWORD	dwSuccessed;			//非P2P成功下载的广告ID数量
	DWORD	dwFailed;				//非P2P失败下载的广告ID数量
									//在后面非别跟着dwP2PSuccessed个，dwP2PFailed个，dwSuccessed个，dwFailed个广告ID
}GLREQADDOWNLOADINFO,*LPGLREQADDOWNLOADINFO;

//服务器->客户端	理论上服务器接收这个消息后不需要发给客户端ACK消息，暂时先定义出来
typedef struct tagGLACKADDOWNLOADINFO
{
    GLACKHEADER header;
}GLACKADDOWNLOADINFO,*LPGLACKADDOWNLOADINFO;
//---------------------------------------------------------------------------------------------------------
//shil.2002.11.8.end

//---------------------------------------------------------------------------
//	定义桌子分组形式,一个GLACKHEADER+<分多少组n>\0<组名1>...<组名n>
//	例如:	2\0开%d\0闭%d\0
//---------------------------------------------------------------------------
#define	GLID_TABLEGROUP						(GLID_BASEROOM+0x00000080)

//---------------------------------------------------------------------------
//	桌面广告
//---------------------------------------------------------------------------
#define	GLID_IMAGEADVERT					(GLID_BASEROOM+0x00000090)

typedef struct tagIMAGEFILEIDINFO
{
	int nFileID;							//文件编号
	int nVersion;							//版本号
}IMAGEFILEIDINFO,*PIMAGEFILEIDINFO;

typedef struct tagGLREQIMAGEADVERT
{
	GLREQHEADER header;
	int nType;								//0:没有广告(删除本地广告),1:强制显示,2:只有颜色相同才显示
	int nBkColor;							//0x123456表示任意颜色都可以，这是只要背景不是图形，都应该显示
	int cnFile;								//广告条目
	IMAGEFILEIDINFO asFileInfo[5];			//cnAdvert条文件信息，实际数目和cnAdvert相关
}GLREQIMAGEADVERT,*PGLREQIMAGEADVERT;

#define IMAGEADVERT_DELETE				0
#define IMAGEADVERT_FORCE				1
#define IMAGEADVERT_SAMECOLOR			2

#define	GLID_GETIMAGEADVERT					(GLID_BASEROOM+0x00000091)

//---------------------------------------------------------------------------
//	客户端请求服务器发回图像文件信息
//---------------------------------------------------------------------------
typedef struct tagGLREQGETIMAGEADVERT
{
	GLREQHEADER header;
	int nFileID;
}GLREQGETIMAGEADVERT,*PGLREQGETIMAGEADVERT;

//---------------------------------------------------------------------------
//	服务器端向客户端发送广告图像文件
//---------------------------------------------------------------------------
typedef struct tagGLACKGETIMAGEADVERT
{
	GLACKHEADER header;
	int nFileID;							//文件编号
	int nVersion;							//版本号
	int nType;								//0左上角，1左下角，2右上角，3右下角，4对中，5平铺
	int x,y;								//偏移，离边上的距离
	int nMinWidth,nMinHeight;				//最小的屏幕完成和高度
	DWORD dwLength;							//图像文件内容长度
}GLACKGETIMAGEADVERT,*PGLACKGETIMAGEADVERT;
//zhouy
#define IMGADV_TOPLEFT			0
#define IMGADV_TOPBOTTOM		1
#define IMGADV_RIGHTTOP			2
#define IMGADV_RIGHTBOTTOM		3
#define IMGADV_CENTER			4
#define IMGADV_FULL				5

//shilei.2001.5.10.BEGIN
//---------------------------------------------------------------------------
//	本地文件广告
//---------------------------------------------------------------------------
#define	GLID_FILEADVERT					(GLID_BASEROOM+0x00000092)

typedef struct tagFILESFILEIDINFO
{
	int nFileID;							//文件编号
	int nVersion;							//版本号
}FILESFILEIDINFO,*PFILESFILEIDINFO;

typedef struct tagGLREQFILEADVERT
{
	GLREQHEADER header;
	int cnFile;								//广告条目
	//FILESFILEIDINFO *asFileInfo;			//cnFile条文件信息，实际数目和cnFile相关
}GLREQFILEADVERT,*PGLREQFILEADVERT;

typedef struct tagGLWORLDFILEADVERT
{
	char szServerIP[GL_BUFLEN_HOST];
	WORD wPort;
	int nFile;
	PFILESFILEIDINFO pfa;
} GLWORLDFILEADVERT, FAR *PGLWORLDFILEADVERT;

typedef struct tagGLWORLDNEWFILEADVERT
{
	char szServerIP[GL_BUFLEN_HOST];
	WORD wPort;
	int nFile;
	PGLNEWADLOCALVERSION pfa;
}GLWORLDNEWFILEADVERT, FAR *PGLWORLDNEWFILEADVERT;


#define	GLID_GETFILEADVERT					(GLID_BASEROOM+0x00000092)

//---------------------------------------------------------------------------
//	客户端请求服务器发回本地文件广告信息
//---------------------------------------------------------------------------
typedef struct tagGLREQGETFILEADVERT
{
	GLREQHEADER header;
	int nFileID;
}GLREQGETFILEADVERT,*PGLREQGETFILEADVERT;

//---------------------------------------------------------------------------
//	服务器端向客户端发送本地文件广告，每个文件的内容
//	1.块长度，包括文件名和文件内容，块长度=0，表示结束
//	2.文件名，以0结尾
//	3.文件内容
//---------------------------------------------------------------------------
typedef struct tagGLACKGETFILEADVERT
{
	GLACKHEADER header;
	int nFileID;							//文件编号
	char szFileName[GL_BUFLEN_HOST];		//联接用的文件名
	int nVersion;							//版本号
	int cnFile;								//目录中的文件个数
}GLACKGETFILEADVERT,*PGLACKGETFILEADVERT;
//shilei.2001.5.10.END

//---------------------------------------------------------------------------
//	服务器列表，用于GLWord传到GLRoom				chenzd 2001.4.9
//---------------------------------------------------------------------------
typedef struct tagGAMESERVERINFO
{
	char szName[GL_BUFLEN_SERVERNAME];	//服务器名称
	char szServerIP[GL_BUFLEN_HOST];	//为进入该Server应该使用的IP地址
	WORD wServerPort;					//为进入该Server应该使用的Port地址
	int cnPlayers;
}GAMESERVERINFO, *PGAMESERVERINFO;

//wuqy add
typedef struct tagGAMESERVERINFOEX
{
	char szName[GL_BUFLEN_SERVERNAME];	//服务器名称
	char szServerIP[GL_BUFLEN_HOST];	//为进入该Server应该使用的IP地址
	WORD wServerPort;					//为进入该Server应该使用的Port地址
	int cnPlayers;
	int cnNetSpeed;
}GAMESERVERINFOEX, *PGAMESERVERINFOEX;

//---------------------------------------------------------------------------
//	所有的RoomOcx更新设置用
//---------------------------------------------------------------------------
#define GL_ROOMOCX_PRIVATEDATA		1500
#define MSG_ROOM_SETTINGSCHANGED	_T("MSG_ROOM_SETTINGSCHANGED")

//---------------------------------------------------------------------------
//	GLWorld窗口特殊属性
//---------------------------------------------------------------------------
#define GL_WORLD_PRIVATEDATA		1600
//更换广告消息, LPARAM参数是一个GLREQADVERT地址，Room以SendMessage方式通知GLWorld
#define MSG_WORLD_ADVERT			_T("MSG_WORLD_ADVERT")
#define MSG_WORLD_ADDOWNLOADSERVER  _T("MSG_WORLD_ADDOWNLOADSERVER")
//Room请求GLWorld关闭，没有参数
#define MSG_WORLD_CLOSEROOM			_T("MSG_WORLD_CLOSEROOM")
//文件广告消息，Room通知GLWorld检查本地广告文件, LPARAM参数是一个GLWORLDFILEADVERT地址，Room以SendMessage方式通知GLWorld
#define MSG_WORLD_FILEADVERT		_T("MSG_WORLD_FILEADVERT")
//更换大告消息，LPARAM参数是一个GLREQADVERT地址，Room以SendMessage方式通知GLWorld
#define MSG_WORLD_LARGEADVERT		_T("MSG_WORLD_LARGEADVERT")
//下载客户端消息，LPARAM参数是GLDOWNLOADCLIENT地址，Room以SendMessage方式通知GLWorld
#define MSG_WORLD_DOWNLOADCLIENT	_T("MSG_WORLD_DOWNLOADCLIENT")
#define MSG_WORLD_ONGLMOBILE        _T("GL_WORLD_MOBILE")
#define MSG_WORLD_GETLOBBYADVERT	_T("MSG_WORLD_GETLOBBYADVERT")
											//room向world请求当前的广告计数

//改变Room，通知大厅显示房间信息刷新
#define MSG_CHANGE_ROOM				_T("MSG_CHANGE_ROOM")
// Room.ocx 向大厅请求更新所有 Room.ocx 的用户显示图标。
#define MSG_WORLD_UPDATEICON		_T("MSG_WORLD_UPDATEICON")

typedef struct tagGLDOWNLOADCLIENT
{
	DWORD dwClientID;							//客户端ID，0表示Room
	DWORD dwVersion;							//需要的版本号
	char  szClientName[GL_BUFLEN_GAMENAME];		//客户端名，如GO add by wangning 使用ID和name双重匹配下载
} GLDOWNLOADCLIENT, *PGLDOANLOADCLIENT;
//以上5个消息的WPARAM参数都是发出消息的GLRoom.ocx的父窗口句柄

#define MSG_WORLD_ANOTHERSTARTUP	_T("MSG_WORLD_ANOTHERSTARTUP")

//---------------------------------------------------------------------------
//	内存映像文件，存放dwCheck						chenzd 2001.4.20
//	dwCheck经过dwOp异或，dwOp由GLWord随机生成，如果GLRoom打开内存映像失败，
//	则认为非法
//---------------------------------------------------------------------------
#define	GL_ROOMOCX_CHECK						_T("GL_ROOMOCX_CHECK")
typedef struct tagROOMOCXCHECK{
	DWORD dwMachineIDLo;
	DWORD dwMachineIDHi;
	DWORD dwOp;
}ROOMOCXCHECKINFO,*PROOMOCXCHECKINFO;

//---------------------------------------------------------------------------
//	告知GLWord是否能退出
//---------------------------------------------------------------------------
#define RESULT_ROOM_EXIT		0			//确定退出
#define RESULT_ROOM_CANCEL		1			//用户取消
#define RESULT_ROOM_BUSY		2			//正在接收数据不允许退出

//---------------------------------------------------------------------------
//	新版本中的关于进入游戏室的定义
//---------------------------------------------------------------------------
//	进入游戏室的消息数据结构大致如下:
//	GLACKENTERROOM				消息头
//	szRankName					以0结尾的段位描述字符串，例如围棋的描述为：无,[30-1]%dk,[1-9]%dd,[1-9]%dp,棋圣,保留[1-50],无,[30-1]%dk*,[1-9]%dd*
//	cnField						1字节，说明字段数目
//	FieldType[cnField]			每个字段一个字节
//		7 6 5 4 3 2 1 0
//		| | -----------
//		| |       |
//		| |       ----------->	固定字段，说明是什么字段，每个字段的长度已经内部确定。对于动态字段说明这个字段的类型
//		|-------------------->	对于固定字段，这位=1表示这个字段不用显示
//		|-------------------->	=1表示动态字段，0表示固定字段
//
//	FieldName[0],...			每个字段的显示名称
//	Player[0],...				每个用户的信息，按照FieldType的描述排列
//---------------------------------------------------------------------------
#define	GL_MAX_FIELDCOUNT			40
#define	GL_FIELDTYPE_DYNAMIC		0x80
#define	GL_FIELDTYPE_HIDE			0x40

#define	GL_FIELDTYPE_CHAR			1
#define	GL_FIELDTYPE_BYTE			2
#define	GL_FIELDTYPE_SHORT			3
#define	GL_FIELDTYPE_WORD			4
#define	GL_FIELDTYPE_LONG			5
#define	GL_FIELDTYPE_DWORD			6
#define	GL_FIELDTYPE_FLOAT			7
#define	GL_FIELDTYPE_STRING			8
#define	GL_FIELDTYPE_PERCENT		9					// x 100

#define	GL_FIELD_USERNAME			0					//string
#define	GL_FIELD_NICKNAME			1					//string
#define	GL_FIELD_RANK				2					//BYTE
#define	GL_FIELD_SCORE				3					//int
#define	GL_FIELD_GAMECOIN			3					//int 和GL_FIELD_SCORE复用表示用户的游戏豆字段
#define	GL_FIELD_WINS				4					//DWORD
#define	GL_FIELD_LOSSES				5					//DWORD
#define	GL_FIELD_DRAWS				6					//DWORD
#define	GL_FIELD_BREAKRATE			7					//WORD, x 100
#define	GL_FIELD_IMAGE				8					//WORD
#define	GL_FIELD_MEMBER				9					//BYTE
#define	GL_FIELD_PRIVILEGE			10					//BYTE
#define	GL_FIELD_MONEY				11					//int, / 100
#define	GL_FIELD_STATUS				12					//BYTE
#define	GL_FIELD_TABLE				13					//WORD
#define	GL_FIELD_SEAT				14					//BYTE
#define	GL_FIELD_TABLEPASSWORD		15					//BYTE
#define	GL_FIELD_READY				16					//BYTE
#define	GL_FIELD_MATCHSTATUS		17					//BYTE
#define	GL_FIELD_SPEED				18					//WORD
#define	GL_FIELD_FACTION			19					//string
#define	GL_FIELD_LANGUAGE			20					//WORD

#define	GL_FIXFIELD_COUNT			21

#define	GL_FIELD_TEAMNAME			21					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_STRING	
#define	GL_FIELD_TEAMSCORE			22					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_TEAM2THSCORE		23					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_MATCHSCORE			24					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_SECONDSCORD		25					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_TEAMWINS			26					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_TEAMLOSSES			27					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_TEAMDRAWS			28					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
//调整显示字段 wuqy 2002.6.18
//字段22.23.31保留
//#define	GL_FIELD_PLAYERWINS			29					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
//#define	GL_FIELD_PLAYERLOSSES		30					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_MATCHCOUNT			29					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_FIRSTCOUNT			30					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_PLAYERDRAWS		31					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD

#define	GL_FIELD_WINRATE			32					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_PERCENT
#define	GL_FIELD_DUTY				33					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_STRING
#define	GL_FIELD_GAMECOUNT			34					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_BRIDGERATE			35					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_PERCENT
#define	GL_FIELD_GAMECOINSCORE		35					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD //和GL_FIELD_BRIDGERATE复用表示游戏豆游戏的积分字段
#define	GL_FIELD_BRIDGELASTWEEK		36					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_FLOAT

#define	GL_FIELD_MASTERSCORE		37					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD
#define	GL_FIELD_MATCHORDER			38					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_DWORD

#define GL_FIELD_TIME				39					//GL_FIELDTYPE_DWORD
#define GL_FIELD_MATCHRANK			40					//GL_FIELDTYPE_DYNAMIC | GL_FIELDTYPE_STRING

#define GL_FIELD_MOBILEDSM			63					//手机标志，这个只在游戏室用，实际服务器端通过其它方式传过来的

#define	GL_DATA_UNKNOWN				0x80000001			//未知数值，客户端接收到这个数值将显示未知
#define GL_HALFMAX_NEGATIVE         0xc0000001          //游戏数据中可能出现的最大负数

//----------------------------------------------------------------------
//	读取某个用户的对象,主要用于测试
//----------------------------------------------------------------------
#define	GLID_GETROOMCLIENT				(GLID_BASEROOM+0x00000093)

typedef struct tagGLREQGETROOMCLIENT
{
	GLREQHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];
}GLREQGETROOMCLIENT,*PGLREQGETROOMCLIENT;

typedef struct tagGLACKGETROOMCLIENT
{
	GLACKHEADER header;
	int nLength;
}GLACKGETROOMCLIENT,*PGLACKGETROOMCLIENT;

//----------------------------------------------------------------------
//	锁定搭档用的消息
//					chenzd	2001.9.20
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//	服务器支持锁定搭档功能
//----------------------------------------------------------------------
#define	GLID_CANLOCKPARTNER				(GLID_BASEROOM+0x00000094)

//----------------------------------------------------------------------
//	锁定搭档消息
//----------------------------------------------------------------------
#define	GLID_LOCKPARTNER				(GLID_BASEROOM+0x00000095)
typedef struct tagGLREQLOCKPARTNER
{
	GLREQHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];		//搭档的用户名
	DWORD dwType;								//消息类型
} GLREQLOCKPARTNER, *PGLREQLOCKPARTNER;

#define GL_LOCKPARTNER_REQ				0			//请求锁定
#define GL_LOCKPARTNER_AGREE			1			//同意锁定
#define	GL_LOCKPARTNER_DISAGREE			2			//对方不同意

typedef struct tagGLACKLOCKPARTNER
{
	GLACKHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];		//搭档的用户名
} GLACKLOCKPARTNER, *PGLACKLOCKPARTNER;

#define	GL_LOCKPARTNER_SUCCESS			0			//锁定成功
#define	GL_LOCKPARTNER_NOTSUPPORT		1			//对方的大厅不支持
#define	GL_LOCKPARTNER_HASLOCKED		2			//对方已经锁定了
#define	GL_LOCKPARTNER_ACKDISAGREE		3			//对方不同意
#define	GL_LOCKPARTNER_PARTNERLEFT		4			//对方已经离开

//----------------------------------------------------------------------
//	解除锁定搭档消息
//----------------------------------------------------------------------
#define	GLID_UNLOCKPARTNER				(GLID_BASEROOM+0x00000096)

//----------------------------------------------------------------------
//	锁定搭档状态改变消息
//----------------------------------------------------------------------
//	自己改变状态，但是搭档无法坐下的时候会接到这条消息
#define	GLID_PARTNERCANNOTSIT			(GLID_BASEROOM+0x00000097)

//----------------------------------------------------------------------
//	改变游戏室内桌子数的消息
//					chenzd	2001.11.6
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//	增加桌子消息
//----------------------------------------------------------------------
#define	GLID_ADDTABLE					(GLID_BASEROOM+0x00000098)
//----------------------------------------------------------------------
//	减少桌子消息
//----------------------------------------------------------------------
#define	GLID_DELETETABLE				(GLID_BASEROOM+0x00000099)
//以上两条消息都用下面这个结构
typedef struct tagGLTABLECHANGE
{
	GLREQHEADER header;
	int nTableCount;					//增加或减少的数目
} GLTABLECHANGE, *PGLTABLECHANGE;

//----------------------------------------------------------------------
//	向服务器发送朋友、不受欢迎的人的消息
//					chenzd	2002.1.22
//----------------------------------------------------------------------
#define GLID_SETUSERPROPERTY			(GLID_BASEROOM+0x0000009A)
typedef struct tagGLSETUSERPROPERTY
{
	GLREQHEADER	header;
	char szUserName[GL_BUFLEN_USERNAME];		//目标用户名
	DWORD dwType;								//设置类型，定义见下
} GLSETUSERPROPERTY, *PGLSETUSERPROPERTY;

#define GL_SETUSER_FRIENDTONORMAL		1				//朋友设置成普通属性
#define	GL_SETUSER_ENEMYTONORMAL		2				//不受欢迎设置成普通属性
#define	GL_SETUSER_FRIEND				3				//普通属性设置成朋友
#define	GL_SETUSER_ENEMY				4				//普通属性设置成不受欢迎
#define	GL_SETUSER_ENEMYTOFRIEND		5				//朋友设置成不受欢迎
#define	GL_SETUSER_FRIENDTOENEMY		6				//不受欢迎设置成朋友
//----------------------------------------------------------------------
//	比赛服务器向游戏室发送比赛调查问卷的消息
//					wangcheng 2005.6.15
//----------------------------------------------------------------------
#define GLID_SENDMATCHUSERINVESTIGATE			(GLID_BASEROOM+0x0000009B)
typedef struct tagGLSENDMATCHUSERINVESTIGATE
{
	GLREQHEADER	header;
	char        MatchInvestigateURL[256];
} GLSENDMATCHUSERINVESTIGATE, *PGLSENDMATCHUSERINVESTIGATE;

//OF自动开桌消息 wuqy add 2005.8.16
#define GLID_OFAUTOSTARTGAME			(GLID_BASEROOM+0x0000009C)
typedef struct tagGLREQOFAUTOSTARTGAME
{
	GLREQHEADER	header;
	char szRoomName[GL_BUFLEN_ROOMNAME];
	int nPlayers;
	char aszPlayerName[GL_MAX_PLAYERSPERTABLE][GL_BUFLEN_USERNAME];
}GLREQOFAUTOSTARTGAME,*PGLREQOFAUTOSTARTGAME;
//wuqy end


//----------------------------------------------------------------------
// 向客户端发送带有丰富信息的消息使用的消息ID和结构定义。
//----------------------------------------------------------------------
#define GLID_RICH_PROMPTMSG		(GLID_BASEROOM+0x0000009D)
typedef struct tagGLREQRICHPROMPTMSG
{
	GLREQHEADER header;
	DWORD dwMsgVersion;		// 消息版本，当前为1.0.0.0(0x01000000)
	DWORD dwFlag;			// 消息标志, 设置某个字段是否可用的标志, 以及对话框的按钮标志.
	DWORD dwMsgId;			// 消息标识, 用于区分消息本身, 也用于记录是否此类消
							// 息下次是否提示的唯一区分.
	USHORT nAutoCloseTime;	// 自动关闭的倒计时时间.
	USHORT nIcon;				// 消息框的Icon值。
	DWORD dwReserved1;		// 保留字段1.
	DWORD dwReserved2;		// 保留字段2.
	// char msg[];					// 消息体，以 \0 结束。
	// 未来后面可能跟随其他信息，依据 dwVersion 字段的设置而定。
} GLREQRICHPROMPTMSG, *PGLREQRICHPROMPTMSG;



// GLREQRICHPROMPTMSG Flag 说明：
#define GL_RICHPM_OK				0x00000000	// 只有确定按钮，ID=IDOK, 这是缺省情况.
#define GL_RICHPM_MSGID				0x00000001	// msgid 字段有效。
#define GL_RICHPM_TIME				0x00000002	// auto close time 字段有效。
#define GL_RICHPM_ICON				0x00000004	// icon 字段有效。
#define GL_RICHPM_MSG				0x00000008	// msg 字段有效。
#define GL_RICHPM_RESET				0x00000010	// 忽略CheckBox设置，总是显示消息
#define GL_RICHPM_YESNO				0x00000040	// 有 Yes/No两个按钮，IDYES, IDNO
#define GL_RICHPM_OKCANCEL			0x00000080	// 有OK/Cancel两个按钮。IDOK, IDCANCEL
#define GL_RICHPM_YESNOCANCEL		0x00000100	// 有 Yes/No/Cancel三个按钮，IDYES, IDNO, IDCANCEL

// GLREQRICHPROMPTMSG Icon 说明：
#define GL_RICHPM_ICON_APP			0x0001	// 使用应用程序的图标。
#define GL_RICHPM_ICON_CURGAME		0x0002	// 使用Room当前代表的游戏的Icon,如果没有则使用应用程序的图标。
#define GL_RICHPM_ICON_EXCLAMATION	0x0003	// 使用系统Exclamation图标。
#define GL_RICHPM_ICON_WARNING		0x0004	// 使用系统Warning图标。
#define GL_RICHPM_ICON_INFORMATION	0x0005	// 使用系统Information图标。
#define GL_RICHPM_ICON_ASTERISK		0x0006	// 使用系统AsterRisk图标。
#define GL_RICHPM_ICON_QUESTION		0x0007	// 使用系统Question图标。
#define GL_RICHPM_ICON_STOP			0x0008	// 使用系统Stop图标。

//----------------------------------------------------------------------
// 检测服务器向游戏服务器获得所进房间要求的客户端room版本和game版本  wangch 2006.4.4
//----------------------------------------------------------------------
#define GLID_GETROOMGAMEVERSION		(GLID_BASEROOM+0x0000009E)
//请求
typedef struct tagGLREQGETROOMGAMEVERSION
{
	GLREQHEADER header;
	char szRoomName[GL_BUFLEN_ROOMNAME];	//房间名称

} GLREQGETROOMGAMEVERSION, *PGLREQGETROOMGAMEVERSION;
//回馈
typedef struct tagGLACKGETROOMGAMEVERSION
{
	GLACKHEADER header;
	DWORD dwRoomVersion;		//房间限制版本号
	DWORD dwGameVersion;		//游戏限制版本号
	DWORD dwMinRoomVersion;		//最小的房间限制版本号
} GLACKGETROOMGAMEVERSION, *PGLACKGETROOMGAMEVERSION;

//用户的联众币等公用信息发生了变化,通知房间更新到mapfile wuqy add 2006.4.6
#define GLID_UPDATEUSERPUBINFO	(GLID_BASEROOM+0x0000009F)
typedef struct tagGLREQUPDATEUSERPUBINFO
{
	GLREQHEADER	header;
	int			nMoney;//当前拥有的财富值
	int			nCoin;//当前拥有的联众币
	BYTE		uchMember;
}GLREQUPDATEUSERPUBINFO,*PGLREQUPDATEUSERPUBINFO;
//----------------------------------------------------------------------
// 游戏服务器重新启动时向检测服务器发送重新启动消息  wangch 2006.5.8
//----------------------------------------------------------------------
#define GLID_SENDRESTARTINFO	(GLID_BASEROOM+0x000000A0)
//请求
typedef struct tagGLREQSENDRESTARTINFO
{
	GLREQHEADER header;
	int					nPort;//本机IP
	DWORD				dwIP;//本机端口
}GLREQSENDRESTARTINFO,*PGLREQSENDRESTARTINFO;


//----------------------------------------------------------------------
// 用户进入比赛房间或游戏时发送限制好友在线功能的消息 wangch 2006.5.23
//----------------------------------------------------------------------
#define GLID_LIMITOURFRIEND	(GLID_BASEROOM+0x000000A1)
//请求 GLREQHEADER header;

//---------------------------------------------------------------------------
// 当玩家进入房间之后，服务器发送这个房间中的游戏桌描述信息给客户端
//---------------------------------------------------------------------------
#define GLID_TABLEDESCRIPTION	( GLID_BASEROOM + 0x000000A2 )
// s->c
typedef struct tagGLReqTableDescription
{
	GLREQHEADER header ;
	int nStart ;		// 这个消息描述的是从这个索引号（从0开始，包括这一桌）开始的游戏桌
	int nEnd ;			// 这个消息描述的是到这个索引号（不包括这一桌）为止的游戏桌
	int nSeatCount ;	// 游戏桌中的座位个数
	// 如果是固定长度的其他信息，直接加到后面即可；如果是变长的信息，那么建议增加一个字段表示这个结构的大小
	// 后续可以加入更多的信息，诸如超级桌主中的信息、游戏桌名字的信息、这个游戏桌只能会员坐下等等
} GLREQTABLEDESCRIPTION , *PGLREQTABLEDESCRIPTION ;

//2.7Avatar用户在游戏房间里变更AvatarDress
#define	GLID_USERCHANGEDRESS27					(GLID_BASEROOM+0x000000A3)
//-------------------------------------------------------------------------------------------------------
//	用户改变自身的物品佩戴
//	请求消息：
//	ackheader
//	string	pszUserName			//改变物品佩戴的用户名
//	WORD	wCount;				//佩戴物品的总数
//	随后跟着wCount个 dwItemID ... dwItemID
//服务器接收到该消息后,将直接把该消息转发给该游戏室所有用户

//glworld客户端发送过来的客户端系统消息
#define GLID_GAMEUSERMACHINEINFO							(GLID_BASEROOM+0x000000A4)
typedef struct tagGLREQGAMEUSERMACHINEINFO
{
	GLREQHEADER header;
	DWORD	dwGLWorldVersion;				//GLWorld的当前版本号
	DWORD   dwGameVersion;					//当前游戏客户端的版本号（游戏的GameID在服务器端可以获得）
	DWORD	dwScreenResolution;				//屏幕分辨率
	WORD	wWindowVersion;					//使用的Windows版本
	WORD	wMemoryCapability;				//当前内存容量(单位M)
	BYTE	byCPUType;						//当前CPU型号
	BYTE	byScreenPixelDepth;				//屏幕颜色位数
	WORD	wCpuSpeed;						//当前CPU主频
}GLREQGAMEUSERMACHINEINFO,*PGLREQGAMEUSERMACHINEINFO;

// 
// glworld->server，用于表明自己支持哪些功能
// 以后尽量使用这个消息，而不是通过检查大厅版本来判断大厅是否支持某个功能
// 这个消息应该在大厅发送版本信息之后发送到服务器端
// 
#define GLID_GLWORLDFACULTY				(GLID_BASEROOM+0x000000A5)
// 按bit取值的功能
#define GLWF_BIT_USEOLDAVATAR			( 1 << 0 )	// 是否使用旧版的Avatar，默认不使用（2.7.0.1之前的版本都是使用旧版Avatar，2.7.0.4之后的版本可能两种都支持）
typedef struct tagGLReqGLWorldFaculty
{
	GLREQHEADER header ;
	DWORD dwFacultyBit ;			// 按bit取值的功能信息，取值为GLWF_BIT_XXX，如果相应的位为1表示大厅支持这个功能
									// 所有的这些功能中，缺省都是对应于相应bit取值为0的状态
} GLREQGLWORLDFACULTY , *PGLREQGLWORLDFACULTY ;

// 
// server->glworld，告知大厅每个房间都有哪些限制。对于某个房间的所有限制而言，都是and的关系。
// 这个消息一般会在玩家进入服务器之后发送给大厅。
// 
#define GLID_ROOMLIMITDESCRIPTION		(GLID_BASEROOM+0x000000A6)
// 限制的信息种类
#define RLD_FIELD_SCORE				(  1 )	// 限制积分，这时nValue取值为具体的分值
#define RLD_FIELD_GAMECOIN			(  2 )	// 限制游戏豆，这时nValue取值为具体的游戏豆数目
#define RLD_FIELD_BREAKRATE			(  3 )	// 限制断线率，这时nValue是断线率百分比*100的数值，比如350表示限制断线率3.5%
#define RLD_FIELD_MEMBERGAMECOUNT	(  4 )	// 限制会员游戏总盘数，这时nValue取值为游戏盘数的值
#define RLD_FIELD_FREEGAMECOUNT		(  5 )	// 限制非会员游戏的总盘数，这时nValue取值为游戏盘数的值
#define RLD_FIELD_MEMBER			(  6 )	// 限制玩家会员状态，这时nValue取值为0（非会员）或者1（会员）
#define RLD_FIELD_PRIVILEGE			(  7 )	// 限制玩家的标志，这时nValue取值为某个标志
#define RLD_FIELD_GAMEVERSION		(  8 )	// 限制游戏版本，这时nValue取值为版本的值，比如0x02030405表示2.3.4.5
#define RLD_FIELD_ROOMVERSION		(  9 )	// 限制大厅版本，这时nValue取值为版本的值，比如0x02030405表示2.3.4.5
#define RLD_FIELD_SEX				( 10 )	// 限制玩家性别，这时nValue取值为0（女性）或者1（男性）
#define RLD_FIELD_RANK				( 11 )	// 限制玩家等级，这时nValue取值为等级的值
#define RLD_FIELD_NETSPEED			( 12 )	// 限制玩家网速，这时nValue取值为网速的值
#define RLD_FIELD_MONEY				( 13 )	// 限制玩家的财富值，这时nValue取值为财富值的数目
// 限制的类型
#define RLD_TYPE_EQUAL	( 1 )	// 限制的值必须等于nValue的值（诸如性别等）
#define RLD_TYPE_MIN	( 2 )	// 限制的值至少是nValue的值（诸如游戏豆）
#define RLD_TYPE_MAX	( 3 )	// 限制的值至多是nValue的值（诸如断线率）
typedef struct tagRoomLimitDesc
{
	int nField ;	// 限制的是什么信息，取值为RLD_FIELD_XXX，对于新增的大厅不能解析的种类，大厅略过即可
	int nType ;		// 限制的类型，取值为RLD_TYPE_XXX
	int nValue ;	// 限制的值，具体限制的值，具体的含义参看GLD_FIELD_XXX中的描述
} ROOMLIMITDESC , *PROOMLIMITDESC ;
typedef struct tagGLReqRoomLimitDescription
{
	GLREQHEADER header ;
	int nSize ;						// 这个结构的大小，大厅应该是从消息头偏移这么多个字节处开始解析消息后跟的数据，
									// 而不要直接使用消息头＋1的方式
	int nRoomCount ;				// 房间的数目
	int nDescSize ;					// 每个描述限制的结构的大小，大厅应该使用这个值，而不是sizeof(ROOMLIMITDESC)，
									// 来作为每一个限制信息的大小（用于定位下一个限制信息时，别使用数组下标的方式）
	// 消息后跟nRoomCount个DWORD信息，表示每个房间都有多少个限制信息
	// 之后再依次跟每个房间的限制信息
} GLREQROOMLIMITDESCRIPTION , *PGLREQROOMLIMITDESCRIPTION ;

//---------------------------------------------------------------------------
//	刷新房间用户人数(隐名房间用)
//---------------------------------------------------------------------------
#define	GLID_REFRESHPLAYERCOUNT				(GLID_BASEROOM+0x000000A7)
typedef struct tagGLRefreshPlayerCount
{
	GLREQHEADER header ;
	WORD		wPlayers;//人数
}GLREFRESHPLAYERCOUNT,*PGLREFRESHPLAYERCOUNT;

//---------------------------------------------------------------------------
//	下发是否使用双通消息
//  说明:
//   1 服务器主动下发这个REQ消息 
//   2 如果客户端启用了互联代理 发上来一个ACK消息头 用于记录 GLACKHEADER header;
//---------------------------------------------------------------------------
#define	GLID_USEWELLNET				(GLID_BASEROOM+0x000000A8)
typedef struct tagUseWellNet
{
	BOOL		bUseWellNet;		//是否使用双通
	WORD		wValve;				//速度阀值
	WORD		wTestSpeedTick;		//测速时间间隔
	WORD		wWNTestSpeedCount;	//代理测速个数	
	WORD		wDCTestSpeedCount;	//直连测速个数
	WORD		wSendSpeedInfoTick; //发送测速报告时间间隔
}USEWELLNET,*PUSEWELLNET;



typedef struct tagGLReqUseWellNet
{
	GLREQHEADER header ;
	USEWELLNET	stUwn;
}GLREQUSEWELLNET,*PGLREQUSEWELLNET;


//---------------------------------------------------------------------------
// 上发双通后的速度信息	  有两个地方使用此消息 一个是客户端给游戏服务器 另外一个游戏服务器给互联记录服务器
//---------------------------------------------------------------------------
#define	GLID_WELLNETSPEEDINFO				(GLID_BASEROOM+0x000000A9)
typedef struct tagGLReqWellNetSpeedInfo
{
	GLREQHEADER header ;
	WORD		wWellNetSpeed;	//使用代理速度
	WORD		wDCSpeed;		//使用直联测度速度 0：表示不通
	WORD		wType;			//连接类型
}GLREQWELLNETSPEEDINFO,*PGLREQWELLNETSPEEDINFO;


typedef struct tagGLReqWellNetSpeedInfoEx
{
	GLREQHEADER header ;
	DWORD		dwIP;//IP
	DWORD		dwGameID;
	time_t		tmTime;//时间
	char		szUserName[GL_BUFLEN_USERNAME];
	WORD		wWellNetSpeed;	//使用代理速度
	WORD		wDCSpeed;		//使用直联测度速度 0：表示不通
	WORD		wType;			//连接类型
}GLREQWELLNETSPEEDINFOEx,*PGLREQWELLNETSPEEDINFOEx;

//---------------------------------------------------------------------------
// 游戏服务器给互联记录服务器 人数统计信息
//---------------------------------------------------------------------------
#define	GLID_WELLNETPLAYERSINFO				(GLID_BASEROOM+0x000000AA)
typedef struct tagGLReqWellNetPlayersInfo
{
	GLREQHEADER header ;
	DWORD	dwGameID;//游戏ID
	int	cnWellProxyPlayer;//使用代理人数
	int	cnRoomPlayer;//房间总人数
}GLREQWELLNETPLAYERSINFO,*PGLREQWELLNETPLAYERSINFO;


//---------------------------------------------------------------------------
// 换桌子和座位
//---------------------------------------------------------------------------
#define	GLID_CHANGESEAT						(GLID_BASEROOM+0x000000AB)
typedef struct tagGLReqChangeSeat
{
	GLREQHEADER header ;
	int nTable;										// 桌号  <=0 为本桌  >0为要转换的桌号
	BYTE uchSeat;									// 座位号
	BOOL bWatch;									// 旁观
}GLREQCHANGESEAT,*PGLREQCHANGESEAT;


typedef struct tagGLAckChangeSeat
{
	GLACKHEADER header ;
	BYTE uchSeat;									// 换回的座位号
	BOOL bWatch;									// 旁观
	char	szChatRoomName[GL_BUFLEN_ROOMNAME];		// Chat Room Name
}GLACKCHANGESEAT,*PGLACKCHANGESEAT;


#define USERROOMSETTING_GROUP	4096
typedef struct tagGLUSERDEMANDINFO
{
	int	nNewBreakRate;	// 新人断线率
	int	nNewWinRate;	// 新人胜率
	DWORD	dwNewSpeed;	//新人网速
	int	nNewScoreOrGameCoin;	//新人积分
	int	nNewMember;	//新人会员
	int	nOldScore;	//老人积分
}GLUSERDEMANDINFO,*PGLUSERDEMANDINFO;

typedef struct tagGLUSERROOMSETTING
{
	BOOL bPlayWithNotFree;					// 只与会员玩，会员功能
	BOOL bNoPlayWithEnemy;					// 不和不受欢迎玩家玩，会员功能
	int nBreakRate;						// 断线率限制，0为不限制
	DWORD dwNetSpeed;						// 网速限制，0为不限制
	long lScore;						// 积分限制，0为不限制
	long lAbsScore;						// 积分差限制，0为不限制
	int  nWinRate;						// 胜率限制，0为不限制
	BOOL bNotDefenceFriend;					// 不限制朋友
	int nIPMask;						// IP地址限制，0为不限制
	BOOL bLimitScore;					//是否限制积分
}GLUSERROOMSETTING,*PGLUSERROOMSETTING;


typedef struct tagFRIENDDATA
{
	char szUserName[GL_BUFLEN_USERNAME];
	int nType;//1为朋友，2为不受欢迎
}GLFRIENDDATA,*PGLFRIENDDATA;

//用户房间设置记录
typedef struct tagUSERROOMSETTINGINFO
{
	char	szUserName[GL_BUFLEN_USERNAME];		//用户名
	DWORD	dwCheckSum;
	DWORD	dwSettingLastUpdateBase;		//room设置最后更新时间
	DWORD	dwFriendLastUpdateBase;			//好友关系设置最后更新时间
	time_t	timeLeave;				//离开时间
	GLUSERROOMSETTING stUserSettingInfo;		//用户设置信息
	int 		nFriendCount;			//朋友个数
	PGLFRIENDDATA	pFrienData;			//朋友数据
}USERROOMSETTINGINFO,*PUSERROOMSETTINGINFO;

typedef struct tagUSERROOMSETTINGGROUPINFO
{
	CRITICAL_SECTION	cs;
	DWORD			dwCount;
	PUSERROOMSETTINGINFO	pUserRoomSetList;
}USERROOMSETTINGGROUPINFO,*PUSERROOMSETTINGGROUPINFO;


//服务器下发服务器上的时间戳
#define	GLID_USERSETTINGTIME				(GLID_BASEROOM+0x000000AC)
typedef struct tagGLREQUSERSETTINGTIME
{
	GLREQHEADER	header;
	DWORD	dwSettingLastUpdateBase;		//room设置最后更新时间
	DWORD	dwFriendLastUpdateBase;			//好友关系设置最后更新时间
	DWORD	dwFriendCount;					//需要上传好友列表个数
	DWORD	dwEnemyCount;					//需要上传不受欢迎列表个数
}GLREQUSERSETTINGTIME,*PGLREQUSERSETTINGTIME;



//用户房间设置
#define	GLID_USERROOMSETTINGINFO				(GLID_BASEROOM+0x000000AD)


typedef struct tagGLREQUSERROOMSETTING
{
	GLREQHEADER	header;
	GLUSERROOMSETTING	stUserSettingInfo;			//用户设置信息
}GLREQUSERROOMSETTING,*PGLREQUSERROOMSETTING;

typedef struct tagGLACKUSERROOMSETTING
{
	GLACKHEADER	header;
	DWORD	dwSettingLastUpdateBase;		//room设置最后更新时间
}GLACKUSERROOMSETTING,*PGLACKUSERROOMSETTING;



//更改用户好友用户名
#define	GLID_UPDATEFRIENDUSERNAME				(GLID_BASEROOM+0x000000AE)


typedef struct tagGLREQUPDATEFRIENDUSERNAME
{
	GLREQHEADER	header;
	int		nCount;			//不受欢迎用户名
}GLREQFRIENDUSERNAME,*PGLREQUPDATEFRIENDUSERNAME;
//后跟nCount*GLFRIENDDATA


typedef struct tagGLACKUPDATEFRIENDUSERNAME
{
	GLACKHEADER	header;
	DWORD	dwFriendLastUpdateBase;		//不受欢迎设置最后更新时间
}GLACKUPDATEFRIENDUSERNAME,*PGLACKUPDATEFRIENDUSERNAME;


//通知游戏桌已经开始游戏了 让room刷新桌子状态
#define	GLID_UPDATETABLEPLAYING				(GLID_BASEROOM+0x000000AF)
typedef struct tagGLUPDATETABLEPLAYING
{
	GLREQHEADER	header;
	int		nCount;			//后跟nCount个tableID 
}GLREQUPDATETABLEPLAYING,*PGLREQUPDATETABLEPLAYING;

// << added by zengxi 2011.02.15
// 客户端在登录之前发送自己的登录位置信息给服务器，以便服务器可以准确的知道客户端来自哪里，从而进行相应的统计。
// 这个消息应该是玩家在发送 GLID_LOGIN 消息之前发送
// 对于pc客户端就不用发送了，因为默认是pc客户端
#define GLID_USERLOGINPOS	( GLID_BASEROOM + 0x000000BC )
enum USER_LOGIN_TYPE
{
	USER_LOGIN_TYPE_PCCLIENT = 1 ,	// pc客户端，这也是默认值
	USER_LOGIN_TYPE_FLASH    = 2 ,	// flash客户端
	USER_LOGIN_TYPE_ANDROID  = 3 ,	// Android客户端
	USER_LOGIN_TYPE_IPAD     = 4 ,	// iPad客户端
	USER_LOGIN_TYPE_IPHONE   = 5 ,	// iPhone客户端
	USER_LOGIN_TYPE_MAX ,
};
enum USER_LOGIN_POS
{
	USER_LOGIN_POS_PCCLIENT           = 1 ,		// pc客户端，这也是默认值
	USER_LOGIN_POS_WEB_OURGAME        = 2 ,		// 联众网络
	USER_LOGIN_POS_WEB_OURGAME_FAMILY = 3 ,		// 联众家园
	USER_LOGIN_POS_WEB_GAME           = 4 ,		// 游戏网站
};
// 用于记录玩家登录位置信息的结构
typedef struct tagUserLoginPos
{
	int nLoginType ;	// 客户端登录的类型，取值为：pc客户端、flash客户端等
	int nLoginPos ;		// 客户端登录的位置（或渠道号），取值为：pc客户端、联众网络、联众家园、游戏网站等
						// 当nLoginType取值为1/2的时候，这里是表示登录的位置；
						// 当nLoginType取值为3/4/5的时候，这里是表示渠道号；
	int nLanguage ;		// 语言
	int nResolution ;	// 分辨率
	char	szRoleName[GL_BUFLEN_ROLENAME]; 
} USERLOGINPOS , *PUSERLOGINPOS ;
typedef struct tagGLUSERLOGINPOS
{
	GLREQHEADER header ;		//   header.dwType =GLID_USERLOGINPOS | GLID_REQ
	USERLOGINPOS pos ;	// 位置信息
} GLREQUSERLOGINPOS , *PGLREQUSERLOGINPOS ;
// >> added by zengxi 2011.02.15

typedef struct tagGLACKUSERLOGINPOS
{
	GLACKHEADER header ;	//header.dwType = GLID_USERLOGINPOS| GLID_ACK ;
	//header.dwResult = GLBIT_FAIL ;   //  
	//header.dwResult = GLBIT_SUCCESS ;   // 
}GLACKUSERLOGINPOS,*PGLACKUSERLOGINPOS ;


typedef struct tagROLEINFOLIST
{
	char szUserName[GL_BUFLEN_USERNAME];				// 用户名
	char szRoleName[GL_BUFLEN_ROLENAME];				// 角色名
	
}ROLEINFOLIST,FAR *PROLEINFOLIST;

//房间里所有用户的id和rolename
#define	GLID_ROOMROLEINFO						(GLID_BASEROOM+0x000000B0)

typedef struct tagGLACKROLEINFOLIST
{
	GLACKHEADER header;								//header.dwType = GLID_ROOMROLEINFO| GLID_ACK ;
	WORD wPlayerNum;								//用户数,后跟n个ROLEINFOLIST
}GLACKROLEINFOLIST,*PGLACKROLEINFOLIST;


//后来者进入房间的
#define	GLID_ADDPLAYER_WEB					(GLID_BASEROOM+0x000000B1)

//---------------------------------------------------------------------------
//	增加用户应答
//---------------------------------------------------------------------------
typedef struct tagGLACKADDPLAYERWEB
{
	GLACKHEADER header;									////header.dwType = GLID_ADDPLAYER_WEB| GLID_ACK ;
	char szUserName[GL_BUFLEN_USERNAME];				// 用户名
	char szRoleName[GL_BUFLEN_ROLENAME];				// 角色名
}GLACKADDPLAYERWEB, *PGLACKADDPLAYERWEB;
 

//为网页捉鱼添加坐下失败消息,收到此消息表示坐下失败了
#define	GLID_SITFAIL_WEB					(GLID_BASEROOM+0x000000B2)

//---------------------------------------------------------------------------
//	增加用户应答
//---------------------------------------------------------------------------
typedef struct tagGLACKSITFAILWEB
{
	GLACKHEADER header;									////header.dwType = GLID_SITFAIL_WEB| GLID_ACK ;
	
}GLACKSITFAILWEB, *PGLACKSITFAILWEB;

#endif	// __GLROOM_H__
