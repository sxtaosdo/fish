class MatrixUtils {

	/**增加亮度 */
	public static colorMatrix = [
		1, 0, 0, 0, 100,
		0, 1, 0, 0, 100,
		0, 0, 1, 0, 100,
		0, 0, 0, 1, 0
	];

	/**模糊滤镜 */
	public static get blurFliter(): egret.BlurFilter {
		return new egret.BlurFilter(1, 1);
	}
}