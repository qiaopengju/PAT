/***********************************************
*      Filename: A1056.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-14 08:49:17
# Last Modified: 2021-03-14 08:49:23
************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
#define N 1005
using namespace std;

struct node{
    int weight, rank;
} mice[N];
int main(){
    int np, ng, ct(0); //ct计数
    queue<int>contest; //顺序编号
    scanf("%d %d", &np, &ng);
    for (int i = 0; i < np; i++) scanf("%d", &mice[i].weight);
    for (int i = 0; i < np; i++) {
        int idx;
        scanf("%d", &idx);
        contest.push(idx);
    }
    int len = np, g = np % ng == 0 ? np / ng : np / ng + 1;
    int maxW = mice[contest.front()].weight, maxIdx = contest.front();
    while(!contest.empty()){
        int idx = contest.front();
        if (ct == len){ //到下一轮
            len = g;
            g = g % ng == 0 ? g / ng : g / ng + 1; //到下一轮，更新g
            ct = 0;
            maxW = mice[idx].weight;
            maxIdx = idx;
            cout << "Next turn, len:" << len << " g:" << g << endl;
        }
        if (ct % ng == 0 && ct != 0){ //到下一组
            maxW = mice[idx].weight;
            maxIdx = idx;
        }
        if (mice[idx].weight > maxW){
            maxW = mice[idx].weight;
            mice[maxIdx].rank = g + 1;
            maxIdx = idx;
        } else if (mice[idx].weight < maxW) mice[idx].rank = g + 1;
        cout << mice[idx].weight << " " << ct << endl;
        contest.pop();
        ct++;
        if (ct % ng == 0 && ct != 0){ //到下一组
            cout << "max: " << mice[maxIdx].weight << endl;
            contest.push(maxIdx);
        }
    }
    for (int i = 0; i < np; i++) {
        if (i) printf(" ");
        printf("%d", mice[i].rank);
    }
    return 0;
}