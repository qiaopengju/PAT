/*3-6 6:46-
 * Dijkstra
 * */
#include <iostream>
#include <algorithm>
#define MAX_N 505
#define INF 1000000
using namespace std;

int n, weight[MAX_N]={0}, w[MAX_N] = {0}, 
    num[MAX_N]={0}, G[MAX_N][MAX_N]={0}, d[MAX_N];
bool visit[MAX_N] = {false};

void dijkstra(int c1, int c2){
    w[c1] = weight[c1];
    d[c1] = 0;
    num[c1] = 1;
    for (int i = 0; i < n; i++){ //循环n次
        int min = INF, u = -1;
        for (int j = 0; j < n; j++){ //找出最小的顶点u
            if (!visit[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if (u == -1) return; //非通路
        visit[u] = true; //访问改点
        for (int j = 0; j < n; j++){ //改进其他点
            if (!visit[j] && G[u][j]!=INF) { //未访问过j 且连通
                if (d[u] + G[u][j] < d[j]) { //一条最短路
                    d[j] = d[u] + G[u][j];
                    num[j] = num[u];
                    w[j] = w[u] + weight[j];
                } else if (d[u] + G[u][j] == d[j]) { //多条最短路
                    num[j] += num[u]; 
                    if (w[u]+weight[j] > w[j]) w[j] = w[u] + weight[j];
                }
            }
        }
    }
}
int main(){
    int m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    fill(G[0], G[0]+MAX_N*MAX_N, INF);
    fill(d, d+MAX_N, INF);
    for (int i = 0; i < n; i++) cin >> weight[i]; //input w
    for (int i = 0; i < m; i++){ //input G
        int c3, c4;
        cin >> c3 >> c4;
        cin >> G[c3][c4];
        G[c4][c3] = G[c3][c4];
    }
    dijkstra(c1, c2); //求出最短路
    cout << num[c2] << " " << w[c2] << endl;

    return 0;
}
