/*3-6 8:17-*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100005
using namespace std;

struct Node{
    int address, key, next;
    Node(){ next = -1; }
}node[MAX];
bool flag[MAX] = {false};
int main(){
    int head, n, pre(-1), tmpH;
    vector<Node> rL;
    cin >> head >> n;
    tmpH = head;
    for (int i = 0; i < n; i++){ //input
        int idx;
        cin >> idx;
        cin >> node[idx].key >> node[idx].next;
        node[idx].address = idx;
    }
    while(tmpH != -1){
        int tmpKey = node[tmpH].key;
        if (flag[abs(tmpKey)]){ //访问过,将本条移入remove list
            rL.push_back(node[tmpH]);
        }else{ //未访问过,链接pre，继续后移
            flag[abs(tmpKey)] = true;
            if (pre != -1) node[pre].next = tmpH;
            pre = tmpH;
        }
        tmpH = node[tmpH].next;
    }
    node[pre].next = -1;
    while(head != -1){
        printf("%05d %d ", head, node[head].key);
        if (node[head].next != -1) printf("%05d\n", node[head].next);
        else cout << "-1" << endl;
        head = node[head].next;
    }
    for (int i = 0; i < rL.size(); i++){
        printf("%05d %d ", rL[i].address, rL[i].key);
        if (i != rL.size() - 1) printf("%05d\n", rL[i+1].address);
    }
    if (rL.size() != 0) cout << "-1" <<endl;

    return 0;
}
