#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    string s;

    while (cin >> a >> b){
        c = a + b;
        if (c < 0){
            cout << "-";
            c = abs(c);
        }
        s = to_string(c);
        if (c >= 1e6) s.insert(s.length()-6, ",");
        if (c >= 1e3) s.insert(s.length()-3, ",");
        cout << s << endl;
    }

    return 0;
}
