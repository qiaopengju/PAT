/***********************************************
*      Filename: A1045.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 19:34:31
# Last Modified: 2021-03-13 20:34:18
************************************************/
#include <iostream>
#include <algorithm>
#define N 10005
using namespace std;

int dp[N]; //dp[i]:以i结尾的最长序列长度
int list[10005], favour[205];
bool isFav[N] = {false};
int main(){
    int n, m, l, color, ans(-1);
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) { //建立颜色大小映射
        scanf("%d", &color);
        favour[color] = i;
        isFav[color] = true;
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        dp[i] = 1;
        scanf("%d", &list[i]);
        for (int j = 0; j < i; j++){
            if (isFav[list[j]] && favour[list[j]]<=favour[list[i]] && dp[j]+1>dp[i])
                dp[i] = dp[j] + 1;
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}
