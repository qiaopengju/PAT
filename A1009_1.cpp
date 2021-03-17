#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int k, exp;
    float coe;
    map<int, float, greater<int> > poly1, poly2;

    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        scanf("%d %f", &exp, &coe);
        poly1[exp] = coe;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        int tmp_exp;
        float tmp_coe;

        scanf("%d %f", &exp, &coe);
        for (map<int, float>::iterator it = poly1.begin(); it != poly1.end(); it++){
            tmp_exp = it->first + exp;
            tmp_coe = it->second * coe;
            if (poly2.find(tmp_exp) != poly2.end()){
                poly2[tmp_exp] += tmp_coe;
                if (poly2[tmp_exp] == 0) poly2.erase(tmp_exp);
            } else poly2[tmp_exp] = tmp_coe;
        }
    }
    printf("%lu", poly2.size());
    for (map<int, float>::iterator it = poly2.begin(); it != poly2.end(); it++) printf(" %d %.1f", it->first, it->second);

    return 0;
}
