#include <cstdio>
#include <string>

using namespace std;

int main(){
    int tmp, sum(0);
    bool first(true);

    while(scanf("%1d", &tmp) != EOF) sum += tmp;
    string s = to_string(sum), tmp_s;
    for(int i = 0; i < s.length(); i++){
        switch(s[i]){
            case '0': tmp_s = "zero"; break;
            case '1': tmp_s = "one"; break;
            case '2': tmp_s = "two"; break;
            case '3': tmp_s = "three"; break;
            case '4': tmp_s = "four"; break;
            case '5': tmp_s = "five"; break;
            case '6': tmp_s = "six"; break;
            case '7': tmp_s = "seven"; break;
            case '8': tmp_s = "eight"; break;
            case '9': tmp_s = "nine"; break;
        }
        if (first){
            printf("%s", tmp_s.c_str());
            first = false;
        } else{
            printf(" %s", tmp_s.c_str());
        }
    }

    return 0;
}
