/*3-6 4:35-*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 99999
using namespace std;

struct node{
    int value, address, next;
    friend bool operator < (node a, node b){ return a.value < b.value; }
    node(){ next = -1; }
}Next[MAX];

int main(){
    int n, head, idx;
    cin >> n >> head;
    vector<node> list;
    for (int i = 0; i < n; i++){ 
        cin >> idx;
        cin >> Next[idx].value >> Next[idx].next;
        Next[idx].address = idx;
    }
    while(head != -1){
        list.push_back(Next[head]); //在队列中压入
        head = Next[head].next;
    }
    sort(list.begin(), list.end());
    n = list.size();
    if (n != 0) printf("%d %05d\n", n, list[0].address);
    else printf("0 -1\n");
    for (int i = 0; i < n; i++){
        int nextA;
        nextA = list[i+1].address;
        printf("%05d %d ", list[i].address, list[i].value);
        if (i != n-1) printf("%05d\n", nextA);
        else printf("-1\n");
    }

    return 0;
}
