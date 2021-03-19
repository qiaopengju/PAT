#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int k, exp;
    float coe;
    map<int , float, greater<int> > poly;

    for (int i = 0; i < 2; i++){
        scanf("%d", &k);
        for (int j = 0; j < k; j++){
            scanf("%d %f", &exp, &coe);
            if (poly.find(exp) != poly.end()){
                poly[exp] += coe;
                if (poly[exp] == 0) poly.erase(exp);
            } else poly[exp] = coe;
        }
    }

    printf("%lu", poly.size());
    for (map<int, float>::iterator it = poly.begin(); it != poly.end(); it++){
        printf(" %d %.1f", it->first, it->second);
    }

    return 0;
}
