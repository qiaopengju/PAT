/*3-4 19:07-*/
#include <iostream>
#include <algorithm>
using namespace std;

int fmP[5] = {0}; //每题满分
struct user{
    int id ,sT, sP[5], acNum, rank;
    bool push[5], pass, ctC; //pass:跳过不输出 ctC编译错
    user(){ 
        for (int i = 0; i < 5; i++){ sP[i] = 0; push[i] = false; } 
        pass = true;
        ctC = false;
        acNum = 0;
        sT = 0;
    }
    friend bool operator < (user a, user b){
        if (a.sT == b.sT){
            if (a.acNum == b.acNum){
                return a.id < b.id;
            } else return a.acNum > b.acNum;
        } else return a.sT > b.sT;
    }
}u[10005];

int main(){
    int n, k, m, uI, pI, pso;
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++) cin >> fmP[i];
    for (int i = 0; i < m; i++){
        cin >> uI >> pI >> pso; pI--;
        u[uI].id = uI;
        u[uI].push[pI] = true;
        u[uI].pass = false; //提交过
        if (pso > u[uI].sP[pI]){ //比之前分高,或第一次提交编译错误
            u[uI].sP[pI] = pso;
            if (pso == fmP[pI]) u[uI].acNum++; //AC
        }
    }
    for (int i = 0; i < 10001; i++){ //求sT, pass 
        if (!u[i].pass){ //提交过代码
            bool flag(false);
            for (int j = 0; j < k; j++){
                if (u[i].sP[j] != 0) flag = true;
            }
            if (!flag) {
                u[i].pass = true;
                continue;
            }
            for (int j = 0; j < k; j++) {
                u[i].sT += u[i].sP[j];
            }
        }
    }
    sort(u, u+1000);
    u[0].rank = 1;
    for (int i = 1; i < n; i++){
        if (!u[i].pass){
            printf("%05d %d", u[i].id, u[i].sT);
            for (int j = 0; j < k; j++){
                if (!u[i].push[j]) printf(" -");
                else printf(" %d", u[i].sP[j]);
            }
            cout << endl;
        }
    }

    return 0;
}
