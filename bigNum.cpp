/*3-4 10:20-*/
/*大数*/
#include <iostream>
#include <cstring> //memset
#define N 25
using namespace std;

bool eq = false;
struct bigN{
    int data[N];
    int len;
    bool sig; //符号
    bigN(){
        len = 0;
        sig = true;
        memset(data, 0, sizeof(data));
    }
};
bigN toBigN(string s){
    bigN tmp;

    if (s[0] == '-'){ //<0
        tmp.sig = false;
        s.erase(s.begin());
    }
    for (int i = 0; i < s.length(); i++) {
        tmp.data[i] = s[s.length() - i - 1] - '0';
        tmp.len++;
    }
    return tmp;
}
void standBigN(bigN &A){
    while(A.data[A.len-1] == 0) A.len--;
}
void print(bigN A){
    if (!A.sig) cout << "-";
    for (int i = 0; i < A.len; i++) cout << A.data[A.len - i -1];
    cout << endl;
}
bool cmpAbs(bigN A, bigN B){ //|A|>|B| ?
    eq = false;
    if (A.len > B.len) return true;
    if (A.len < B.len) return false;
    for (int i = A.len-1; i+1; i--){ //A.len == B.len
        if (A.data[i] > B.data[i]) return true;
        if (A.data[i] < B.data[i]) return false;
    }
    eq = true;
    return false;
}
bool cmp(bigN A, bigN B){ //A>B ?
    bool absGreater = cmpAbs(A, B);
    if (A.sig && B.sig) return absGreater; //A>=0, B>=0
    else if (A.sig && !B.sig) return true; //A>=0, B<0
    else if (B.sig) return false; //A<0, B>=0
    else{ //A<0, B<0
        if (eq) return false;
        return !absGreater;
    }
}
bigN add(bigN A, bigN B){ //A+B
    int c(0), i, ans; //carry
    bigN tmp;

    if (!A.sig) tmp.sig = false; //signal
    for (i = 0; i < A.len || i < B.len; i++){
        ans = A.data[i] + B.data[i] + c;
        tmp.data[i] = ans % 10;
        c = ans / 10;
    }
    tmp.len = i;
    tmp.data[i] = c;
    if (B.len > A.len) A = B;
    for (; i < A.len; i++){
        tmp.data[i] += A.data[i];
    }
    standBigN(tmp);
    return tmp;
}
bigN sub(bigN A, bigN B){ //A-B
    bool absGreater = cmpAbs(A, B);
    bigN tmp;
    int i;

    if (!absGreater) swap(A, B);//|A| < |B|, swap(A, B); 
    if (!A.sig) tmp.sig = false;//signal
    /*sub*/
    for (i = 0; i < A.len; i++){
        if (A.data[i] < B.data[i]){
            int j(1);
            while (i+j < A.len && A.data[i+j] == 0){
                A.data[i+j] = 9;
                j++;
            }
            A.data[i+j]--;
            A.data[i] += 10;
            
        }
        tmp.data[i] = A.data[i] - B.data[i]; 
    }
    tmp.len = i;
    standBigN(tmp);
    return tmp;
}

int main(){
    int T;
    bigN A, B, C, S;
    string sA, sB, sC;

    cin >> T;
    for (int i = 1; i <= T; i++){
        cin >> sA  >> sB >> sC;
        A = toBigN(sA);
        B = toBigN(sB);
        C = toBigN(sC);
        if (A.sig){ //A>=0
            if (B.sig) S = add(A, B);// B>=0, A+B
            else S = sub(A, B); //B<0, A-B
        }else{ //A<0
            if (B.sig) S = sub(B, A);// B>=0, B-A
            else S = add(A, B); //B<0, A+B
        }

        cout << "Case #" << i << ": ";
        if (cmp(S, C)) cout << "true";
        else cout << "false";
        if (i!=T) cout << endl;
    }

    return 0;
}
