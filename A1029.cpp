/***********************************************
*      Filename: A1029.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-12 19:13:57
# Last Modified: 2021-03-12 19:24:46
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<long> L1(n);
    for (int i = 0; i < n; i++) cin >> L1[i];
    cin >> m;
    for (int i = 0; i < m; i++){
        int num; cin >> num;
        L1.push_back(num);
    }
    sort(L1.begin(), L1.end());
    if ((n + m) % 2 == 1) cout << L1[(n + m) / 2] << endl;
    else cout << L1[(n+m-1) / 2] << endl;
    return 0;
}
