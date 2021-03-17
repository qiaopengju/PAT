/*3-6 10:00-*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 105
using namespace std;

int n, m, s;
vector<long long> path;
struct node{
    vector<int> child;
    long long w;
}bt[MAX];

bool cmp(int a, int b){ return bt[a].w > bt[b].w; }
void printPath(){
    for (int i = 0; i < path.size(); i++){
        printf("%lld", path[i]);
        if (i != path.size()-1) cout << " ";
        else cout << endl;
    }
}
void dfs(int root, long long w){
    w += bt[root].w;
    path.push_back(bt[root].w);
    if (w > s){ //求和大于s,返回
        path.pop_back();
        return;
    }
    if (bt[root].child.empty()){ //叶子，计算
        if (w == s) printPath(); //相等,返回
        path.pop_back();
        return;
    }
    if (w < s){ //小于,继续
        for (int i = 0; i < bt[root].child.size(); i++) dfs(bt[root].child[i], w);
    }
    path.pop_back();
}
int main(){
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) scanf("%lld", &bt[i].w);
    for (int i = 0; i < m; i++){
        int idx, k;
        cin >> idx >> k;
        for (int j = 0; j < k; j++){
            bt[idx].child.resize(k);
            cin >> bt[idx].child[j];
        }
    }
    for (int i = 0; i < n; i++) sort(bt[i].child.begin(), bt[i].child.end(), cmp); //对孩子结点sort
    dfs(0, 0);

    return 0;
}
