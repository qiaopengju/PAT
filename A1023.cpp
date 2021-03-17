/***********************************************
*      Filename: A1023.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-12 09:25:39
# Last Modified: 2021-03-12 09:38:10
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#define N 25
using namespace std;

int main(){
    int visit[10] = {0}, bigN1[N] = {0}, bigN2[N] = {0};
    int i, len1(0), len2(0), carry(0);
    while(scanf("%1d", &i) != EOF) {
        bigN1[len1++] = i;
        visit[i]++;
    }
    reverse(bigN1, bigN1 + len1);
    for (len2 = 0; len2 < len1; len2++){
        int tmp = bigN1[len2] * 2 + carry;
        carry = tmp / 10;
        tmp %= 10;
        visit[tmp]--;
        bigN2[len2] = tmp;
    }
    if (carry != 0){
        bigN2[len2++] = carry;
    }
    reverse(bigN2, bigN2+len2);
    bool flag = true;
    for (int i = 0; i < 10; i++){
        if (visit[i] != 0){
            flag = false;
            break;
        }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    for (int i = 0; i < len2; i++) cout << bigN2[i];
    return 0;
}
