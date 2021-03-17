/***********************************************
*      Filename: A1061.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-14 17:11:44
# Last Modified: 2021-03-14 17:11:50
************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

string W[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main(){
    int d, h, m;
    string s1, s2, s3, s4;
    bool day(false);
    cin >> s1 >> s2 >> s3 >> s4;
    int len1 = min(s1.length(), s2.length());
    int len2 = min(s3.length(), s4.length());
    for (int i = 0; i < len1; i++){
        if (s1[i] == s2[i]){
            if (!day && s1[i]>='A' && s1[i]<='G'){
                d = s1[i] - 'A';
                day = true;
            } else if (day){
                if (s1[i] >= 'A' && s1[i] <= 'N') {
                    h = s1[i] - 'A' + 10;
                    break;
                } else if (isdigit(s1[i])) {
                    h = s1[i] - '0';
                    break;
                }
            }
        }
    }
    for (int i = 0; i < len2; i++) 
        if (s3[i] == s4[i] && isalpha(s3[i])){
            m = i;
            break;
        }
    cout << W[d];
    printf(" %02d:%02d\n", h, m);
    return 0;
}
