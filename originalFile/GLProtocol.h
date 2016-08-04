/*---------------------------------------------------------------------------
 GlobalLink Games Client/Server protocol
 联众互联网络游戏 客户/服务器端公用消息定义及结构
 
 整理: jjwk 1998.3.2
 
 注：所有宏定义均以 GL_ 开头
     所有结构定义全部大写，并以 GL 开头,前面加 *P 表示预定义指针
     GLID_ 开头表示信息包分类ID
     GLBIT_ 开头表示应答结果位定义
 
	1998.4.21 AddID GLID_BASECHNCHESS	by SHi Lei
	1998.5.24 AddID GLID_BASEJUMP	by jjwk
---------------------------------------------------------------------------*/

#ifndef __GLPROTOCOL_H__
#define __GLPROTOCOL_H__

#include <time.h>
//---------------------------------------------------------------------------
//	1.以 GL_BUFLEN_ 开头
//	2.字符串长度定义，由于字符串都以0结尾，因此实际可使用的长度为定义值减1
//  3.最好长度定义能被4整除，解决 32 位环境下结构空间被自动修正的问题
//---------------------------------------------------------------------------
#define GL_BUFLEN_HOST					(39+1)	// HOST 默认长度


#define	GL_BUFLEN_USERNAME				(19+1)	// 用户名长度
#define GL_BUFLEN_USERNAME_CHN			(12+1)	// 6个汉字的长度 wuqy add 2007.4.5(中文ID专用)
#define GL_BUFLEN_NICKNAME				(19+1)	// Nike Name 长度
#define	GL_BUFLEN_PASSWORD				(15+1)	// 密码长度
#define	GL_BUFLEN_MD5				(32+1)	// md5字符串长度
#define GL_BUFLEN_PASSWORD_MD5			GL_BUFLEN_MD5	//(32+1) md5密码字符串长度
#define	GL_BUFLEN_SERIALNUMBER			(15+1)	// 序列号长度
#define GL_BUFLEN_EMAIL					(63+1)	// EMAIL 长度
#define	GL_BUFLEN_HTML					(255+1)	// HTML 广告页地址
#define	GL_BUFLEN_PRESENTNOTE			(47+1)	//avatar赠送物品留言
#define GL_BUFLEN_NIPID					(63+1)	// nipID的长度，用了登陆nip服务器，做唯一的标识
#define GL_BUFLEN_BCNAME				(63+1)	// 转播名称来自GLBroadcastProtocol.h的BROADCAST_GAMENAME_LEN定义
#define GL_BUFLEN_TGUSERNAME			(63+1)	// 第三方游戏用户名长度


#define GL_BUFLEN_REALNAME				(19+1)	// 姓名
#define GL_BUFLEN_STATE					(19+1)	// 省份
#define GL_BUFLEN_CITY					(19+1)	// 市（地区）
#define GL_BUFLEN_POSTALCODE			(11+1)	// 邮政编码
#define GL_BUFLEN_WHEREPLAY				(19+1)	// 在哪里上网
#define GL_BUFLEN_LOVEGAME				(49+1)	// 喜欢的游戏
#define GL_BUFLEN_FAVOR					(49+1)	// 兴趣爱好
#define GL_BUFLEN_COMPANY				(39+1)	// 单位
#define GL_BUFLEN_DEPART				(19+1)	// 部门
#define GL_BUFLEN_ADDRESS				(39+1)	// 地址
#define GL_BUFLEN_PHONE					(31+1)	// 电话

#define	GL_BUFLEN_GAMENAME				(31+1)	//游戏英文名, 如GO
#define	GL_BUFLEN_GAMEFULLNAME			(63+1)	//游戏完整名, 如围棋

#define	GL_BUFLEN_SERVERNAME			(39+1)	//服务器名字长度,包括聊天室
#define	GL_BUFLEN_ROOMNAME				(39+1)	//房间名字长度,包括聊天室

#define	GL_BUFLEN_RANKNAME				(15+1)	//等级名称长度

#define GL_BUFLEN_ASCTIME				(27+1)	// 标准 asctime 长度
#define GL_BUFLEN_SAVEINDEXNAME			(63+1)	// 标准存盘 Index 字串长度

#define	GL_BUFLEN_FIELDNAME				(15+1)	//字段名长度

#define	GL_BUFLEN_PERSONALID			(19+1)	//身份证号码、二级密码

#define	GL_BUFLEN_VERSION				(39+1)	//版本号
#define	GL_BUFLEN_NAMES					(59+1)

#define	GL_BUFLEN_TITLE					(255+1)

#define	GL_BUFLEN_FACTION				(19+1)	//帮派
#define	GL_BUFLEN_DUTY					(19+1)	//职务
#define	GL_BUFLEN_MATCHRANKNAME			(19+1)	//比赛级别

#define	GL_BUFLEN_IP					(15+1)
#define	GL_BUFLEN_ACTION				(29+1)
#define	GL_BUFLEN_COMMENT				(63+1)
#define	GL_BUFLEN_COMMENT128			(127+1)//对于太长的用户名，64位的comment不够长 wuqy add 2006.6.7

#define	GL_BUFLEN_MOBILENO				GL_BUFLEN_USERNAME
#define	GL_BUFLEN_MANUFACTURER			(19+1)
#define	GL_BUFLEN_MODEL					(19+1)
#define GL_BUFLEN_SMCONTENT				(120+1)	//手机短信内容长度

#define GL_BUFLEN_CARDNO				(39+1)	//会员卡号码长度
#define GL_BUFLEN_CARDPASSWORD			(19+1)	//会员卡密码长度

#define	GL_BUFLEN_OLDINFO				(59+1)	//原来的旧信息

#define GL_BUFLEN_TICKET				(128)	// ticket

#define GL_BUFLEN_IDCCHECKSUM			(19+1)	//身份证标识号码
#define GL_BUFLEN_IDCCHECKSUMSTRING		(35+1)	//MD5验证码字符串，32字节字符串

#define GL_BUFLEN_PROMPTMSG			(1024+1)//提示消息


//obis系统要求在会员资格和联众币的注册消费接口增加数据列
#define GL_BUFLEN_OBIS_CHANNELID		(11+1)//8		//渠道编号长度
#define GL_BUFLEN_OBIS_PRODUCTID		(63+1)//60		//产品编号长度（产品为mapping编号时，m@productid）
#define GL_BUFLEN_OBIS_FLOWNUMBER		(63+1)//60		//流水号长度
#define GL_BUFLEN_OBIS_PRODUCTREMARK	(63+1)//60		//产品类型注释长度

#define	GL_MAX_GAMES					100		//最多游戏种类
#define	GL_MAX_SERVERSPERGAME			50		//一种游戏最多具有的Server数
#define	GL_MAX_ROOMSPERGAME				100		//一种游戏最多具有的Room数
#define	GL_MAX_PLAYERSPERROOM			500		//一个Room内最多可以容纳的人数
#define GL_MAX_PLAYERSPERTABLE			6		//每张桌子最多可以有多少个Player
#define GL_MAX_WAITEVENT				10		//最多同时等待多少个event(一个client)

#define	GL_MIN_USERNAME					2		//用户名最短长度
#define	GL_MIN_PASSWORD					3		//密码最短长度
#define	GL_MIN_ROOMNAME					2		//房间名最短长度

//---------------------------------------------------------------------------
//	比赛系统相关
//---------------------------------------------------------------------------
#define GL_BUFLEN_TEAMNAME				(39+1)	//队名长度
#define GL_BUFLEN_ROOMPROPERTY			64		//房间属性

//---------------------------------------------------------------------------
//	密码系统相关----add by zzh.
//---------------------------------------------------------------------------
#define	GL_BUFLEN_DBNAME				(19+1)	// 数据库名长度
#define	GL_BUFLEN_DBUSERNAME			(19+1)	// 数据库用户名长度
#define	GL_BUFLEN_DBPASSWORD			(19+1)	// 数据库密码长度
#define	GL_BUFLEN_ODBCNAME				(19+1)	// ODBC名长度

//---------------------------------------------------------------------------
//	用户和桌子状态
//---------------------------------------------------------------------------
#define	GL_STATUS_EMPTY					0	//空桌子
#define	GL_STATUS_STANDING				0	//用户正站在Room内
#define	GL_STATUS_WAITING				1	//用户在等待对手，或桌子有人但人数不足，还没有开始游戏
#define	GL_STATUS_PLAYING				2	//正在玩
#define	GL_STATUS_WATCHING				3	//用户正在观看别人玩
#define	GL_STATUS_IDLEING				4	//用户正空闲，5分钟内未进行状态改变或聊天

#define	GL_ADVERT_WIDTH					200	//客户端广告页宽度
#define	GL_ADVERT_HEIGHT				60	//客户端广告页高度

#define	GL_TEXTADVERT_WIDTH				120	//客户端广告页宽度
#define	GL_TEXTADVERT_HEIGHT			60	//客户端广告页高度

#define	GL_ROOMADVERT_WIDTH				468	//客户端广告页宽度
#define	GL_ROOMADVERT_HEIGHT			60	//客户端广告页高度

//有关加密狗数据长度定义
#define GL_SOFTDOG_RANDOMLEN			16
#define GL_SOFTDOG_MD5RESULTLEN			16


//---------------------------------------------------------------------------
//	1.服务器与客户端之间进行数据交换时，每种信息包必须包含一个包ID，总分为二大
//	  类，即请求类和应答类
//	2.请求类ID必须以GLID_REQ开头
//	3.应答类ID必须以GLID_ACK开头
//---------------------------------------------------------------------------
#define GLID_REQ						0x00000000	// 请求符
#define GLID_ACK						0x80000000	// 应答符
#define	GLID_COMPRESS					0x40000000	// 压缩数据包


//---------------------------------------------------------------------------
//	1.根据需要将ID进行细分，每种ID都定义一个基础ID，实际ID在此基础之上进行定义
//---------------------------------------------------------------------------
#define GLID_BASEREGISTER				0x00000000	// 注册类
#define	GLID_BASEROOM					0x00000100	// 与Room相关的ID
#define GLID_BASEGAMES					0x00000200	// 游戏中的通用信息类
#define GLID_BASECHAT					0x00000300	// 聊天室
#define GLID_BASEMSG					0x00000400	// 即时通迅, byq 2002.11.17
#define GLID_BASEB2B					0x00000500	// B2B, byq 2002.12.02
#define GLID_BASESERVICE				0x00000600	// 服务器进程间通讯		！！！千万不要向 GLID_BASESERVICE 的 255以上再加消息了，已经和其他的消息段重了 wangym 2008.3.25
//#define GLID_BASESERVICEEX				0x00040000	//重新分配一个段给基本服务消息使用，原有GLID_BASESERVICE早已越界使用，引起消息重复 wangym 2008.3.25
#define GLID_BASEDOWNLOAD				0x00000700	// 服务器进程间通讯	
#define GLID_BASEMASTERROOM				0x00000800  // 网管室
#define	GLID_BASESM						0x00000900	// 短信
#define	GLID_BASETASK					0x00000a00	// 任务管理
#define	GLID_BASEGRAPHCHAT				0x00000b00	// 图形聊天
#define GLID_BASEMATCH					0x00000c00	// 比赛系统
#define GLID_BASEMAIL  				    0x00000d00	// 邮件群发系统
#define GLID_BASEADSVR 				    0x00000e00	// 广告系统
#define GLID_BASEPASSWORD			    0x00000f00	// 密码系统

#define GLID_BASEGO						0x00001000	// 围棋
#define GLID_BASEUPGRADE				0x00002000	// 升级
#define GLID_BASEHEARTS					0x00003000	// 拱猪
#define GLID_BASECHNCHESS				0x00004000	// 中国象棋
#define GLID_BASEJUMP					0x00005000	// 跳棋
#define GLID_BASERUNOUT					0x00006000	// 跑得快
#define GLID_BASEINTCHESS				0x00007000	// 国际象棋
#define GLID_BASEJUNQI					0x00008000	// 军棋
#define GLID_BASEBRIDGE					0x00009000	// 桥牌
#define GLID_BASECNACHESS				0x0000A000	// 中国象棋暗棋
#define GLID_BASEMJ						0x0000B000	// 麻将
#define GLID_BASETETRIS					0x0000C000	// 俄罗斯方块
#define GLID_BASECUTOUT					0x0000D000	// 锄大地
#define GLID_BASESQUEEN					0x0000E000	// 红心大战
#define GLID_BASEWZQ					0x0000F000  // 五子棋
#define GLID_BASESHOWHAND				0x00010000	// 梭哈
#define GLID_BASEDOUBLE					0x00011000	// 双扣
#define GLID_BASELORD					0x00012000	// 斗地主
#define GLID_BASELORD3					0x00012100	// 斗地主3		wym 2005.8.23
#define GLID_BASETHREETOONE				0x00013000	// 三打一
#define GLID_BASEGOUJI					0x00014000	// 够级
#define	GLID_BASELOG					0x00015000	// Log数据记录
#define	GLID_BASEBUILDPIC				0x00016000	// 拼图
#define	GLID_BASEFLYCHESS				0x00017000	// 飞行棋
#define	GLID_BASEBILLIARD				0x00018000	// 台球
#define GLID_BASEATOM					0x00019000	// 原子
#define GLID_BASEK007					0x0001A000	// 憋七
#define GLID_BASEK105					0x0001B000	// 五十K
#define GLID_BASEOTHELLO				0x0001C000	// 黑白棋
#define GLID_BASECHAODP					0x0001D000	// 炒地皮	 wym 2002-1-31 9:42:17
#define GLID_BASEBOMBMAN				0x0001E000	// 炸弹人	 wym 2002-4-3 16:57:48
#define GLID_BASEK003					0x0001F000	// 敲三家	 wym 2002-5-20 10:23:24
#define GLID_BASEDIGPIT					0x00020000	// 挖坑		wuqy 2004-2-24
#define GLID_BASEUSERCACHE				0x00021000	// 用户信息记录读取和更新服务, baoyq 2004.4.19
#define GLID_BASEGAMECACHE				0x00022000	// 用户游戏记录读取和更新服务, baoyq 2004.4.19
#define GLID_BASEMBAUTHENTICATE			0x00023000	// 手机游戏鉴权服务器 wym 2004.4.20
#define GLID_BASEMBPROXY				0x00024000	// 手机游戏代理服务器和手机通讯的消息 wym 2004.4.20
#define GLID_BASEGOLDFLOWER				0x00025000	// 炸金花	wuqy 2004-6-2
#define GLID_BASEBAOHUANG				0x00026000	// 保皇		wuqy 2004-6-2
#define GLID_BASEBLACKJACK				0x00027000	// BlackJack（21点）	wuqy 2004-6-2
#define GLID_BASESITUAN					0x00028000	// 四团	wuqy 2004-6-2
#define GLID_BASESLOT					0x00029000	// 碰运气	lvch 2004-6-21
#define GLID_BASESEAWAR					0x0002A000	// 海站棋	wuqy 2004-8-4
#define GLID_BASECARIBBEAN				0x0002B000	// 加勒比海宝藏	wuqy 2004-8-4
#define GLID_BASEJUNQIHUN				0x0002C000	// 混战军棋	wuqy 2004-8-4
#define GLID_BASEPOPDRAGON				0x0002D000	// 泡泡龙 wuqy 2004-8-19
#define GLID_BASESNAKE					0x0002E000	// 贪吃蛇 wuqy 2004-8-19
#define GLID_BASEROLL					0x0002F000	// 打滚子 wuqy 2004-8-30
#define GLID_BASEGUANSJ					0x00030000	// 关三家 wuqy 2004-8-30
#define GLID_BASELORDWH					0x00031000	// 武汉斗地主 wuqy 2004-9-17
#define GLID_BASETANK					0x00032000	// 坦克大战(外包游戏) wuqy 2004-11-29
#define GLID_BASECRAZYGF				0x00033000	// 疯狂赢三张 chairmin 2007-9-11
#define GLID_BASETEXASPOKER				0x00034000	// 德洲扑克 chairmin 2007-11-14
#define GLID_BASEMAJIANGT				0x00035000	// 疯狂二人麻将 chairmin 2008-1-9
#define GLID_BASEMAJIANGZS				0x00035100	// 钻石麻将 chairmin 2008.4.10

#define GLID_BASEBROADCAST				0x00001100	// 转播系统通用消息 wym 2005.4.5
#define GLID_BASEBROADCASTROOM			0x00001200	// 转播大厅 wym 2005.4.5
#define GLID_BASEBROADCASTWEIQI			0x00001300  // 围棋转播 wym 2005.4.5
#define GLID_BASEBROADCASTXIANGQI		0x00001400	// 象棋转播 wym 2005.4.5

#define GLID_BASEITEM					0x00002100	// 道具系统 wym 2005.12.6

#define GLID_BASEPIPEUICOM				0x00002A00	// 客户端公共通讯模块消息,客户端之间使用不会到服务器 wym 2007.9.12

#define GLID_BASECHECKCC				0x00003100	// 游戏豆充值检查服务 wym 2005.7.15
#define GLID_BASEGIGN					0x00003200	// 反外挂服务器 wuqy 2006.1.4
#define GLID_BASEINDICT					0x00003300	// 投诉服务器 wuqy 2006.2.22
#define GLID_BASEHBZHA					0x00003400	// 河北捉黑A wuqy 2006.3.17
#define GLID_BASEMONITOR				0x00003500	// 监控服务器 wangch 2006.4.12
#define GLID_BASEBET					0x00003600	// 竞猜服务器 wuqy 2006.8.4
#define GLID_BASESUBUSERCACHE			0x00003700	// Sub用户信息记录读取和更新服务, wuqy 2006.11.23
#define GLID_BASEIDCDB					0x00003800	// IDC监控 wuqy 2006.11.29
#define GLID_BASEIDCMONITOR				0x00003900	// IDC监控 wuqy 2006.11.29
#define GLID_BASESOHUGHOSTUSERCACHE		0x00003A00	// SohuGhost用户信息记录读取和更新服务, wuqy 2006.12.1
#define GLID_BASETOMGHOSTUSERCACHE		0x00003A00	// TomGhost用户信息记录读取和更新服务, wuqy 2007.1.4
#define GLID_BASESINAGHOSTUSERCACHE		0x00003A00	// SinaGhost用户信息记录读取和更新服务, wuqy 2007.4.29
#define GLID_BASECONTROLMONITOR			0x00003B00	// 同步监控服务器 wangcheng 2007.1.29

#define GLID_BASELUCKYCOIN				0x00004100	// 幸运币产品相关的消息定义	by cobra 20070920
#define GLID_BASEUSERIMAGE				0x00004200	// 游戏形象消息定义 chairmin 2007.11.2
/*
#define GLID_BASESERVICEEX				0x00005000	//重新分配一个段给基本服务消息使用，原有GLID_BASESERVICE早已越界使用，引起消息重复 chairmin 2007.11.30*/
#define GLID_BASESERVICEEX				0x00040000	//重新分配一个段给基本服务消息使用，原有GLID_BASESERVICE早已越界使用，引起消息重复 wangym 2008.3.25
#define GLID_BASEDBSVR					0x00041100	// dbsvr使用的消息段 wangym 2008.3.25

#define GLID_BASEHISTORY				0x00080000	// 统一的历史与存盘管理系统 wuqy 2004-12-15
#define GLID_PDB_CHESS					0x00081000	// 个性数据库功能，棋类使用 chairmin 2008-12-15
#define GLID_PDB_MAJIANG				0x00082000	// 个性数据库功能，麻将使用(钻石麻将需求) chairmin 2008-12-29

//Gaoy, 2004.02.13
#define GLID_BASENEW					0x000FB000	//新老系统接口消息

#define GLID_BASESM2					0x000FD000	// 短信平台第二个段 0xfd000~0xff000 8192个 wym 2003-9-17

#define GLID_BASESAMPLE					0x000FF000	// 空模板游戏  wym 2001-12-4 16:22:56

// 全屏广告通道和普通广告通道的分界值  wym 2002-4-12 17:35:17
#define GLID_BASEADVERTLARGE			0x00100000	// 大于等于这个值是全屏广告 小于这个值是普通广告
#define GLID_BASEADVERTIMAGE			0x00400000  // Image广告  用GameID|GLID_BASEADVERTIMAGE 定义该值
#define GLID_BASEADVERTNORMAL			0x00000000	// 普通广告

//无线
#define	GLID_BASEMOBILE					0x03000000	//此值以上已被无线使用 chairmin 2007.6.6


// add by zhp 2014/04/25
#define GL_BUFLEN_ROLENAME				(79+1)
// add end zhp

//---------------------------------------------------------------------------
//	其他标准情况定义
//---------------------------------------------------------------------------
#define GLBIT_FAIL						0x00000000	// 失败
#define GLBIT_SUCCESS					0x00000001	// 成功

//---------------------------------------------------------------------------
//	客户端请求包和服务器端应答包除外信息包的头结构
//---------------------------------------------------------------------------
typedef struct tagGLHEADER
{
	DWORD dwType;				// 请求类型ID
	DWORD dwLength;				// 实际数据长度(不包括本请求头的长度2个DWORD)
}GLHEADER, *PGLHEADER;

//---------------------------------------------------------------------------
//	所有客户端请求包的头
//---------------------------------------------------------------------------
typedef struct tagGLREQHEADER
{
	DWORD dwType;				// 请求类型ID
	DWORD dwLength;				// 实际数据长度(不包括本请求头的长度2个DWORD)
}GLREQHEADER, *PGLREQHEADER;

// hangame的请求头 wym 2004.12.16
typedef struct tagGLREQHGHEADER
{
	DWORD dwType;				// 请求类型ID
	DWORD dwLength;				// 实际数据长度(不包括联众请求头的长度2个DWORD)

	DWORD dwSeqID;				// 消息序列号，这是hangame特殊要求的
}GLREQHGHEADER, *PGLREQHGHEADER;

//---------------------------------------------------------------------------
//	所有服务器应答包的头
//---------------------------------------------------------------------------
typedef struct tagGLACKHEADER
{
	DWORD dwType;				// 类型ID
	DWORD dwLength;				// 实际数据长度(不包括本应答头的长度3个DWORD)
	DWORD dwResult;				// 按位定义的结果
}GLACKHEADER, *PGLACKHEADER;

// 给hangame的应答头 wym 2004.12.16
typedef struct tagGLACKHGHEADER
{
	DWORD dwType;				// 类型ID
	DWORD dwLength;				// 实际数据长度(不包括联众应答头的长度3个DWORD)
	DWORD dwResult;				// 按位定义的结果

	DWORD dwSeqID;				// 消息序列号，和req中的值相同，这是hangame特殊要求的
	DWORD dwDummy;				// 没有用，好像为了对齐，这是hangame特殊要求的
}GLACKHGHEADER, *PGLACKHGHEADER;

#define	GLID_SHAREMSG			0xffeeddcc
#define GLID_STRLINEMSG			0xAABBCCDD		//字符流消息 CGLLineClient使用
#define GLID_SOCKETMONIT		0x0000eeee		//socket监控消息


//---------------------------------------------------------------------------
//	内存共享数据包
//---------------------------------------------------------------------------
typedef struct tagGLSHAREMSG
{
	DWORD dwMagic;				// 标志字，必须是与消息不一致的统一值，GLID_SHAREMSG
	DWORD dwCount;				// 共享计数，为0时可以删除
}GLSHAREMSG,*PGLSHAREMSG;

#define	GL_MAX_LOBBYCHAT			20

#define	GL_CHAT_MAPFILENAME_MAIN	"GL_MF_CPM"
#define	GL_CHAT_MAPFILENAME_LOCAL	"GL_MF_CPL"
#define	GL_CHAT_MUTEX_MAIN			"GL_MU_CPM"
#define	GL_CHAT_MUTEX_LOCAL			"GL_MU_CPL"
#define	GL_CHAT_MAPFILENAME_LOBBY	"GL_MF_CML"

#define GL_LOBBYFINDGAME_MESSAGE	"GL_LOBBYFINDGAME_MESSAGE_ID"
#define	GL_GAME_PRIVATEDATA			0xFECE

//---------------------------------------------------------------------------
//	已经启动的游戏室及客户端信息结构定义
//---------------------------------------------------------------------------
#define	GL_MAX_ROOMCOUNT				20		//允许同时启动的游戏室数量
#define	GL_MAX_COPLAYER					20		//在一盘游戏中游戏者和旁观的最多数量，仅用于避免作弊而设，实际没有这个限制
#define	GL_BUFLEN_WNDTITLE				(39+1)	//窗口标题的最大长度
typedef struct tagROOMRECINFO
{
	HWND hwnd;									//Room的窗口句柄
	char szWndTitle[GL_BUFLEN_WNDTITLE];		//Room的窗口标题
	DWORD idGame;								//游戏ID
	char aszCoplayer[GL_MAX_COPLAYER][GL_BUFLEN_USERNAME];
	char szRoomChatName[GL_BUFLEN_ROOMNAME];	//游戏室聊天室的名字
	char szClientChatName[GL_BUFLEN_ROOMNAME];	//游戏
}ROOMRECINFO,*PROOMRECINFO;

typedef struct tagLOCATEINFO
{
	char szGameName[GL_BUFLEN_GAMENAME];
	char szServerName[GL_BUFLEN_SERVERNAME];
	char szRoomName[GL_BUFLEN_ROOMNAME];
	int  nTable;
}LOCATEINFO,*PLOCATEINFO;

//add by lvch 2003/12/06 for avatar
#define	GL_MAXAVATARDRESSCOUNT			64				//Avatar最大的穿戴数量
#define	GL_MAXAVATARSTYLECOUNT			128				//Avatar最大的类型数目
#define	GL_MAXAVATARCTRLCOUNT			64				//最大的Avatar控件数目
#define	GL_AVATARCTRLNOTIFYMSG			(WM_USER + 142)	//通知Avatar控件消息
#define	GL_AVATARCTRLADDONEBUBBLE		(WM_USER + 143)	//通知Avatar控件消息,指定的游戏玩家获得一个游戏泡泡
typedef struct tagGL_AVATARCTRLINFO_OLD
{
	char	szUserName[GL_BUFLEN_USERNAME];			//对应控件用户名
	DWORD	dwGameID;								//游戏ID
	HWND	hCtrlWnd;								//控件窗口句柄
	WORD	wAvatarDressCount;						//当前穿戴衣服数量	最多GL_MAXAVATARDRESSCOUNT
	WORD	awAvatarDressID[GL_MAXAVATARDRESSCOUNT];//当前穿戴衣服ID列表
	DWORD	dwByFillInfo;							//是否已填充信息 
}GL_AVATARCTRLINFO_OLD,*PGL_AVATARCTRLINFO_OLD;
typedef struct tagGL_AVATARCTRLINFO
{
	char	szUserName[GL_BUFLEN_USERNAME];			//对应控件用户名
	DWORD	dwGameID;								//游戏ID
	HWND	hCtrlWnd;								//控件窗口句柄
	WORD	wAvatarDressCount;						//当前穿戴衣服数量	最多GL_MAXAVATARDRESSCOUNT
	WORD	awAvatarDressID[GL_MAXAVATARDRESSCOUNT + GL_MAXAVATARDRESSCOUNT];//当前穿戴衣服ID列表
	DWORD	dwByFillInfo;							//是否已填充信息 
}GL_AVATARCTRLINFO,*PGL_AVATARCTRLINFO;

#define	MAPFILENAME						_T("GL_ROOM_REC")
typedef struct tagMAPFILEINFO
{
	char szUserName[GL_BUFLEN_USERNAME];
	BOOL bLobbyExist;
	BOOL bMaskEnemyMsg;
	ROOMRECINFO asrri[GL_MAX_ROOMCOUNT];
	char szPassword[GL_BUFLEN_PASSWORD];
	BOOL bStopMasterRoom;
	BOOL bInMasterRoom;
	LOCATEINFO asLocate[GL_MAX_ROOMCOUNT];
	char szLobbyName[GL_BUFLEN_SERVERNAME];
//add by lvch 2003/12/06 for avatar
	DWORD	dwSize;						//=sizeof(MAPFILEINFO)，2005.12.1从szReserve[64]拆分
	DWORD	dwWorldExeVersion;			//大厅程序的版本，2005.12.1从szReserve[64]拆分
	char	szReserve[56];				//保留
	HWND	hGlworldFrameWnd;			//大厅主窗口句柄
	char	szNickName[GL_BUFLEN_NICKNAME];//用户昵称
	int		nMoney;						//财富值 为第一次进入大厅时候值,随后可能变化
	int		nCoin;						//联众币 为第一次进入大厅时候值,随后可能变化
	char	szFaction[GL_BUFLEN_FACTION];//用户帮派
	char	szDuty[GL_BUFLEN_DUTY];		//用户职务
	BYTE	bySex;						//用户性别
	BYTE	byMember;					//是否会员
	char	szAvatarServer[GL_BUFLEN_HOST]; //推荐Avatar服务器地址
	int		nAvatarServerPort;              //推荐Avatar服务器端口
	char	szLastLoginServer[GL_BUFLEN_HOST]; //用户最近一次成功登陆的游戏服务器地址
	int		nLastLoginServerPort;              //用户最近一次成功登陆的游戏服务器端口
	GL_AVATARCTRLINFO_OLD	astrAvatarCtrl_cannotuse[GL_MAXAVATARCTRLCOUNT];//对应Avatar控件信息 (联众秀2.7,静止使用此结构,这里只是占位)
	LONGLONG	lDigitalID;					//数字id wuqy add 2005.3.8 %I64d

	DWORD	dwFaction;					//门派ID,用于购买联众秀时，判断指定秀的江湖门派ID，0表示非江湖成员 wuqy add 2005.6.23
	time_t	timeMemberStart;			//会员资历起始时间//0没有，－1未知
	int		nMemberRank;				//会员等级,0没有等级（由会员资历时间计算而来）wuqy add 2005.6.23
	int		nCoinScore;					//联众币消费积分 wuqy add 2005.6.23

	char	szTicket[GL_BUFLEN_TICKET];	//wangym 2005.11.11
	GL_AVATARCTRLINFO	astrAvatarCtrl[GL_MAXAVATARCTRLCOUNT];//对应Avatar控件信息 Avatar2.7
}MAPFILEINFO,*PMAPFILEINFO;

//Ewonder 加入下面的定义 2000/05/10
//当Glworld启动的时候检测到已经存在一个实例，它存放启动参数到内存文件里面
//并且发送消息到当前启动的Glworld主窗口
#define	MAPCOMMANDLINE					_T("GL_WORLD_CMDLINE")
typedef struct tagMAPCOMMANDLINEINFO
{		
	int	nLen;							//命令字符串的长度
	char szCmd[512];					//命令串存放的位置
}MAPCOMMANDLINEINFO,*PMAPCOMMANDLINEINFO;

// 当服务器发生任何错误时,服务器发送这个类型的消息(使用GLACKHEADER)
#define GLID_ACKERR						(GLID_ACK | 0x7FFFFFFF)
													// 应答出错
#define GLBIT_ACKERR_GAMEBREAK			0x00000001	// Game 被任何一方中断
#define GLBIT_ACKERR_KICKOUT			0x00000002	// 被一个相同用户名和口令的人踢出来
#define GLBIT_ACKERR_ROOMBREAK			0x00000004	// Room被断线
#define GLBIT_ACKERR_TIMEOUT			0x00000008	// 由于TIMEOUT而被服务器关闭

//---------------------------------------------------------------------------
//	通用错误消息
//---------------------------------------------------------------------------
typedef struct tagGLACKERR
{
	GLACKHEADER header;
	char szUserName[GL_BUFLEN_USERNAME];
}GLACKERR, *PGLACKERR;

//---------------------------------------------------------------------------
//	与注册有关的常量与数据结构的定义
//---------------------------------------------------------------------------
//#include "GLRegisterProtocol.h"	commented by wym 2003-3-11
								// 会导致registerservice编译时不从自己目录下编译这个文件 
								// 哪里用哪里包含它吧

//---------------------------------------------------------------------------
//	与Room有关的常量与数据结构的定义
//---------------------------------------------------------------------------
//#include "GLRoomProtocol.h"

//---------------------------------------------------------------------------
//	与游戏有关的常量与数据结构的定义，具体每个游戏可能还有特殊的定义
//---------------------------------------------------------------------------
//#include "GLGamesProtocol.h"

//---------------------------------------------------------------------------
//	与通讯无关的公用信息常量和数据结构定义
//---------------------------------------------------------------------------
//#include "GLOtherProtocol.h"

//add by lvch 2002 09 22
//             用作内部调试用                 吕翠华
#define LVCH_chSTR2(x)	   #x
#define LVCH_chSTR(x)	LVCH_chSTR2(x)
#define LVCH_MSG(desc) message(__FILE__ "(" LVCH_chSTR(__LINE__) "):" #desc)
//end add by lvch 2002 09 22

// wym 2003-8-8
// wMobileType 是每款手机在联众的唯一标识 长度WORD
// (wMobileType & 0x0080)==0x0080 是brew手机的标识，主要是区分联通内网域名映射用
#define MB_BREW		0x0080		// 0x0080 这位是brew手机的标识

typedef struct tagAvatarUserInfo
{
	char szUserName[GL_BUFLEN_USERNAME];  
	char szNickName[GL_BUFLEN_NICKNAME];  
	char szFaction[32];                   
	char szBusiness[32];                  
	int	 nMoney;                           
	int	 nCoin;                       
	BYTE bySex; 
	tagAvatarUserInfo()
	{
		memset(this, 0, sizeof(*this));
	}
}GL_AVATAR_USER_INFO, *PGL_AVATAR_USER_INFO;

//add by chairmin 大厅要求加上此定义 2008.11.21
//读写LangRsc的Mapfile
#define	MAPLANGRSCNAME					_T("GL_WORLD_LANGRSC")
//结构后面跟了dwLength长度的buffer
typedef struct tagMAPLANGRSCINFO
{		
	DWORD dwLength;						//LangRsc文件长度
}MAPLANGRSCINFO,*PMAPLANGRSCINFO;


#define	GL_MAX_PRIVILEGE_COUNT			64				//用户拥有的最大权限标志数量

#endif	// __GLPROTOCOL_H__
