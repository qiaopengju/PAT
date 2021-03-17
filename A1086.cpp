/*3-6 3:22-*/
#include <iostream>
#include <algorithm>
#include <stack>
#define MAX 35
using namespace std;

struct node{
    int l, r;
    node(){ l = r = -1; }
}bT[MAX];
int printNum(0);

void postOrder(int root){
    if (root == -1) return;
    postOrder(bT[root].l);
    postOrder(bT[root].r);
    if (printNum++) cout << " ";
    cout << root;
}
int main(){
    int n, idx, root(-1), pre(-1);
    bool lFlag = true;
    string state;
    stack<int> s;
    cin >> n;
    for (int i = 0; i < 2*n; i++){
        cin >> state;
        if (state == "Push"){
            cin >> idx;
            if (lFlag){ //压入左子树
                if (root == -1){ //根
                    s.push(idx);
                    root = idx;
                } else{
                    bT[s.top()].l = idx;
                    s.push(idx);
                }
            } else{ //压入右子树
                bT[pre].r = idx;
                lFlag = true;
                s.push(idx);
            }
        }else if(state == "Pop"){
            pre = s.top();
            s.pop();
            lFlag = false;
        }
    }
    postOrder(root);
    return 0;
}
