/*3-4 15:22-*/
#include <iostream>
using namespace std;

int main(){
    string s;
    int n1, n3, len;

    cin >> s;
    len = s.length();
    n1 = (len+2) / 3;
    n3 = len+2 - n1*2;
    for (int i = 0; i < n1-1; i++){
        cout << s[i];
        for (int j = 0; j < n3-2; j++) cout << " ";
        cout << s[len-i-1] << endl;
    }
    for (int i = n1-1; i < n1+n3-1; i++) cout << s[i];

    return 0;
}
