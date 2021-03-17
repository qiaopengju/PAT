/***********************************************
*      Filename: A1021.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-11 23:06:45
# Last Modified: 2021-03-11 23:34:00
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define N 10005
using namespace std;

int n, maxDepth(0);
vector<int> G[N];
set<int> result, tmp;
bool visit[N];

void dfs(int r, int depth){
    visit[r] = true;
    if (depth > maxDepth){
        maxDepth = depth;
        result.clear();
        result.insert(r);
    } else if (depth == maxDepth){
        result.insert(r);
    }
    for (int i = 0; i < G[r].size(); i++){
        if (!visit[G[r][i]]) dfs(G[r][i], depth+1);
    }
}
int main(){
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int com(0);
    fill(visit, visit+N, false);
    for (int i = 0; i < n; i++){ //第一遍dfs，找出离根最远的节点,判断连通性
        if (!visit[i]){
            dfs(i, 1);
            com++;
        }
    }
    if (com != 1) {
        cout << "Error: " << com << " components" << endl;
        return 0;
    }
    set<int> tmp;
    for (auto it : result) tmp.insert(it);
    /*再dfs一遍，得出所有结果*/
    fill(visit, visit+N, false);
    if (result.size() != 0){
        int r = *result.begin();
        dfs(r, 1);
    }
    for (auto it : tmp) result.insert(it);
    for (auto it : result) cout << it+1 << endl;
    return 0;
}
