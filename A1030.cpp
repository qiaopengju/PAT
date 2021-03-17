/*3-6 8:00-9:00*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 505
#define INF 100005
using namespace std;

int n, G[MAX_N][MAX_N], cost[MAX_N][MAX_N], min_cost(INF);
int c[MAX_N], d[MAX_N] = {0};
bool visit[MAX_N] = {false};
vector<int> path, tmp_path, pre[MAX_N];

void dijkstra(int st){
    d[st] = 0;
    c[st] = 0;
    for (int i = 0; i < n; i++){
        int min = INF, u = -1;
        for (int j = 0; j < n; j++){ //find min
            if (!visit[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if (u == -1) return; //无通路
        visit[u] = true;
        for (int v = 0; v < n; v++){ //优化
            if (!visit[v] && G[u][v] != INF){ //未访问且连通
                if (d[u] + G[u][v] < d[v]){
                    pre[v].clear();
                    pre[v].push_back(u); //前驱
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                } else if (d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u); //前驱
                    if (c[v] > c[u] + cost[u][v]) c[v] = c[u] + cost[u][v];
                }
            }
        }
    }
}
void dfs(int st, int v){ //st为源点，v为当前结点
    tmp_path.push_back(v); //当前结点压入
    if (v == st){ //走到叶子
        int tmp_cost(0);
        for (int i = tmp_path.size()-1; i > 0; i--){
            tmp_cost += cost[tmp_path[i]][tmp_path[i-1]];
        }
        if (tmp_cost < min_cost){
            min_cost = tmp_cost;
            path = tmp_path; //覆盖path
        }
        tmp_path.pop_back(); //出结点
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) dfs(st, pre[v][i]);
    tmp_path.pop_back();
}

int main(){
    int m, c1, c2, st, ed;
    cin >> n >> m >> st >> ed;
    fill(G[0], G[0]+MAX_N*MAX_N, INF);
    fill(cost[0], cost[0]+MAX_N*MAX_N, INF);
    fill(c, c+MAX_N, INF);
    fill(d, d+MAX_N, INF);
    for (int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        cin >> G[c1][c2];
        cin >> cost[c1][c2];
        G[c2][c1] = G[c1][c2];
        cost[c2][c1] = cost[c1][c2];
    }
    dijkstra(st);
    dfs(st, ed); //find path
    for (int i = path.size()-1; i >= 0; i--) cout << path[i] << " ";
    cout << d[ed] << " " << c[ed];

    return 0;
}
