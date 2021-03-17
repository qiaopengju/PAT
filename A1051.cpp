/*3-6 11:30-*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    while(k--){
        int sf(0);
        bool flag = false;
        stack<int> S; 
        vector<int> seq(n);
        for (int i = 0; i < n; i++) cin >> seq[i];
        for (int i = 1; i <= n; i++){
            S.push(i);
            if (S.size() > m) break;
            while (!S.empty() && seq[sf] == S.top()){
                S.pop();
                sf++;
            }
        }
        if (sf == n) flag = true;
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
