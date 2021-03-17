/*3-4 20:00-*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int flag;
struct application{
    int id, ge, gi, fi, prefer[105], rank;
    bool flag; //true:录取
    friend bool operator < (application a, application b){
        return a.fi==b.fi ?  a.ge > b.ge : a.fi>b.fi;
    }
}A[40005];

int main(){
    int n, m, k, S[105], greastR[105] = {0};
    vector<int> R[105];
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) cin >> S[i];
    for (int i = 0; i < n; i++){
        A[i].id = i;
        A[i].flag = false;
        cin >> A[i].ge >> A[i].gi;
        A[i].fi = (A[i].ge + A[i].gi) / 2;
        for (int j = 0; j < k; j++) scanf("%d", &A[i].prefer[j]);
    }
    sort(A, A+n);
    /*排序*/
    A[0].rank = 0;
    for (int i = 1; i < n; i++){
        if (A[i].fi == A[i-1].fi && A[i].ge == A[i-1].ge) A[i].rank = A[i-1].rank;
        else A[i].rank = i;
    }
    /*录取*/
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            int idx = A[i].prefer[j];
            int len = R[idx].size() - 1;
            if (len+1 < S[idx] || //学校未招满，录取
                    greastR[idx] == A[i].rank) { //与最后一名排名相同，录取
                A[i].flag = true;
                R[idx].push_back(A[i].id);
                if (greastR[idx] < A[i].rank) greastR[idx] = A[i].rank;
                break;
            }
        }
    }
    /*输出*/
    for (int i = 0; i < m; i++){
        sort(R[i].begin(), R[i].end());
        for (int j = 0; j < R[i].size(); j++){
            if (j) cout << " ";
            cout << R[i][j];
        }
        cout << endl;
    }

    return 0;
}
