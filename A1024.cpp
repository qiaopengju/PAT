/***********************************************
*      Filename: A1024.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-12 09:44:22
# Last Modified: 2021-03-12 10:41:55
************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

bool isPaliNum(string n){
    int i = 0, j = n.size() - 1;
    for (; i < j; i++, j--) if (n[i] != n[j]) return false; 
    return true;
}
void add(string& s){
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    int carry(0);
    for (int i = s.size() - 1; i >= 0; i--){
        int sum = s[i] + tmp[i] + carry - '0'*2;
        carry = sum / 10;
        s[i] = (sum % 10) + '0';
    }
    if (carry != 0) s.insert(s.begin(), carry+'0');
}
int main(){
    int k, step(0);
    string n;
    cin >> n >> k;
    for (step = 1; step <= k; step++){
        if (isPaliNum(n)) break;
        add(n);
    }
    cout << n << endl << step - 1;
    return 0;
}
