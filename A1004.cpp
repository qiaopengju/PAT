/*3-6 14:30-*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 105
using namespace std;

struct node{
    int id, level;
    vector<int> child;
}tree[MAX]; //root从1开始
bool visit[MAX] = {false};
int high(0), result[MAX] = {0};

void bfs(){
    queue<int> q; //存编号
    q.push(1); //root编号入队
    tree[1].level = 0; //root层数为0
    while(!q.empty()){
        int r = q.front();
        visit[r] = true;
        q.pop();
        if (tree[r].level > high) high = tree[r].level;
        if (tree[r].child.size() == 0){
            result[tree[r].level] += 1;
        }
        for (int i = 0; i < tree[r].child.size(); i++){
            int child_idx = tree[r].child[i];
            q.push(child_idx); 
            tree[child_idx].level = tree[r].level + 1;
        }
    }
}

int main(){
    int n, m, idx, k, cIdx;
    cin >> n >> m;
    for (int i = 0; i < m; i++) { //input
        cin >> idx >> k;
        tree[idx].id = idx;
        while(k--) {
            cin >> cIdx;
            tree[idx].child.push_back(cIdx);
        }
    }
    bfs();
    for (int i = 0; i <= high; i++) {
        cout << result[i];
        if (i != high) cout << " ";
    }
    return 0;
}
