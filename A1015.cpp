/***********************************************
*      Filename: A1015.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-10 17:04:44
# Last Modified: 2021-03-10 19:33:45
************************************************/
#include <iostream>
#include <string>
using namespace std;

bool isPrime(int n){
    if (n <= 1) return false; //1不是素数
    int len = int(sqrt(n));
    for (int i = 2; i <= len; i++) if (n % i == 0) return false;
    return true;
}
int rToTen(int n, int r){ //先转成r进制，再转成十进制
    string s;
    do{
        s.insert(s.end(), '0'+(n%r));
        n /= r;
    } while( n != 0);
    return stoi(s, nullptr, r);
}
int main(){
    int num, r;
    while(1){
        cin >> num;
        if (num < 0) break;
        cin >> r;
        if (isPrime(num)){
            if (isPrime(rToTen(num, r))) cout << "Yes\n";
            else cout << "No\n";
        }else cout << "No\n";
    }
    return 0;
}
