class ShellVo {

	public id: number;
	public level: number;
	public shell: string;
	public bomb: string;
	public sendInterval: number;
	public offy: number;

	public constructor() {
	}

	public analysis(data: any): void {
		this.id = data.id;
		this.level = data.level;
		this.shell = data.shell;
		this.bomb = data.bomb;
		this.sendInterval = data.sendInterval;
		this.offy = data.offy;
	}
}