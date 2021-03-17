/***********************************************
*      Filename: A1041.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 15:41:58
# Last Modified: 2021-03-13 15:42:03
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#define N 100005
using namespace std;

struct node{
    int data, idx;
};
vector<node> list;
int h[N] = {0};
bool cmp(node a, node b){ 
    return h[a.data]==h[b.data] ? a.idx<b.idx : h[a.data] < h[b.data];
}
int main(){
    int n;
    cin >> n;
    list.resize(n);
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        list[i].data = tmp;
        list[i].idx = i;
        h[tmp]++;
    }
    sort(list.begin(), list.end(), cmp);
    int result = list[0].data;
    if (h[result] == 1) cout << result << endl;
    else cout << "None" << endl;
    return 0;
}
