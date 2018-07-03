
var game_file_list = [
    //以下为自动修改，请勿修改
    //----auto game_file_list start----
	"libs/modules/egret/egret.js",
	"libs/modules/egret/egret.native.js",
	"libs/modules/eui/eui.js",
	"libs/modules/res/res.js",
	"libs/modules/game/game.js",
	"libs/modules/game/game.native.js",
	"libs/modules/tween/tween.js",
	"libs/modules/socket/socket.js",
	"libs/modules/dragonBones/dragonBones.js",
	"libs/greensock/greensock.min.js",
	"libs/protobuf/Long.min.js",
	"libs/protobuf/ByteBufferAB.min.js",
	"libs/protobuf/ProtoBuf.min.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/entity/BaseGameEntity.js",
	"bin-debug/com/ourgame/angryFisher/model/window/BaseComponent.js",
	"bin-debug/com/ourgame/angryFisher/net/message/BaseMessage.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/entity/MovingEntity.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/utils/TreeSet.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/v2d/Vector2Ds.js",
	"bin-debug/com/ourgame/angryFisher/base/interface/IBase.js",
	"bin-debug/com/ourgame/angryFisher/base/interface/IBaseGameEntity.js",
	"bin-debug/com/ourgame/angryFisher/base/interface/ICompositor.js",
	"bin-debug/com/ourgame/angryFisher/base/interface/IMovingEneity.js",
	"bin-debug/com/ourgame/angryFisher/data/ClientModel.js",
	"bin-debug/com/ourgame/angryFisher/data/ConfigModel.js",
	"bin-debug/com/ourgame/angryFisher/data/HallClientModel.js",
	"bin-debug/com/ourgame/angryFisher/data/LanguageConfig.js",
	"bin-debug/com/ourgame/angryFisher/data/UserModel.js",
	"bin-debug/com/ourgame/angryFisher/data/def/EntityType.js",
	"bin-debug/com/ourgame/angryFisher/data/def/GameStateDef.js",
	"bin-debug/com/ourgame/angryFisher/data/def/StateDef.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/DeabedVo.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/DiceInfo.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/DiceVo.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/FishCreateVo.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/FishVo.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/GridVo.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/PathPointVo.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/PlayerVo.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/RoomInfoVo.js",
	"bin-debug/com/ourgame/angryFisher/data/vo/ShellVo.js",
	"bin-debug/com/ourgame/angryFisher/event/BaseEvent.js",
	"bin-debug/com/ourgame/angryFisher/event/GameDispatcher.js",
	"bin-debug/com/ourgame/angryFisher/event/GameEvent.js",
	"bin-debug/com/ourgame/angryFisher/model/dice/DiceGamePanel.js",
	"bin-debug/com/ourgame/angryFisher/model/dice/DiceView.js",
	"bin-debug/com/ourgame/angryFisher/model/game/DeabedPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/game/GameWorld.js",
	"bin-debug/com/ourgame/angryFisher/model/game/HitGoldAnimation.js",
	"bin-debug/com/ourgame/angryFisher/model/game/JpBarPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/game/PlayerList.js",
	"bin-debug/com/ourgame/angryFisher/model/hall/HallView.js",
	"bin-debug/com/ourgame/angryFisher/model/hall/RoomInfoListPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/loading/LoadingUI.js",
	"bin-debug/com/ourgame/angryFisher/model/login/LoginView.js",
	"bin-debug/com/ourgame/angryFisher/model/renderer/FishRenderer.js",
	"bin-debug/AssetAdapter.js",
	"bin-debug/com/ourgame/angryFisher/model/renderer/RoomBtnItemRenderer.js",
	"bin-debug/com/ourgame/angryFisher/model/renderer/RoomInfoListRenderer.js",
	"bin-debug/com/ourgame/angryFisher/model/renderer/ShellRenderer.js",
	"bin-debug/com/ourgame/angryFisher/model/top/TopView.js",
	"bin-debug/com/ourgame/angryFisher/model/window/Alert.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/messaging/MessageType.js",
	"bin-debug/com/ourgame/angryFisher/model/window/BindPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/window/DiceAlert.js",
	"bin-debug/com/ourgame/angryFisher/model/window/HelpPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/window/HitInfoPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/window/IWindow.js",
	"bin-debug/com/ourgame/angryFisher/model/window/LevelUpPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/window/MailPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/window/OperationPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/window/RankPanel.js",
	"bin-debug/com/ourgame/angryFisher/model/window/WindowManager.js",
	"bin-debug/com/ourgame/angryFisher/native/AndroidInterface.js",
	"bin-debug/com/ourgame/angryFisher/native/INative.js",
	"bin-debug/com/ourgame/angryFisher/native/InterfaceManager.js",
	"bin-debug/com/ourgame/angryFisher/native/IosInterface.js",
	"bin-debug/com/ourgame/angryFisher/native/WebInterface.js",
	"bin-debug/com/ourgame/angryFisher/native/WxInterface.js",
	"bin-debug/com/ourgame/angryFisher/net/ConnectionManager.js",
	"bin-debug/com/ourgame/angryFisher/net/ISocket.js",
	"bin-debug/com/ourgame/angryFisher/net/MsgReceiveHelper.js",
	"bin-debug/com/ourgame/angryFisher/net/MsgSendHelper.js",
	"bin-debug/com/ourgame/angryFisher/net/MsgType.js",
	"bin-debug/com/ourgame/angryFisher/net/handler/SocketIoHandler.js",
	"bin-debug/com/ourgame/angryFisher/net/handler/WebSocketHandler.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/messaging/MessageDispatcher.js",
	"bin-debug/com/ourgame/angryFisher/net/message/MsgLoginReq.js",
	"bin-debug/com/ourgame/angryFisher/net/service/LocalService.js",
	"bin-debug/com/ourgame/angryFisher/utils/BitMapUtil.js",
	"bin-debug/com/ourgame/angryFisher/utils/ButtonUtils.js",
	"bin-debug/com/ourgame/angryFisher/utils/HitTestUtils.js",
	"bin-debug/com/ourgame/angryFisher/utils/MatrixUtils.js",
	"bin-debug/com/ourgame/angryFisher/utils/PcHelper.js",
	"bin-debug/com/ourgame/angryFisher/utils/RandomUtil.js",
	"bin-debug/com/ourgame/angryFisher/utils/RollNumber.js",
	"bin-debug/com/ourgame/angryFisher/utils/StringUtils.js",
	"bin-debug/com/ourgame/angryFisher/utils/TimeUtils.js",
	"bin-debug/com/ourgame/angryFisher/utils/TimerManager.js",
	"bin-debug/com/ourgame/test/TestEvent.js",
	"bin-debug/com/ourgame/test/TestWindow.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/fsm/StateMachine.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/fsm/ShellEntityState.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/fsm/IState.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/fsm/FishEntityState.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/messaging/Telegram.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/entity/EntityManager.js",
	"bin-debug/com/ourgame/angryFisher/base/ai/utils/FishPathUtil.js",
	"bin-debug/com/ourgame/angryFisher/GameMain.js",
	"bin-debug/ThemeAdapter.js",
	"bin-debug/Main.js",
	"bin-debug/com/ourgame/angryFisher/model/renderer/PlayerGunRenderer.js",
	//----auto game_file_list end----
];

var window = this;

egret_native.setSearchPaths([""]);

egret_native.requireFiles = function () {
    for (var key in game_file_list) {
        var src = game_file_list[key];
        require(src);
    }
};

egret_native.egretInit = function () {
    egret_native.requireFiles();
    egret.TextField.default_fontFamily = "/system/fonts/DroidSansFallback.ttf";
    //egret.dom为空实现
    egret.dom = {};
    egret.dom.drawAsCanvas = function () {
    };
};

egret_native.egretStart = function () {
    var option = {
        //以下为自动修改，请勿修改
        //----auto option start----
		entryClassName: "Main",
		frameRate: 30,
		scaleMode: "showAll",
		contentWidth: 960,
		contentHeight: 570,
		showPaintRect: false,
		showFPS: false,
		fpsStyles: "x:0,y:0,size:12,textColor:0xffffff,bgAlpha:0.5",
		showLog: false,
		logFilter: "",
		maxTouches: 2,
		textureScaleFactor: 1
		//----auto option end----
    };

    egret.native.NativePlayer.option = option;
    egret.runEgret();
    egret_native.Label.createLabel(egret.TextField.default_fontFamily, 20, "", 0);
    egret_native.EGTView.preSetOffScreenBufferEnable(true);
};