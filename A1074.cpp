/*3-6 5:15-*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

struct Node{
    int data, address, next, order; //order为位序
    Node(){ next = -1; order = MAX; }
    friend bool operator < (Node a, Node b) { return a.order < b.order; }
}node[MAX], result[MAX];

int main(){
    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; i++){ //输入
        int idx;
        cin >> idx;
        cin >> node[idx].data >> node[idx].next;
        node[idx].address = idx;
    }
    while(head != -1){  //输出
        printf("%05d %d", head, node[head].data);
        if (node[head].next == -1) printf(" -1\n");
        else printf(" %05d\n", node[head].next);
        head = node[head].next;
    }
    return 0;
}
