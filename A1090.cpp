/*3-6 4:30-*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

int n, num(1), pre[MAX] = {-1};
double r, maxW(0);
struct node{
    vector<int> child;
}tree[MAX];

void dfs(int root, double w){
    if (tree[root].child.empty()){ //叶子节点
        if (w > maxW){
            maxW = w;
            num = 1;
        } else if (w == maxW) num++;
        return;
    }
    for (int i = 0; i < tree[root].child.size(); i++)
        dfs(tree[root].child[i], w*r);
}
int main(){
    int root(-1), father;
    double p;
    cin >> n >> p >> r;
    r = 1 + r/100;
    for (int i = 0; i < n; i++){
        cin >> father;
        if (father != -1) tree[father].child.push_back(i);
        else root = i;
    }
    dfs(root, p);
    printf("%.2lf %d\n", maxW, num);

    return 0;
}
