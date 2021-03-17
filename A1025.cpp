/*3-t 16:11-*/
#include <iostream>
#include <algorithm>
using namespace std;

struct team{
    string id;
    int score, aRank, lRank, loc;
}t[30005];
bool cmpLoc(team a, team b){ return a.loc == b.loc ?  a.score > b.score : a.loc < b.loc; }//场内排序
bool cmpAll(team a, team b){ return a.score == b.score ? a.id < b.id : a.score > b.score; } //整体排序

int main(){
    int n, tN(0), sf(0); //sf:场地指针偏移

    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        for (int j = 0; j < k; j++){
            cin >> t[tN].id >> t[tN].score;
            t[tN++].loc = i+1;
        }
    }
    /*场内排序*/
    sort(t, t+tN, cmpLoc);
    t[0].lRank = 1;
    for (int i = 1; i < tN; i++){
        if (t[i].loc == t[i-1].loc){ //和之前场地相同
            if (t[i].score == t[i-1].score) t[i].lRank = t[i-1].lRank;
            else t[i].lRank = i+1-sf;
        }else{ //场地不同,场内第一 
            t[i].lRank = 1;
            sf = i; //场地偏移
        }
    }
    /*整体排序*/
    sort(t, t+tN, cmpAll);
    t[0].aRank = 1;
    for (int i = 1; i < tN; i++){
        if (t[i].score == t[i-1].score) t[i].aRank = t[i-1].aRank;
        else t[i].aRank = i+1;
    }
    cout << tN << endl;
    for (int i = 0; i < tN; i++){ //输出结果
        cout << t[i].id << " " << t[i].aRank 
            << " " << t[i].loc  << " " << t[i].lRank << endl;
    }

    return 0;
}
