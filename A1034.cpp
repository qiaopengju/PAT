/***********************************************
*      Filename: A1034.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 13:11:39
# Last Modified: 2021-03-13 13:38:17
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define N 2010
using namespace std;

map<string, int> s2i;
map<int, string> i2s;
map<string, int> ans;

int n, k, sf(0);
int G[N][N] = {0}, W[N] = {0};
bool visit[N] = {false};

int getInt(string s){
    if (s2i.find(s) == s2i.end()){
        s2i[s] = sf;
        i2s[sf++] = s;
    }
    return s2i[s];
}
void dfs(int root, int &head, int &memNum, int &totalW){ //用引用的dfs
    visit[root] = true;
    memNum++;
    if (W[head] < W[root]) head = root;
    for (int i = 0; i < n; i++){
        if (G[root][i] != 0){
            totalW += G[root][i];
            G[root][i] = G[i][root] = 0;
            if (!visit[i]) dfs(i, head, memNum, totalW);
        }
    }
}
void dfsTravel(){
    for (int i = 0; i < n; i++){
        if (!visit[i]){
            int head = i, memNum = 0, totalW = 0;
            dfs(i, head, memNum, totalW);
            if (memNum > 2 && totalW > k) ans[i2s[head]] = memNum;
        }
    }
}
int main(){
    int w;
    string n1, n2;
    cin >> n >> k;
    for (int i = 0; i < n; i++){ //input
        cin >> n1 >> n2 >> w;
        int u = getInt(n1);
        int v = getInt(n2);
        G[u][v] += w;
        G[v][u] += w;
        W[u] += w;
        W[v] += w;
    }
    dfsTravel();
    cout << ans.size() << endl;
    for (auto it : ans) cout << it.first << " " << it.second << endl;
    return 0;
}

