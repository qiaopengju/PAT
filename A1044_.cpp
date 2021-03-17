/***********************************************
*      Filename: A1044.cpp
*
*        Author: qiaopengju
*   Description: 暴力 超时
*        Create: 2021-03-13 16:34:04
# Last Modified: 2021-03-13 16:34:08
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define N 100005
using namespace std;

int dp[N] = {0};
int main(){
    int n, m, min(1000000005);
    vector<pair<int, int> > node;
    cin >> n >> m;
    vector<int> chain(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> chain[i];
        if (i != 0) dp[i] = chain[i] + dp[i-1];
        else dp[i] = chain[i];
    }
    bool flag = false;
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            int sum = dp[j] - dp[i] + chain[i];
            if (sum == m){
                flag = true;
                cout << i << "-" << j << endl;
            }
            else if (sum > m && sum < min){
                min = sum;
                node.clear();
                node.push_back(make_pair(i, j));
            } else if (sum > m && sum == min){
                node.push_back(make_pair(i, j));
            }
        }
    }
    if (!flag){
        for (auto it : node) cout << it.first << "-" << it.second << endl;
    }

    return 0;
}
