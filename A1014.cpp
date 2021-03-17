/***********************************************
*      Filename: A1014.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-12 17:57:27
# Last Modified: 2021-03-12 17:57:31
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node{ //从0号窗口开始
    int begin, end;
    queue<int> q;
    node(){ begin = end = 0; }
}window[20];
vector<int> processT, result;

bool cmp(int a, int b) { 
    return window[a].begin + processT[window[a].q.front()]
    < window[b].begin + processT[window[b].q.front()]; 
}
void printTime(int t){
    if (t > 540) printf("Sorry\n");
    else{
        int h = t / 60 + 8;
        int m = t % 60;
        printf("%02d:%02d\n", h, m);
    }
}
int main(){
    int minWin[20];
    for (int i = 0; i < 20; i++) minWin[i] = i;
    int n, m, k, q, sf; //从1号客户开始
    cin >> n >> m >> k >> q;
    processT.resize(k + 1);
    result.resize(k + 1);
    for (int i = 1; i <= k; i++) cin >> processT[i];
    for (sf = 1; sf <=k && sf <= n*m; sf++){ //先将黄线前所有人入队
        int wIdx = sf % n;
        window[wIdx].q.push(sf);
        window[wIdx].end += processT[sf];
        result[sf] = window[wIdx].end; //服务截止时间
        window[wIdx].q.pop();
    }
    while(sf <= k){ //处理所有人
        sort(minWin, minWin+n, cmp);
        int wIdx = minWin[0]; //取最早结束窗口号
        int topI = window[wIdx].q.front();
        window[wIdx].begin += processT[topI];
        window[wIdx].q.push(sf);
        window[wIdx].end += processT[sf];
        result[sf++] = window[wIdx].end;
        window[wIdx].q.pop();
    }
    while (q--) {
        int cIdx;
        cin >> cIdx;
        cout << cIdx << " ";
        printTime(result[cIdx]);
    }
    return 0;
}