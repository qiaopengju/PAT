/*3-4 15:40-16:00*/
#include <iostream>
using namespace std;

void print13(int i){
    char a('0'), b; //第一位a，第二位b
    if (i % 13 < 10) b = i % 13 + '0';
    else {
        b = (i % 13) - 10 + 'A';
    }
    i /= 13;
    if (i % 13 < 10) a = i % 13 + '0';
    else {
        a = (i % 13) - 10 + 'A';
    }
    cout << a << b;
}

int main(){
    int R, G, B;
    cin >> R >> G >> B;
    cout << "#";
    print13(R);
    print13(G);
    print13(B);

    return 0;
}
