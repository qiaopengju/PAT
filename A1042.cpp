/*3-3 20:54-21:32*/
#include <iostream>
#define NUM_CARDS 54
using namespace std;

int main(){
    int K, pos[NUM_CARDS + 1];
    string Cards[NUM_CARDS + 1], tmp[NUM_CARDS + 1];

    /*inital Cards[]*/
    for (int i = 1; i <= 13; i++) Cards[i] = "S";
    for (int i = 1; i <= 13; i++) Cards[i + 13] = "H";
    for (int i = 1; i <= 13; i++) Cards[i + 26] = "C";
    for (int i = 1; i <= 13; i++) Cards[i + 39] = "D";
    for (int i = 1; i <= NUM_CARDS - 2; i++) Cards[i] += to_string((i-1) % 13 + 1);
    Cards[53] = "J1";
    Cards[54] = "J2";

    cin >> K;
    for (int i = 1; i <= NUM_CARDS; i++) cin >> pos[i];
    while(K--){
        for (int i = 1; i <= NUM_CARDS; i++) tmp[pos[i]] = Cards[i];
        for (int i = 1; i <= NUM_CARDS; i++) Cards[i] = tmp[i];
    }
    cout << Cards[1];

    for (int i = 2; i <= NUM_CARDS; i++) cout << " " << Cards[i];

    return 0;
}
