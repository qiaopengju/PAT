/***********************************************
*      Filename: A1050.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 22:34:09
# Last Modified: 2021-03-13 22:34:17
************************************************/
#include <iostream>
using namespace std;

bool flag[130] = {false};
int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.length(); i++){
        flag[s2[i] - ' '] = true;
    }
    for (int i = 0; i < s1.length(); i++){
        if (!flag[s1[i] - ' ']) putchar(s1[i]);
    }
    return 0;
}
