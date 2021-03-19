#include <iostream>
#include <string>
#include <vector>
#define GET_IDX() cin >> id;\
        idx = (id[0] - '0') * 10 + id[1] - '0' - 1
using namespace std;

struct Tree{
    vector<int> child;
}tree[100];

int main(){
    int N, M, k, idx, father, out;
    string id;

    cin >> N >> M;
    for (int i = 0; i < M; i++){
        GET_IDX();
        father = idx;
        cin >> k;
        for (int j = 0; j < k; j++){
            GET_IDX();
            tree[father].child.push_back(idx);
        }
    }
    idx = 0;
    while(N > 0){
        father = idx;
        out = 0;
    }
}
