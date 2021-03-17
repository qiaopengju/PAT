/*3-4 14:30-*/
#include <iostream>
#include <vector>
using namespace std;

struct account{
    string usr, psw;
    account (string _usr, string _psw): usr(_usr), psw(_psw) {}
};

int main(){
    int N;
    vector<account> A;
    string usr, psw;

    cin >> N;
    for (int i = 0; i < N; i++){
        bool mod(false);
        int p;

        cin >> usr >> psw;
        while(psw.find("1") != string::npos){
            p = psw.find("1");
            psw.replace(p, 1, "@");
            mod = true; 
        }
        while(psw.find("0") != string::npos){
            p = psw.find("0");
            psw.replace(p, 1, "%");
            mod = true; 
        }
        while(psw.find("l") != string::npos){
            p = psw.find("l");
            psw.replace(p, 1, "L");
            mod = true; 
        }
        while(psw.find("O") != string::npos){
            p = psw.find("O");
            psw.replace(p, 1, "o");
            mod = true; 
        }
        if (mod) A.push_back(account(usr, psw));
    }
    if (A.size() == 0){
        if (N == 1) cout << "There is " << N << " account and no account is modified";
        else cout << "There are " << N << " accounts and no account is modified";
    }
    else{
        cout << A.size() << endl;
        for(int i = 0; i < A.size(); i++){
            cout << A[i].usr << " " << A[i].psw;
            if (i != A.size()-1) cout << endl;
        }
    }

    return 0;
}
