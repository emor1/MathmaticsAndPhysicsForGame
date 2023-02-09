#include <cstdio>
#include "../vector.cpp"
#include <math.h>

#define PI 3.14

/**
 * ベクトルを向きと大きさから成分に変換
 * 入力：vector2D_polar、結果格納用vector2D
 * 出力：
*/

void PolarToCompConversion(vector2D_polar vec, vector2D *result_vec){
    vector2D temp;

    temp.x = vec.mag * cos(vec.dir*PI/180);
    temp.y = vec.mag * sin(vec.dir*PI/180);

    result_vec->x = temp.x;
    result_vec->y = temp.y;
}

/**
 * ベクトルを成分から大きさと向きに変換
 * 入力：vector2D、結果格納用vector2D_polar
 * 出力
*/
void CompToPolarConversion(vector2D vec, vector2D_polar *result_vec){
    result_vec->mag = sqrtf(vec.x *vec.x + vec.y*vec.y);
    if(result_vec->mag == 0){
        return;
    }

    result_vec->dir = (180/PI)*asin(vec.y / result_vec->mag);
    if(vec.x < 0)
    {
        result_vec->dir -= 180;
    }else if(vec.x > 0 && vec.y < 0){
        result_vec->dir += 360;
    }
}

int main()
{
    vector3D v1 = {500,50,50};

    printf("%f, %f, %f\n",v1.x,v1.y,v1.z);

}