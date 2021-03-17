/*3-4 18:25-
 * vector超时，尝试用数组
 * */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int flag;
struct studInfo{
    string id, name;
    int grade;
    friend bool operator < (studInfo a, studInfo b){
        switch (flag) {
            case 1: return a.id < b.id; break;
            case 2: return a.name==b.name ? a.id<b.id : a.name<b.name; break;
            default: return a.grade==b.grade ? a.id < b.id : a.grade<b.grade; break;
        }
    }
}sV[100005];
int main(){
    int n;
    cin >> n >> flag;
    for (int i = 0; i < n; i++) cin >> sV[i].id >> sV[i].name >> sV[i].grade; //input
    sort(sV, sV+n);
    for (int i = 0; i < n; i++) cout << sV[i].id << " " << sV[i].name 
       << " " << sV[i].grade << endl; //output

    return 0;
}
