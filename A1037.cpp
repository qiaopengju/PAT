/***********************************************
*      Filename: A1037.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 13:45:41
# Last Modified: 2021-03-13 13:57:59
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b) {return a > b;}
int main(){
    int n, tmp, result(0);
    vector<int> pos1, pos2, neg1, neg2;
    cin >> n;
    while(n--){
        cin >> tmp;
        if (tmp > 0) pos1.push_back(tmp);
        else neg1.push_back(tmp);
    }
    cin >> n;
    while(n--){
        cin >> tmp;
        if (tmp > 0) pos2.push_back(tmp);
        else neg2.push_back(tmp);
    }
    /*正数从大到小排，负数从小到大排*/
    sort(pos1.begin(), pos1.end(), cmp);
    sort(pos2.begin(), pos2.end(), cmp);
    sort(neg1.begin(), neg1.end());
    sort(neg2.begin(), neg2.end());
    for (int i = 0; i < min(pos1.size(), pos2.size()); i++)
        result += pos1[i] * pos2[i];
    for (int i = 0; i < min(neg1.size(), neg2.size()); i++)
        result += neg1[i] * neg2[i];
    cout << result << endl;
    return 0;
}

