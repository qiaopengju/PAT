#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class record{
    public:
    string plate;
    int time, h, m, s;
    bool status; //true: in ;false :out
    void caculateTime(){ time = h*3600 + m*60 + s; }
    friend bool operator < (record a, record b){
        return a.plate==b.plate ? a.time<b.time : a.plate < b.plate;
    }
};

int main(){
    int n, k, maxPark(0);
    string status;
    vector<record> lR; //合法记录
    map<string, int> carPark; //停车时长
    vector<string> maxParkCar; //停车最长的车
    cin >> n >> k;
    vector<record> rec(n);

    for (vector<record>::iterator it = rec.begin(); it != rec.end(); it++){ //input record
        cin >> it->plate;
        scanf("%d:%d:%d ", &(it->h), &(it->m), &(it->s));
        cin >> status;
        it->status = status=="in" ? true : false;
        it->caculateTime();
    }
    /*筛选合法信息并排序*/
    sort(rec.begin(), rec.end());
    for (int i = 1 ; i < n; ){
        if (rec[i-1].plate==rec[i].plate && rec[i-1].status && !rec[i].status){ //记录合法，压入
            lR.push_back(rec[i-1]);
            lR.push_back(rec[i]);
            carPark[rec[i].plate] += (rec[i].time - rec[i-1].time);
            if (carPark[rec[i].plate] > maxPark) maxPark = carPark[rec[i].plate]; //更新最大停车时间
            i += 2;
        } else i++;
    }
    for (auto it : carPark){ //将时长最大压入vector
        if (it.second == maxPark) maxParkCar.push_back(it.first);
    }
    for (int i = 0; i < k; i++){ //处理查询
        int h, m, s, t, pN(0);
        scanf("%d:%d:%d", &h, &m, &s);
        t = h*3600 + m*60 + s;
        for (int j = 0; j < lR.size(); j+=2){ //统计时段内停车数量
            if (lR[j].time<=t && lR[j+1].time>=t) pN++; //在t之前进入，在t之后出
        }
        printf("%d\n", pN);
    }
    /*输出最大停车时长的车*/
    sort(maxParkCar.begin(), maxParkCar.end());
    for (int i = 0; i < maxParkCar.size(); i++) {
        if (i) printf(" ");
        printf("%s", maxParkCar[i].c_str());
    }
    printf(" %02d:%02d:%02d\n", maxPark/3600, (maxPark%3600)/60, maxPark%3600%60);

    return 0;
}
