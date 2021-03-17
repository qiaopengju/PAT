/*3-6 11:14-*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

double total(0), r;
struct node{
    bool flag; //true：retailer
    int saleNum;
    vector<int> child;
    node() { flag = false; saleNum = 0;}
}tree[MAX];

void dfs(int root, double w){
    if (tree[root].flag) {
        total += w*tree[root].saleNum;
    }
    if (tree[root].child.empty()) return; //叶子 
    for (int i = 0; i < tree[root].child.size(); i++) 
        dfs(tree[root].child[i], w*r);
}
int main(){
    int n, k;
    double p;
    cin >> n >> p >> r;
    r /= 100;
    r += 1;
    for (int i = 0; i < n; i++){
        cin >> k;
        if (k) {
            tree[i].child.resize(k);
            for (int j = 0; j < k; j++) cin >> tree[i].child[j];
        } else{  //零售商，叶子
            cin >> tree[i].saleNum;
            tree[i].flag = true;
        }
    }
    dfs(0, p);
    printf("%.1lf\n", total);

    return 0;
}
