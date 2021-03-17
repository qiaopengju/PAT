/*3-5 12:44-*/
#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <queue>
using namespace std;

struct date{
    int d, h, m;
    bool onLine;
    friend bool operator < (date a, date b){
        if (a.d != b.d) return a.d < b.d;
        if (a.h != b.h) return a.h < b.h;
        return a.m < b.m;
    }
};
struct rec{
    int recN;
    date dt[1005];
    rec() {recN = 0;}
};

int main(){
    map<string, rec> record;
    int n(24), Mon, d, h, m; //cost rate
    float rate[24];
    string name, onOff;

    while(n--) cin >> rate[24-n-1]; //input rate
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> name;
        scanf("%d:%d:%d:%d ", &Mon, &d, &h, &m);
        cin >> onOff;
        int &recN = record[name].recN;
        record[name].dt[recN].d = d;
        record[name].dt[recN].h = h;
        record[name].dt[recN].m = m;
        record[name].dt[recN].onLine = onOff == "on-line" ? true : false;
        recN++;
    }
    for (map<string, rec>::iterator it = record.begin(); it != record.end(); it++){
        sort(it->second.dt, it->second.dt + it->second.recN);
    }
    for (map<string, rec>::iterator it = record.begin(); it != record.end(); it++){ //处理一位客户记录
        float charge(0);
        bool flag(false); //上一次是online
        printf("%s %02d\n", it->first.c_str(), Mon);
        for (int i = 0; i < it->second.recN; i++){
            if (!flag && it->second.dt[i].onLine) { flag = true; continue; }
            if (flag && !it->second.dt[i].onLine){ //匹配成功,输出并计算charge
                float tmpC(0);
                int mi(0), d1 = it->second.dt[i-1].d, d2 = it->second.dt[i].d;
                int h1 = it->second.dt[i-1].h, h2 = it->second.dt[i].h;
                int m1 = it->second.dt[i-1].m, m2 = it->second.dt[i].m;
                flag = false;
                printf("%02d:%02d:%02d", d1, h1, m1);
                printf(" %02d:%02d:%02d", d2, h2, m2);
                if (m1 != 0){ //先把时间化整
                    mi += 60-m1;
                    tmpC += (60-m1) * rate[h1];
                    m1 = 0;
                    if (h1 == 23){ //向前进一天
                        h1 = 0; d1++;
                    }else h1++;
                }
                if (m2 != 0){
                    mi += m2;
                    tmpC += m2 * rate[h2];
                    m2 = 0;
                }
                while(d1!=d2 || h1 != h2){
                    mi += 60; //过一小时
                    tmpC += rate[h1++]*60;
                    if (h1 == 24){
                        h1 = 0;
                        d1++;
                    }
                }

                printf(" %d $%.2f\n", mi, tmpC/100);
                charge += tmpC;
                continue;
            }
            if (flag && it->second.dt[i].onLine){ flag = true; continue; }
            if (!flag && !it->second.dt[i].onLine){ flag = false; continue; }
        }
        printf("Total amount: $%.2f\n", charge/100);
    }

    return 0;
}
