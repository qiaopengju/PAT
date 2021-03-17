/***********************************************
*      Filename: A1033.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 08:50:11
# Last Modified: 2021-03-13 08:50:14
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000005
using namespace std;

struct node {
    float dis, price;
    friend bool operator < (node a, node b ) { return a.dis < b.dis; }
};
int main(){
    int n;
    float dis, perGas, maxCap, maxDis, reGas(0), cost(0);
    cin >> maxCap >> dis >> perGas >> n;
    vector<node> station(n+1);
    maxDis = maxCap * perGas; //加满油后最远距离
    for (int i = 0; i < n; i++) cin >> station[i].price >> station[i].dis;
    station[n].price = 0; //最后一个加油站是目的城市
    station[n].dis = dis;
    sort(station.begin(), station.end()); //按距离排序
    if (station[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    for (int i = 0; i < n; ){ //当前在第i个加油站
        if (maxDis < station[i+1].dis - station[i].dis){
            printf("The maximum travel distance = %.2f\n", station[i].dis + maxDis);
            return 0;
        }
        int minIdx = i;
        //找最近比i油价低的加油站
        for (int j = 1; j <= n && station[j].dis - station[i].dis < maxDis; ){
            if (station[j].price < station[i].price){
                minIdx = j;
            }
        }
        if (minIdx > i){ //如果有比i油价低的加油站minIdx，前往minIdx
            cost += ((station[minIdx].dis-station[i].dis)/perGas - reGas) * station[i].price;
            reGas = 0;
            i = minIdx;
            continue;
        }
        //若没有比i低的找在加满油下能走到的油钱最少的加油站
        float minPrice = station[i+1].price;
        for (int j = i+1; j <= n && station[j].dis - station[i].dis < maxDis; j++){
            if (station[j].price < minPrice){
                minPrice = station[j].price;
                minIdx = j;
            }
        }
        cost += (maxCap - reGas) * station[i].price;
        reGas = maxCap - (station[minIdx].dis - station[i].dis) / perGas;
        i = minIdx;
    }
    printf("%.2f\n", cost);
    return 0;
}

