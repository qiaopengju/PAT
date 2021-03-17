/***********************************************
*      Filename: A1038.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 14:05:42
# Last Modified: 2021-03-13 14:05:46
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline void eraseH0(string &s){
    while(!s.empty() && s[0] == '0') s.erase(s.begin());
}
bool cmp(string a, string b){return a+b < b+a;}
int main(){
    int n;
    cin >> n;
    vector<string> list(n);
    for (int i = 0; i < n; i++) cin >> list[i];
    sort(list.begin(), list.end(), cmp);
    string result = "";
    for (int i = 0; i < n; i++) result += list[i];
    eraseH0(result);
    if (result.empty()) result = "0";
    cout << result << endl;

    return 0;
}