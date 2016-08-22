class ShellVo {

	public id: number;
	public level: number;

	public shell: string;
	public width: number;
	public height: number;
	public offy: number;
	public offx: number;

	public bomb: string;
	public bombWidth: number;
	public bombHeight: number;
	public bombOffx: number;
	public bombOffy: number;

	public sendInterval: number;
	public speed: number;

	public constructor() {
	}

	public analysis(data: any): void {
		this.id = data.id;
		this.level = data.level;
		this.shell = data.shell;
		this.width = data.width;
		this.height = data.height;
		this.offx = data.offx;
		this.offy = data.offy;

		this.bomb = data.bomb;
		this.bombWidth = data.bombWidth;
		this.bombHeight = data.bombHeight;
		this.bombOffx = data.bombOffx;
		this.bombOffy = data.bombOffy;

		this.sendInterval = data.sendInterval;
		this.speed = data.speed;
	}
}