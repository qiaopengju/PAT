/***********************************************
*      Filename: A1019.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-10 19:43:16
# Last Modified: 2021-03-10 20:07:33
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, r, array[30], len(0);
    bool flag(true);
    cin >> n >> r;
    while(n != 0){ //转化为r进制数
        array[len++] = n % r;
        n /= r;
    }
    int i = 0, j = len - 1;
    while(i <= j){
        if (array[i] != array[j]){
            flag = false;
            break;
        }
        i++;
        j--;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    for (int k = len-1; k >= 0; k--){
        cout << array[k];
        if (k) cout << " ";
    }
    return 0;
}
