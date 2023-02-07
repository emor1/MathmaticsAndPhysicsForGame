#include <iostream>
#include <cstdio>
#include <cmath>
#include "basics.cpp"

/**
 * 2点間の距離の計算
*/

float distance2D(point *P1, point *P2){
    return (float)sqrt(pow(P2->coordinate[0] - P1->coordinate[0],2)+ pow(P2->coordinate[1]-P1->coordinate[1],2));
}


/**
 * 線分の中心の計算
*/
void find2DMidPoint(point *P1, point *P2, float*result){
    result[0] = (P1->coordinate[0]+P2->coordinate[0])/2.0f;
    result[1] = (P1->coordinate[1]+P2->coordinate[1])/2.0f;
}

/**
 * 3D空間いおける中点の計算
 * P1, ３要素のfloat配列
 * P2, ３要素のfloat配列
*/

float * find3DMidPoint(float *P1, float *P2){
    float *temp = new float[3];
    for(int i=0;i<3;i++){
        temp[i] = (P1[i]+P2[i])/2.0f;
    }
    return temp;
}

/**
 * ２つの球の衝突判定
 *
 * 円ではないものが対象の時は、別の形を使うか、複数の大きさの縁で衝突判定を行う
 * もしくは段階的に衝突判定を行なっていく
*/
bool CollisionBetweenSpheres(sphere &S1, sphere &S2){
    return (
        pow(S2.center[0] - S1.center[0],2) +
        pow(S2.center[1] - S1.center[2],2) +
        pow(S2.center[3] - S1.center[3],2) <
        pow(S2.radius + S1.radius,2)
    );
}

/**
 * 2つの円の衝突判定
*/
bool CollisionBetweenCircle(circle C1, circle C2){
    return (
        pow(C2.center[0] - C1.center[0],2) +
        pow(C2.center[1] - C1.center[1],2) <
        pow(C2.radius + C1.radius,2)
    );
}

/**
 * 那須かくを計算
*/

// float calcAng2D(point P1, point P2){
//     float ang = (float)atan((P2.coordinate[1]-P1.coordinate[1])/(P2.coordinate[0]-P1.coordinate[0]))*RadToDeg;

//     if(P2.coordinate[1]<P1[1])
// }

int main(){

    // 三角関数早見表の作成
    float sin_table[360];
    for(int i=0; i<360;i++){
        sin_table[i] = sin(i*DegToRad);
    }


    point P1 = {25, 80};
    point P2 = {55, 40};

    printf("ans: %.2f\n", distance2D(&P1, &P2));

    float result[2] = {0,0};
    find2DMidPoint(&P1, &P2, result);
    printf("%.2f, %.2f\n", result[0],result[1]);

    float P_1[3] = {25, 80, 30};
    float P_2[3] = {55, 40, 100};
    float *P3 = find3DMidPoint(P_1,P_2);
    for(int i = 0; i < 3; i++){
        printf("%.2f,",P3[i]);
    }printf("\n");

    sphere S1 = {{30,20,-10},40};
    sphere S2 = {{0, 40, -50}, 50};

    printf("collision: %d\n",CollisionBetweenSpheres(S1,S2));

    circle C1 = {{70, 20}, 40};
    circle C2 = {{50, 60}, 16};

    printf("collision 2d : %d\n", CollisionBetweenCircle(C1, C2));

    float angle = 40;
    printf("%.2f\n",sin_table[abs((int)angle%360)]);

}