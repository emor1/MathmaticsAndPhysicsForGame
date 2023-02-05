#include <iostream>
#include <cstdio>
#include <cmath>


template<typename T, size_t n>
void print_array(T const(& arr)[n])
{
    for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
}

/**
 * 2点間の距離の計算
*/

float distance2D(float *P1, float *P2){
    return (float)sqrt(pow(P2[0]-P1[0],2)+ pow(P2[1]-P1[1],2));
}


/**
 * 線分の中心の計算
*/
void find2DMidPoint(float*P1, float*P2, float*result){
    result[0] = (P1[0]+P2[0])/2.0f;
    result[1] = (P1[1]+P2[1])/2.0f;
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

int main(){
    float P1[2] = {25, 80};
    float P2[2] = {55, 40};

    printf("ans: %.2f\n", distance2D(P1, P2));

    float result[2] = {0,0};
    find2DMidPoint(P1, P2, result);
    printf("%.2f, %.2f\n", result[0],result[1]);

    float P_1[3] = {25, 80, 30};
    float P_2[3] = {55, 40, 100};
    float *P3 = find3DMidPoint(P_1,P_2);
    for(int i = 0; i < 3; i++){
        printf("%.2f,",P3[i]);
    }printf("\n");
}