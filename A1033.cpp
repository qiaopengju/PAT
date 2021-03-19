/***********************************************
*      Filename: A1033.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-17 16:34:14
# Last Modified: 2021-03-19 11:28:32
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#define N 505
using namespace std;

struct node{
    float dis, price;
    friend bool operator < (node a, node b){ return a. dis < b.dis; }
}station[N];
int main(){
    int n;
    float cMax, d, dAvg, maxFullDis, reGas(0);
    scanf("%f %f %f %d", &cMax, &d, &dAvg, &n);
    maxFullDis = cMax * dAvg;
    for (int i = 0; i < n; i++)
        cin >> station[i].price >> station[i].dis;
    station[n].dis = d;
    station[n].price = 0;
    sort(station, station+n+1);
    /* 策略
    1，寻找加满油范围内离当前站点最近的比当前站便宜的加油站，油刚好加到能到达该站
    2. 若没有比当前站便宜的，则加满油后找范围内最小的
    3. 若走不到下一站，输出最远距离
    */
    for (int i = 0; i <= n; i++){
        for (int j = i + 1; j <= n && station[j; j++){ //从当前站之后一站找
        }
    }
    return 0;
}
