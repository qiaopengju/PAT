#include <iostream>
#define MAX_N 1000
using namespace std;

int main(){ 
    int K, tmpK;
    float tmpN, N[MAX_N + 1] = {0};

    for (int i = 0; i < 2; i++){
        cin >> K;
        for (int j = 0; j < K; j++){
            cin >> tmpK >> tmpN;
            N[tmpK] += tmpN;
        }
    }
    K = 0;
    for (int i = 0; i <= MAX_N; i++) if (N[i] != 0) K++;
    cout << K;
    for (int i = MAX_N; i >= 0; i--) if (N[i] != 0){
        cout << " " << i << " ";
        printf("%.1f", N[i]);
    }

    return 0;
}
