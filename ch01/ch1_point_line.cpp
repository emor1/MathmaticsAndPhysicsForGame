#include <iostream>
#include <cstdio>


/*
2点間の傾き計算
入力：P1点１を表す配列、P2点２を表す配列
出力：傾き
*/
float slopeBetweenPoints(float *P1, float *P2){
    return (P2[1]-P1[1])/(P2[0]-P1[0]);
}

/*
直線の傾き
与えられた直線に垂直な直線の傾き
入力：slope(傾き)
出力：slopeに対して垂直な傾き
*/
float perpSlope(float slope){
    // A*B=-1: 垂直
    return -1/slope;
}


/*
２つの直線が垂直か調べる
入力: slope1, slope2
出力　bool
*/
bool arePerp(float slope1, float slope2){
    if(slope1*slope2==-1){
        return true;
    }
    return false;
}

/*
２つの直線の交点を求める
入力：座標１、傾き１、座標２、傾き２、結果用配列
出力：交点の座標配列
*/
void lineIntersect(float *L1Point, float L1Slope, float *L2Point, float L2Slope, float (&result)[2]){
    // xを求める
    result[0] = (L1Slope*L1Point[0] - L2Slope*L2Point[0]+L2Point[1]-L1Point[1])/(L1Slope-L2Slope);

    result[1] = L1Slope*(result[0]-L1Point[0])+L1Point[1];
}


int main(){
    float a[2] = {1, 5};
    float b[2] ={-2,0};


    float result = slopeBetweenPoints(a,b);
    printf("the slope is %f\n", result);

    printf("perp slope is %f, %d\n", perpSlope(result), arePerp(perpSlope(result), result));

    float c[2] = {5,1};
    float d[2] = {3,1};

    float slope1 = 5.0f;
    float slope2 = -3.0f;

    // float &ans[2]
    float result_2[2] = {0,0};
    lineIntersect(c, slope1, d, slope2, result_2);
    printf("the intersect is %f, %f\n", result_2[0],result_2[1]);
}
