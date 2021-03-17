/*3-9 7:29-*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    int st(0), ed(0), sum(-100005), n;
    bool flag(true); //全为负数
    cin >> n;
    vector<int> list(n); 
    vector<pair<int, int> >dp(n); //dp[i] 为以i结尾,first:最大和, second:前缀
    for (int i = 0; i < n; i++) {
        cin >> list[i];
        dp[i] = make_pair(list[i], i); //边界
        if (list[i] >= 0) flag = false;
    }
    if (flag) { //全负
        cout << "0 " << list[0] << " " << list[n-1] << endl;
        return 0;
    }
    sum = dp[0].first;
    for (int i = 1; i < n; i++){
        //dp[i] = max(dp[i], dp[i-1] + list[i]);
        if (dp[i-1].first + list[i] > dp[i].first){ //与之前的关联
            dp[i].first = dp[i-1].first + list[i];
            dp[i].second = dp[i-1].second; //继承之前的开始节点
        } 
        if (dp[i].first > sum){
            sum = dp[i].first;
            st = dp[i].second;
            ed = i;
        } 
    }
    cout << sum << " " << list[st] << " " << list[ed] << endl;

    return 0;
}
