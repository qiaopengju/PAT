/***********************************************
*      Filename: A1057.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-14 10:10:47
# Last Modified: 2021-03-14 10:10:51
************************************************/
#include <iostream>
#include <algorithm>
#define N 100005
using namespace std;

int stack[N], cp[N], top;
int partition(int low, int high){
    int tmp = cp[low];
    while(low < high){
        while(low < high && cp[low] < cp[high]) high--;
        cp[low] = cp[high];
        while(low < high && cp[high] <= cp[low]) low++;
        cp[high] = cp[low];
    }
    cp[low] = tmp;
    return low;
}
inline void seekMedian(){
    for (int i = 0; i <= top; i++) cp[i] = stack[i];
    int low = 0, high = top, mid = (top+1)%2==0 ? (top+1)/2-1 : (top+2)/2-1;
    while(low <= high){
        int pari = partition(low, high);
        if (pari == mid) {
            printf("%d\n", cp[pari]);
            return;
        } else if(pari < mid) low = pari + 1;
        else high = pari - 1;
    }
}
int main(){
    int n, data;
    cin >> n;
    top = -1;
    for (int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        if (cmd == "Pop") {
            if (top == -1) printf("Invalid\n");
            else cout << stack[top--] << endl;
        } else if (cmd == "Push"){
            cin >> stack[++top];
        } else if (cmd == "PeekMedian"){
            if (top == -1) printf("Invalid\n");
            else seekMedian();
        }
    }
    return 0;
}
