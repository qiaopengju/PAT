/***********************************************
*      Filename: A1044.cpp
*
*        Author: qiaopengju
*   Description: lower_bound
*        Create: 2021-03-13 16:34:04
# Last Modified: 2021-03-13 16:34:08
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define N 100005
using namespace std;

int dp[N];
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
        int low = i, high = n+1, mid, sum;
        while(low < high){ //二分法找j
            mid = (low + high) / 2;
            sum = dp[mid] - dp[i] + chain[i];
            if (sum == m){
                flag = true;
                cout << i << "-" << mid << endl;
                break;
            }else if (sum > m) high = mid;
             else low = mid + 1;
        }
        sum = dp[low] - dp[i] + chain[i];
        if (sum < min && sum > m){
            min = sum;
            node.clear();
            node.push_back(make_pair(i, low));
        } else if (sum == min && sum > m){
            node.push_back(make_pair(i, low));
        }
    }
    if (!flag){
        for (auto it : node) cout << it.first << "-" << it.second << endl;
    }

    return 0;
}
