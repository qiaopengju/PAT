/*3-6 5:02-*/
#include <iostream>
#include <vector>
#define MAX 105
using namespace std;

int maxGen(0), gen(1);
struct node{
    vector<int> child;
}tree[MAX];
int num[MAX] = {0}; //每代人数

void dfs(int root, int depth){
    num[depth]++;
    if (num[depth] > maxGen){
        maxGen = num[depth];
        gen = depth;
    }
    if (tree[root].child.empty()) return; //叶子
    for (int i = 0; i < tree[root].child.size(); i++)
        dfs(tree[root].child[i], depth+1);
}
int main(){
    int n, m, idx, k;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> idx >> k;
        tree[idx].child.resize(k);
        for (int j = 0; j < k; j++) cin >> tree[idx].child[j];
    }
    dfs(1, 1);
    cout << maxGen << " " << gen << endl;

    return 0;
}
