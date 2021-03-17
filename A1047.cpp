/***********************************************
*      Filename: A1047.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 20:37:12
# Last Modified: 2021-03-13 20:37:16
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> course[2505];
int main(){
    int n, k, c, cIdx;
    string name;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> name;
        scanf("%d", &c);
        for (int j = 0; j < c; j++){
            scanf("%d", &cIdx);
            course[cIdx].push_back(name);
        }
    }
    for (int i = 1; i <= k; i++){
        int len = course[i].size();
        printf("%d %d\n", i, len);
        sort(course[i].begin(), course[i].end());
        for (int j = 0; j < len; j++) cout << course[i][j] << "\n";
    }
    return 0;
}
