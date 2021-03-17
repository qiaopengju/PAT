/*3-4 6:40-*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, m, mark[5];
class user{
    public:
    int id, total, acNum, p[5], rank, flag; //flag:1 输出
    bool sub[5];
    user(){ 
        flag = 0;
        total = 0;
        acNum = 0;
        memset(p, 0, sizeof(p));
        memset(sub, false, sizeof(sub));
    }
    void sum(){ total = 0; for (int i = 0; i < k; i++) total += p[i]; } //求total
    void push(int uId, int pId, int score){
        id = uId;
        if (score != -1) flag = 1;
        sub[pId] = true;
        if (score > p[pId]) {
            p[pId] = score;
            if (score == mark[pId]) acNum++;
        }
    }
    friend bool operator < (user a, user b){
        return a.total == b.total ? 
            (a.acNum == b.acNum ? a.id<b.id : a.acNum>b.acNum) : a.total>b.total;
    }
}u[10005];

int main(){
    int uId, pId, pso;
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++) cin >> mark[i];
    for (int i = 0; i < m; i++){
        cin >> uId >> pId >> pso;
        uId--; pId--;
        u[uId].push(uId+1, pId, pso);
    }
    for (int i = 0; i < n; i++) u[i].sum(); //求total
    sort(u, u+n);
    u[0].rank = 1;
    for (int i = 1; i < n; i++){
        if (u[i].total == u[i-1].total) u[i].rank = u[i-1].rank;
        else u[i].rank = i+1;
    }
    for (int i = 0; i < n; i++){
        if (u[i].flag){ 
            printf("%d %05d %d", u[i].rank, u[i].id, u[i].total);
            for (int j = 0; j < k; j++){ 
                if (u[i].sub[j]) cout << " " << u[i].p[j];
                else cout << " -";
            }
            cout << endl;
        }
    }

    return 0;
}
