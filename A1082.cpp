/*3-4 19:00-*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int len, sf(0);
    bool f1(false), f2(false);
    string N;
    string D[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    string L[9] = {"\0", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};

    cin >> N;
    if (N[0] == '-'){
        cout << "Fu ";
        N.erase(N.begin());
    }
    reverse(N.begin(), N.end());
    len = N.length();
    for (int i = 0; i < len; i++){//偏移,f1=true表示非零
        if (f1) break;
        if (N[i] == '0') sf++;
        else f1 = true;
    }
    if (len == 1 && N[0] == '0') cout << "ling"; //特判，0输出ling
    for (int i = len-1; i >= sf; i--){ //f2=true表示上一个是0
        if (N[i] == '0') f2 = true;
        else {
            if (f2) cout << " ling";
            f2 = false;
        }
        if (!f2){
            if (i != len-1) cout << " ";
            cout << D[N[i]-'0']; //print digit
        }
        if ((!f2 || i == 4) && i != 0) cout << " " << L[i];
    }

    return 0;
}
