/*3-4 17:05-*/
/*
 *最长后缀，反过来比方便 reverse(begin(), end())
 * */
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, minL(257), idx;
    bool flag(true);
    string s;
    vector<string> v;

    cin >> N;
    getchar(); //吃回车，后跟getline
    for (int i = 0; i < N; i++){
        getline(cin, s);
        v.push_back(s);
        minL = s.length() < minL ? s.length() : minL;
    }
    s.clear();
    for (idx = 0; idx < minL; idx++){
        for (int i = 1; i < N; i++){
            int len1 = v[i].length();
            int len2 = v[i-1].length();
            if (v[i][len1-idx-1] != v[i-1][len2-idx-1]) flag = false;
        }
        if (!flag) break;
    }
    if (idx != 0){
        s = v[0].substr(v[0].length() - idx, idx);
        cout << s;
    }else cout << "nai";

    return 0;
}
