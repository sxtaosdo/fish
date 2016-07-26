class RandomUtil extends egret.HashObject {

					public constructor()
					{
						super();
					}

					public static randNumber(min:number,max:number):number
					{
						return min + Math.random() * (max - min);
					}

					public static randInt(min:number,max:number):number
					{
//						min = flash.checkInt(min);
//						max = flash.checkInt(max);
						return min + Math.ceil(Math.random() * (max - min));
					}

					public static randColor():number
					{
						return Math.random() * 0x666666;
					}

					public static randPt(x0:number,y0:number,x1:number,y1:number):egret.Point
					{
						return new egret.Point(x0 + Math.random() * (x1 - x0),y0 + Math.random() * (y1 - y0));
					}

				}

