/*3-4 18:47-*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person{
    string name;
    int age, worth;
    friend bool operator < (person a, person b){
        return a.worth==b.worth ? 
            (a.age==b.age ? a.name<b.name : a.age<b.age) : a.worth > b.worth;
    }
}p[100005];

int main(){
    int n, k, m, min, max;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> p[i].name >> p[i].age >> p[i].worth;
    sort(p, p + n);
    for (int i = 0; i < k; i++){
        int outN(0); //输出数
        cin >> m >> min >> max;
        cout << "Case #" << i + 1 << ":\n";
        for (int j = 0; j < n && outN != m; j++){
            if (p[j].age >= min && p[j].age <= max){
                cout << p[j].name << " " << p[j].age << " " << p[j].worth << endl;
                outN++;
            }
        }
        if (!outN) cout << "None\n";
    }

    return 0;
}
