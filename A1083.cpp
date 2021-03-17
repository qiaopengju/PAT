/*3-4 19:46-19:59*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student{
    public:
    int grade;
    string name, id;
    friend bool operator < (student a, student b){ return a.grade > b.grade; }
};
int main(){
    int n, l, h, outN(0);
    cin >> n;
    vector<student> s(n);
    for (int i = 0; i < n; i++){ cin >> s[i].name >> s[i].id >> s[i].grade; }
    sort(s.begin(), s.end());
    cin >> l >> h;
    for (int i = 0; i < n; i++){
        if (s[i].grade < l) break;
        if (s[i].grade <= h && s[i].grade >= l){
            cout << s[i].name << " " << s[i].id << endl;
            outN++;
        }
    }
    if (outN == 0) cout << "NONE";

    return 0;
}
