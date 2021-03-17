/*3-4 20:00-*/
#include <iostream>
#include <vector>
using namespace std;

int flag;
struct application{
    int id, ge, gi, fi, prefer[105], rank;
    bool flag; //true:录取
    friend bool operator < (application a, application b){
        return a.fi==b.fi ?  a.ge > b.ge : a.fi>b.fi;
    }
}A[40005], B[40005];

int main(){
    int n, m, k, S[105];
    vector<int> R[105];
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) cin >> S[i];
    for (int i = 0; i < n; i++){
        A[i].id = i;
        A[i].flag = false;
        cin >> A[i].ge >> A[i].gi;
        A[i].fi = (A[i].ge + A[i].gi) / 2;
        for (int j = 0; j < k; j++) cin >> A[i].prefer[j];
    }
    for (int i = 0; i < n; i++) B[i] = A[i];
    sort(A, A+n);
    /*排序*/
    A[0].rank = 0;
    for (int i = 1; i < n; i++){
        if (A[i].fi == A[i-1].fi && A[i].ge == A[i-1].ge) A[i].rank = A[i-1].rank;
        else A[i].rank = i;
    }
    //for (int i = 0; i < n; i++) cout << A[i].id << " " << A[i].rank << endl << endl;
    /*录取*/
    for (int i = 0; i < n; i++){
        if (A[i].flag) continue; //被录取了 跳过
        for (int j = 0; j < k; j++){
            int len = R[j].size() - 1;
            if (len+1 < S[j] || //学校未招满，录取
                    B[R[j][len]].rank == A[i].rank) { //与最后一名排名相同，录取
                A[i].flag = true;
                R[j].push_back(A[i].id);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) sort(R[i].begin(), R[i].end());
    for (int i = 0; i < m; i++){
        for (int j = 0; j < R[i].size(); j++){
            if (j) cout << " ";
            cout << R[i][j];
        }
        if (i != m-1) cout << endl;
    }

    return 0;
}
