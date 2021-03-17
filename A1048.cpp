/***********************************************
*      Filename: A1048.cpp
*
*        Author: qiaopengju
*   Description: two points
*        Create: 2021-03-13 21:08:56
# Last Modified: 2021-03-13 21:09:00
************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int coinList[100005], n, m;
int twoPoints(int low, int high, int coin){
    while(low <= high){
        int mid = (low + high) / 2;
        int sum = coinList[mid] + coin;
        if (sum == m) return mid;
        if (sum < m) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &coinList[i]);
    sort(coinList, coinList + n);
    for (int i = 0; i < n; i++){
        int l = twoPoints(0, i-1, coinList[i]);
        int r = twoPoints(i+1, n-1, coinList[i]);
        int ans = max(l, r);
        if (ans != -1) {
            printf("%d %d\n", coinList[i], coinList[ans]);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}
