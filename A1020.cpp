/*3-6 9:07-*/
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 35
using namespace std;

int n, postOrder[MAX], inOrder[MAX];
struct node{
    int l, r;
    node(){ l = -1; r = -1; };
}bt[MAX];

int createT(int pL, int pR, int iL, int iR){ //建树，返回root
    if (pL > pR) return -1;
    int k, r = postOrder[pR]; //根节点编号
    for (k = iL; k <= iR; k++) if (inOrder[k] == r) break; //找k
    int lenL = k - iL;
    bt[r].l = createT(pL, pL+lenL-1, iL, k-1); //构建左子树
    bt[r].r = createT(pL+lenL, pR-1, k+1, iR); //构建右子树
    return r;
}
void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int r = q.front();
        q.pop();
        if (r != root) cout << " ";
        cout << r;
        if (bt[r].l != -1) q.push(bt[r].l);
        if (bt[r].r != -1) q.push(bt[r].r);
    }
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> postOrder[i];
    for (int i = 0; i < n; i++) cin >> inOrder[i];
    int root = createT(0, n-1, 0, n-1);
    bfs(root);

    return 0;
}
