/***********************************************
*      Filename: A1021.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-11 20:44:39
# Last Modified: 2021-03-11 21:50:47
************************************************/
#include <iostream>
#include <algorithm>
#include <set>
#define N 10005
using namespace std;

int n, maxDepth(0);
bool G[N][N] = {false}, visit[N];
set<int> path;
void dfs(int R, int root, int depth){
    visit[root] = true;
    if (depth > maxDepth){
        maxDepth = depth;
        path.clear();
        path.insert(R+1);
    }else if (depth == maxDepth)
        path.insert(R+1);
    for (int i = 0; i < n; i++){
        if (!visit[i] && G[root][i]) dfs(R, i, depth+1);
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 1; i < n; i++){ //下标改为从0开始
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        G[u][v] = G[v][u] = true;
    }
    for (int r = 0; r < n; r++){ //从0到n-1求最长
        int com(0), u = r;
        fill(visit, visit+N, false);
        for (int i = 0; i < n; i++){
            if (!visit[u]) {
                dfs(u, u, 1);
                com++;
            }
            u = (u+1) % n;
        }
        if (com != 1){
            printf("Error: %d components\n", com);
            return 0;
        }
    }
    for (auto it : path) printf("%d\n", it);
    return 0;
}
