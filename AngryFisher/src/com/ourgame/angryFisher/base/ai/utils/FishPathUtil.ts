/**
 *
 * @author 
 *sxt
 */
class FishPathUtil {
    private static smooth_value: number = 0.6;

    public static createPath(startIndex:number,beforeStartPoint:PathPoint,startPoint:PathPoint, endPoint:PathPoint,afterEndPoint:PathPoint): Array<PathPoint> {
        var pointList:Array<PathPoint>=[];
        // Assume we need to calculate the control
        // points between (x1,y1) and (x2,y2).
        // Then x0,y0 - the previous vertex,
        //      x3,y3 - the next one. 
        var x1=startPoint.x;
        var y1=startPoint.y;
        var x2=endPoint.x;
        var y2=endPoint.y;
        var x0=beforeStartPoint.x;
        var y0=beforeStartPoint.y;
        var x3=afterEndPoint.x;
        var y3=afterEndPoint.y;
        var xc1: number = (x0 + x1) / 2.0;
        var yc1: number = (y0 + y1) / 2.0;
        var xc2: number = (x1 + x2) / 2.0;
        var yc2: number = (y1 + y2) / 2.0;
        var xc3: number = (x2 + x3) / 2.0;
        var yc3: number = (y2 + y3) / 2.0;
        var len1: number = Math.sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
        var len2: number = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        var len3: number = Math.sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        var k1: number = len1 / (len1 + len2);
        var k2: number = len2 / (len2 + len3);
        var xm1: number = xc1 + (xc2 - xc1) * k1;
        var ym1: number = yc1 + (yc2 - yc1) * k1;
        var xm2: number = xc2 + (xc3 - xc2) * k2;
        var ym2: number = yc2 + (yc3 - yc2) * k2;
        var NUM_STEPS=Math.floor(len2/startPoint.speed);
        // Resulting control points. Here smooth_value is mentioned
        // above coefficient K whose value should be in range [0...1].
        var ctrl1_x: number = xm1 + (xc2 - xm1) * this.smooth_value + x1 - xm1;
        var ctrl1_y: number = ym1 + (yc2 - ym1) * this.smooth_value + y1 - ym1;
        var ctrl2_x: number = xm2 + (xc2 - xm2) * this.smooth_value + x2 - xm2;
        var ctrl2_y: number = ym2 + (yc2 - ym2) * this.smooth_value + y2 - ym2;
        // Number of intermediate points between two source ones,
        // Actually, this value should be calculated in some way,
        // Obviously, depending on the real length of the curve.
        // But I don't know any elegant and fast solution for this
        // problem.
        var dx1: number = ctrl1_x - x1;
        var dy1: number = ctrl1_y - y1;
        var dx2: number = ctrl2_x - ctrl1_x;
        var dy2: number = ctrl2_y - ctrl1_y;
        var dx3: number = x2 - ctrl2_x;
        var dy3: number = y2 - ctrl2_y;
        var subdiv_step:number=1/(NUM_STEPS+1);
        var subdiv_step2:number=subdiv_step*subdiv_step;
        var subdiv_step3:number=subdiv_step*subdiv_step*subdiv_step;
        var pre1:number=3*subdiv_step;
        var pre2:number=3*subdiv_step2;
        var pre4:number=6*subdiv_step2;
        var pre5:number=6*subdiv_step3;

        var tmp1x:number=x1-ctrl1_x*2+ctrl2_x;
        var tmp1y:number=y1-ctrl1_y*2+ctrl2_y;
        var tmp2x:number=(ctrl1_x-ctrl2_x)*3-x1+x2;
        var tmp2y:number=(ctrl1_y-ctrl2_y)*3-y1+y2;
        var fx:number=x1;
        var fy:number=y1;
        var dfx=(ctrl1_x-x1)*pre1+tmp1x*pre2+tmp2x*subdiv_step3;
        var dfy=(ctrl1_y-y1)*pre1+tmp1y*pre2+tmp2y*subdiv_step3;
        var ddfx=tmp1x*pre4+tmp2x*pre5;
        var ddfy=tmp1y*pre4+tmp2y*pre5;
        var dddfx=tmp2x*pre5;
        var dddfy=tmp2y*pre5;

        var step:number=NUM_STEPS;
        // Suppose, we have some abstract object Polygon which
        // has method AddVertex(x, y), similar to LineTo in
        // many graphical APIs.
        // Note, that the loop has only operation add!
        while (step--) {
            fx += dfx;
            fy += dfy;
            dfx += ddfx;
            dfy += ddfy;
            ddfx += dddfx;
            ddfy += dddfy;
            var p:PathPoint=new PathPoint();
            p.index=startIndex;
            p.x=fx;
            p.y=fy;
            pointList.push(p);
            startIndex++;
        }
        return pointList;
    }
}
