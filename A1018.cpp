/*3-6 21:15-*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX_N 505
#define INF 99999999 
using namespace std;

int cMax, n, ed;
int G[MAX_N][MAX_N], weight[MAX_N] = {0};  //weight[0]:PBMC内是完美的
int d[MAX_N], need(INF), back(INF); 
bool visit[MAX_N] = {false};
vector<int> path, tmpPath, pre[MAX_N];
void dijkstra(){
    d[0] = 0;
    for (int i = 0; i <= n; i++){
        int min(INF), u = -1;
        for (int v = 0; v <= n; v++){ //find min
            if (!visit[v] && min > d[v]){
                min = d[v];
                u = v;
            }
        }
        if (u == -1) return;
        visit[u] = true;
        for (int v = 0; v <= n; v++){ //优化
            if (G[u][v]!=INF && !visit[v]){ //未访问过且连通
                if (d[u]+G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (d[u] + G[u][v] == d[v]) pre[v].push_back(u);
            }
        }
    }
}
void dfs(int v){
    tmpPath.push_back(v);
    if (v == 0){ //走到源点
        int tmpNeed(0), tmpBack(0);
        for (int i = tmpPath.size()-1; i>=0; i--){ //caculate 
            if (weight[tmpPath[i]] < 0){ //back
                tmpBack += -weight[tmpPath[i]];
            } else { //need
                if (tmpBack - weight[tmpPath[i]] > 0){ //冗余
                    tmpBack -= weight[tmpPath[i]];
                } else{ //不够
                    tmpNeed += weight[tmpPath[i]] - tmpBack;
                    tmpBack = 0;
                }
            }
        }
        if (tmpNeed < need){
            need = tmpNeed;
            back = tmpBack;
            path = tmpPath;
        } else if (tmpNeed == need && tmpBack < back){
            back = tmpBack;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    tmpPath.pop_back();
}

int main(){
    int m, v1, v2;
    fill(G[0], G[0]+MAX_N*MAX_N, INF);
    fill(d, d+MAX_N, INF);
    cin >> cMax >> n >> ed >> m;
    weight[0] = cMax / 2;
    for (int i = 1; i <= n; i++) cin >> weight[i];
    for (int i = 0; i <= n; i++) weight[i] = cMax/2 - weight[i];
    for (int i = 0; i < m; i++){
        cin >> v1 >> v2;
        cin >> G[v1][v2];
        G[v2][v1] = G[v1][v2];
    }
    dijkstra();
    dfs(ed);
    cout << need << " 0";
    for (int i = path.size()-2; i >= 0; i--) cout << "->" << path[i];
    cout << " " << back << endl;

    return 0;
}
