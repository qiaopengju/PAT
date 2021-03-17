/*3-4 10:30-*/
#include <iostream>
#include <map>
#include <algorithm>
#define MAX 2005
using namespace std;

struct student{
    string id;
    int best, bIdx, score[4], rank[4];
    student() { best = MAX; }
}S[MAX];
int flag;
bool cmp(student a, student b){ return a.score[flag] > b.score[flag]; }

int main(){
    int n, m;
    string sId;
    map<string, bool> exit;

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> S[i].id >> S[i].score[1] >> S[i].score[2]>> S[i].score[3];
        S[i].score[0] = (S[i].score[1]+S[i].score[2]+S[i].score[3]) / 3; 
        exit[S[i].id] = true;
    }
    for (flag = 0; flag < 4; flag++){ //分别排名
        sort(S, S+n, cmp);
        for (int i = 0; i < n; i++){
            if (i!=0 && S[i].score[flag] == S[i-1].score[flag])
                S[i].rank[flag] = S[i-1].rank[flag];
            else S[i].rank[flag] = i+1;
            if (S[i].rank[flag] < S[i].best){
                S[i].best = S[i].rank[flag];
                S[i].bIdx = flag;
            }
        }
    }
    while(m--){ //查询成绩
        cin >> sId;
        if (exit.find(sId) != exit.end()){
            for (int i = 0; i < n; i++){
                if (S[i].id == sId){
                    cout << S[i].best;
                    switch(S[i].bIdx){
                        case 0: cout << " A"; break; 
                        case 1: cout << " C"; break;
                        case 2: cout << " M"; break;
                        case 3: cout << " E"; break;
                        default: break;
                    }
                }
            }
        }else cout << "N/A";
        if (m) cout << endl;
    }

    return 0;
}
