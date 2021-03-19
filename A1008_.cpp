#include <iostream>

using namespace std;

int main(){
    int n, time(0), floor(0), to;

    cin >> n;
    time += n * 5;
    for (int i = 0; i < n; i++){
        cin >> to;
        if (to > floor){
            time += ((to - floor) * 6);
        } else{
            time += ((floor - to) * 4);
        }
        floor = to;
    }
    cout << time;

    return 0;
}
