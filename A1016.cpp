/*3-4 15:02-*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct record{
    string name;
    int time, d, h, m;
    bool onLine;
    bool friend operator < (record a, record b){
        return a.name != b.name ? a.name < b.name : a.time < b.time;
    }
};
float rate[25]={0}; //rate[24]表示全天倍率

float billFormZero(record r){
    float bill(0);
    bill += rate[r.h]*r.m + rate[24]*60*r.d;
    for (int i = 0; i < r.h; i++){
        bill += rate[i]*60;
    }
    return bill / 100;
}
int main(){
    int n, mon;

    for (int i = 0; i < 24; i++){
        cin >> rate[i];
        rate[24] += rate[i];
    }
    cin >> n;
    vector<record> rec(n); //通话记录
    map<string, vector<record> > legRec; //合法记录
    for (int i = 0; i < n; i++){
        string tmpS;
        cin >> rec[i].name;
        scanf(" %d:%d:%d:%d ", &mon, &rec[i].d, &rec[i].h, &rec[i].m);
        rec[i].time = rec[i].m + rec[i].h * 60 + rec[i].d * 24 * 60; //从0:0:0开始的分钟数
        cin >> tmpS;
        rec[i].onLine = tmpS == "on-line" ? true : false;
    }
    sort(rec.begin(), rec.end());
    for (int i = 1; i < n; i++){
        if (rec[i-1].name == rec[i].name && 
                (rec[i-1].onLine && !rec[i].onLine)){ //构成合法记录
            legRec[rec[i].name].push_back(rec[i-1]);
            legRec[rec[i].name].push_back(rec[i]);
        }
    }
    for (auto it : legRec){ //输出结果
        float total(0);
        vector<record> tmpV = it.second;
        printf("%s %02d\n", it.first.c_str(), mon);
        for (int i = 0; i < it.second.size(); i+=2){
            float bill = billFormZero(tmpV[i+1]) - billFormZero(tmpV[i]);
            total += bill;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                    tmpV[i].d, tmpV[i].h, tmpV[i].m, tmpV[i+1].d, 
                    tmpV[i+1].h, tmpV[i+1].m, tmpV[i+1].time-tmpV[i].time, bill);
        }
        printf("Total amount: $%.2f\n", total);
    }

    return 0;
}
