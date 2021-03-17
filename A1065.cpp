/*3-4 10:20-*/
/*大数*/
#include <iostream>
using namespace std;

int main(){
    int n;
    long long a, b, c, sum;

    cin >> n;
    for (int i = 0; i < n; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        sum = a + b;
        if (a > 0 && b > 0 && sum < 0) printf("Case #%d: true", i+1);//overflow >
        else if (a < 0 && b < 0 && sum >= 0) printf("Case #%d: false", i+1);//overflow < 
        else if (sum > c) printf("Case #%d: true", i+1);//sum > c
        else printf("Case #%d: false", i+1);//sum <= c
        if (i != n-1) cout << endl;
    }

    return 0;
}
