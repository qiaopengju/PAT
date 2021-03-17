/***********************************************
*      Filename: A1010.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-11 19:38:32
# Last Modified: 2021-03-11 20:41:24
************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

inline int toDigit(char c){ return isdigit(c) ? c - '0' : c - 'a' + 10; }
long long toTenRadix(string s, long long r){
    long long N(0);
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) N += pow(r, i) * toDigit(s[i]);
    return N;
}
int findRadix(string s, long long r, long long N){ //二分
    long long low = r, high = max(r, N);
    while(low <= high){
        r = (low + high) / 2;
        long long current = toTenRadix(s, r);
        if (current > N || current < 0) high = r - 1;
        else if (current == N) return r;
        else low = r + 1;
    }
    return -1;
}
int main(){
    string n1, n2;
    long long r1, r2;
    int tag;
    cin >> n1 >> n2 >> tag >> r1;
    if (tag == 2) swap(n1, n2);
    r2 = toDigit(*max_element(n2.begin(), n2.end())) + 1;
    r2 = findRadix(n2, r2, toTenRadix(n1, r1));
    if (r2 == -1) cout << "Impossible" << endl;
    else cout << r2 << endl;
    return 0;
}
