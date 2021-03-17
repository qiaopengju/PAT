/*3-4 13:45-14:20*/
/*
 * 两个指数最大为1000多项式相乘，指数最大为2000
 * */
#include <iostream>
#define MAX_N 2000
using namespace std;

void print(float a[]){
    int len(0);
    for (int i = MAX_N; i+1; i--) if (a[i] != 0) len++;
    cout << len;
    for (int i = MAX_N; i+1; i--) {
        if (a[i] != 0){
            cout << " " << i;
            printf(" %.1f", a[i]);
        }
    }
}

int main(){
    int K, e;
    float c, coe[MAX_N+1] = {0}, tmp[MAX_N+1] = {0};

    cin >> K;
    while(K--){
        cin >> e >> c;
        coe[e] = c;
    }
    cin >> K;
    while(K--){
        cin >> e >> c;
        for (int i = 0; i < MAX_N+1; i++){
            if (coe[i] != 0){
                tmp[i + e] += coe[i] * c;
            }
        }
    }
    print(tmp);

    return 0;
}
