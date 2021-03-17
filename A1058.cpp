/*3-4 15:00-15:10*/
/*
 *加法模拟
 * s = (a + b + carry) % r;
 * carry = (a + b + carry) / r;
 * carry 
 * */
#include <cstdio>

int main(){
    int xS, xK, yS, yK, s(0) ,k;
    long long xG, yG, g(0);

    scanf("%lld.%d.%d %lld.%d.%d", &xG, &xS, &xK, &yG, &yS, &yK);
    k = xK + yK;
    if (k >= 29){
        k %= 29;
        s++;
    }
    s += (xS + yS);
    if (s >= 17){
        s %= 17;
        g++;
    }
    g += (xG + yG);
    printf("%lld.%d.%d", g, s, k);

    return 0;
}
