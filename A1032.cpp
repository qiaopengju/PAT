/*3-6 3:44-*/
#include <iostream>
#include <map>
#define MAX_N 99999
using namespace std;

bool visit[MAX_N] = {false};
int Next[MAX_N] = {-1};
int main(){
    int b1, b2, n, idx;
    string tmp;
    cin >> b1 >> b2 >> n;
    for (int i = 0; i < n; i++){
        cin >> idx >> tmp;
        cin >> Next[idx];
    }
    while(b1 != -1){ //处理第一个链
        visit[b1] = true;
        b1 = Next[b1]; //next
    }
    while(b2 != -1){
        if (visit[b2]){ 
            printf("%05d\n", b2);
            break;
        }
        b2 = Next[b2]; //next
    }
    if (b2 == -1) cout << "-1" << endl; //错误

    return 0;
}
