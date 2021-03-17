/***********************************************
*      Filename: A1059.cpp
*
*        Author: qiaopengju
*   Description: 质因数分解 
*        Create: 2021-03-14 14:27:47
# Last Modified: 2021-03-14 14:27:50
************************************************/
#include <iostream>
#include <vector>
#include <cmath>
#define N 500000
using namespace std;

vector<bool> prime(N, true);
struct factor {
    int x, cnt;
} fac[15];
void findPrime(){
    for (int i = 2; i * i < N; i++){
        if (prime[i]){
            for (int j = 2; i * j < N; j++) prime[i*j] = false;
        }
    }
}
int main(){
    long int n;
    int num(0);
    scanf("%ld", &n);
    printf("%ld=", n);
    if (n == 1) printf("1");
    findPrime();
    for (long i = 2; i < N; i++){
        if (prime[i] && n % i == 0){
            fac[num].x = i;
            fac[num].cnt = 0;
            while (n % i == 0) {
                fac[num].cnt++;
                n /= i;
            }
            num++;
        }
    }
    if (n > 1){
        fac[num].x = n;
        fac[num].cnt = 1;
        num++;
    }
    for (int i = 0; i < num; i++){
        if (i) printf("*");
        printf("%d", fac[i].x);
        if (fac[i].cnt != 1) printf("^%d", fac[i].cnt);
    }
    return 0;
}