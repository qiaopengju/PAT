#include <iostream>
#include <string>
#include <cstdio>

#define UNLOCK() min_h = h; min_m = m; min_s = s;\
            unlock_name = tmp_name
#define LOCK() max_h = h; max_m = m; max_s = s;\
            lock_name = tmp_name

using namespace std;

int min_h(25), min_m(0), min_s(0);
int max_h(0), max_m(0), max_s(0);
string tmp_name, unlock_name, lock_name;

int main(){
    int M, h, m, s;

    cin >> M;
    for (int i = 0; i < M; i++){
        cin >> tmp_name;
        scanf("%d:%d:%d", &h, &m, &s);
        if (h < min_h){
            UNLOCK();
        } else if (h == min_h){
            if (m < min_m){ 
                UNLOCK();
            } else if (m == min_m && s < min_s){
                UNLOCK();
            }
        }

        scanf("%d:%d:%d", &h, &m, &s);
        if (h > max_h){
            LOCK();
        } else if (h == max_h){
            if(m > max_m){
                LOCK();
            } else if (m == max_m && s > max_s){
                LOCK();
            }
        }
    }
    cout << unlock_name << " " << lock_name;

    return 0;
}
