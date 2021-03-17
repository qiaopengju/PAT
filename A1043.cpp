/***********************************************
*      Filename: A1043.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 16:14:12
# Last Modified: 2021-03-13 16:14:18
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#define N 1005
using namespace std;

int n;
struct node{
    int left, right;
}bt[N];
vector<int> preOrder, inOrder, PostOrder;
int createTree(int pL, int pR, int inL, int inR){
}
int main(){
    cin >> n;
    preOrder.resize(n);
    inOrder.resize(n);
    PostOrder.resize(n);
    for (int i = 0; i < n; i++){
        cin >> preOrder[i];
        inOrder[i] = preOrder[i];
    }
    sort(inOrder.begin(), inOrder.end()); //中序序列
    int root = createTree(0, n - 1, 0, n - 1);
    return 0;
}
