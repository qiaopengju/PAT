/***********************************************
*      Filename: A1060.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-14 15:57:26
# Last Modified: 2021-03-14 15:57:30
************************************************/
#include <iostream>
using namespace std;

int n;
void standardS(string &s) {
    while(!s.empty() && s[0] == '0') s.erase(s.begin());
    int exp, pointPos = s.find(".");
    if (pointPos != string::npos){
        s.erase(s.begin()+pointPos); //删除小数点
        if (s[0] != '0') exp = pointPos;
        else {
            exp = 0;
            while(!s.empty() && s[0] == '0') {
                exp--;
                s.erase(s.begin());
            }
            if (s.empty()) exp = 0;
        }
    } else exp = s.size();
    if (s == "0") exp = 0;
    while(s.length() < n) s += "0";
    string stdS = "0." + s.substr(0, n) + "*10^" + to_string(exp);
    s = stdS;
}
int main(){
    string a, b;
    cin >> n >> a >> b;
    standardS(a);
    standardS(b);
    if (a == b) cout << "YES " << a << endl;
    else cout << "NO " << a << " " << b << endl;
    return 0;
}