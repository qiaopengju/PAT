/*超时*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M, tmp, x, y;
    vector<int> p;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        p.push_back(tmp);
    }
    cin >>M;
    for (int i = 0; i < M; i++){
        int l(0), r(0), tmpX, tmpY;
        cin >> tmpX >> tmpY;
        x = --tmpX; y = --tmpY;
        while( x != y){
            r += p[x];
            x = (x+1) % N;
        }
        x = (tmpX + N - 1) % N; y = tmpY;
        while( (x+1)%N != y){
            l += p[x];
            x = (x + N - 1) % N;
        }
        cout << min(l, r);
        if (i != M - 1) cout << endl;
    }

    return 0;
}
