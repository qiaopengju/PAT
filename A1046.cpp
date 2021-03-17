/*3-3 22:58-*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M, tmp, x, y;
    vector<int> p, L, R;

    cin >> N;
    R.push_back(0);
    for(int i = 0; i < N; i++){
        cin >> tmp;
        p.push_back(tmp);
        R.push_back(tmp + R[i]);//存储1顺时针到i的距离
    }
    for (int i = 0; i < N-1; i++){
        L.push_back(i == 0 ? p[N-i-1] : p[N-i-1]+L[i-1]);
    }
    L.push_back(0);
    reverse(L.begin(), L.end());
    cin >>M;
    for (int i = 0; i < M; i++){
        int l, r;
        cin >> x >> y;
        x--; y--;
        l = x<=y ? L[y] + R[x] : R[x] - R[y];
        r = x<=y ? R[y] - R[x] : L[x] + R[y];
        cout << min(l,r);
        if (i != M - 1) cout << endl;
    }

    return 0;
}
