/**
 * 帮助面板
 */
class HelpPanel extends BaseComponent implements IWindow {

    private list: eui.List;
    private data: eui.ArrayCollection;

    public constructor() {
        super();
        this.skinName = "resource/skin/panel/HelpPanelSkin.exml";
    }

    protected onSkinComplete(e: any): void {
        super.onSkinComplete(e);
        this.init();
    }

    public enter(data?: any): void {
        this.stage.addEventListener(egret.TouchEvent.TOUCH_END, this.exit, this);
        GameDispatcher.addEventListener(BaseEvent.HELP_DATA_EVENT, this.onData, this);
        ConnectionManager.instance.sendHelper.help();
    }

    public exit(data?: any): void {
        if (this.stage != null) {
            this.stage.removeEventListener(egret.TouchEvent.TOUCH_END, this.exit, this);
        }
        ClientModel.instance.openWindow(null);
    }
    public execute(data ?: any): void {

}

    public onData(): void {
        if (this.list != null) {
            this.list.dataProvider = this.getData();
        }
    }

    public destroy(): void {
        this.exit();
    }

    public init(): void {
        if (this.list != null) {
            // this.list.itemRenderer = HelpItemRenderer;
            this.list.layout = this.getLayout();
        }
    }

    private getLayout(): eui.LayoutBase {
        var la: eui.TileLayout = new eui.TileLayout();
        // la.gap=1;
        return la;
    }


    private getData(): eui.ArrayCollection {
        if (this.data == null) {
            this.data = new eui.ArrayCollection();
        }
        this.data.removeAll();
        // var len: number = ClientModel.instance.helpData.length;
        // for (var i: number = 0; i < len; i++) {
        //     if (ClientModel.instance.helpData[i] != null) {
        //         this.data.addItem(ClientModel.instance.helpData[i]);
        //     } else {
        //         this.data.addItemAt(null, i);
        //     }
        // }
        return this.data;
    }
}