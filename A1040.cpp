/***********************************************
*      Filename: A1040.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 15:14:47
# Last Modified: 2021-03-13 15:41:16
************************************************/
#include <iostream>
#define N 1005
using namespace std;

int dp[N][N] = {0}; //dp[i][j]表示从i - j是否是回文串
int main(){
    int result(1);
    string s;
    getline(cin, s);
    int n = s.size();
    for (int i = 0; i < n; i++) { //边界
        dp[i][i] = 1; //自身回文串长度为1
        if (i+1 < n && s[i] == s[i+1]) {
            dp[i][i+1] = 2;
            result = 2;
        }
    }
    for (int len = 2; len < n; len++){ //从长度为3开始
        for (int i = 0; i + len < n; i++){
            if (dp[i+1][i+len-1] && s[i] == s[i+len]) {
                dp[i][i+len] = 1;
                result = len + 1;
            }
            if (s[i] != s[i+len]) dp[i][i+len] = 0;
        }
    }
    cout << result << endl;
    return 0;
}
