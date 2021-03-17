#include <iostream>
using namespace std;

int main(){
    int a, b;
    string s;

    cin >> a >> b;
    a += b;
    if (a < 0) cout << "-";
    a = abs(a);
    s = to_string(a);

    if (a >= 1e6) s.insert(s.length() - 6, ",");
    if (a >= 1e3) s.insert(s.length() - 3, ",");
    cout << s << endl;

    return 0;
}
