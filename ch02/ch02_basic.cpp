#include <iostream>
#include <cstdio>
#include <cmath>

/**
 * 2点間の距離の計算
*/

float distance2D(float *P1, float *P2){
    return (float)sqrt(pow(P2[0]-P1[0],2)+ pow(P2[1]-P1[1],2));
}

int main(){
    float P1[2] = {25, 80};
    float P2[2] = {55, 40};

    printf("ans: %.2f\n", distance2D(P1, P2));
}