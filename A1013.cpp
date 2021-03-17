/***********************************************
*      Filename: A1013.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-10 09:38:47
# Last modified: 2021-03-10 09:47:25
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1005
using namespace std;

int n, G[MAX][MAX] = {0}, tmpG[MAX][MAX];
bool visit[MAX];

void inital(){
    fill(visit, visit+MAX, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            tmpG[i][j] = G[i][j];
    }
}
void dfs(int root){
    visit[root] = true;
    for (int v = 1; v <= n; v++){
        if (tmpG[root][v] && !visit[v]) dfs(v);
    }
}
int main(){
    int m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    while(k--){
        int num = -1, con;
        inital();
        cin >> con;
        for (int i = 1; i <= n; i++) tmpG[con][i] = tmpG[i][con] = 0; //不连通
        for (int i = 1; i <= n; i++){
            if (!visit[i]) {
                num++;
                dfs(i);
            }
        }
        cout << (num == 0 ? 0 : num-1) << endl;
    }

    return 0;
}
