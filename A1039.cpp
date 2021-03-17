/***********************************************
*      Filename: A1039.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 14:59:48
# Last Modified: 2021-03-13 15:14:19
************************************************/
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int main(){
    int n, k, courseId, studNum;
    string name;
    cin >> n >> k;
    map<string, set<int> > stu;
    for (int i = 0; i < k; i++){
        cin >> courseId >> studNum;
        while(studNum--){
            cin >> name;
            stu[name].insert(courseId);
        }
    }
    while (n--){
        cin >> name;
        cout << name << " " << stu[name].size();
        for (auto it : stu[name]) cout << " " << it;
        cout << endl;
    }
    return 0;
}
