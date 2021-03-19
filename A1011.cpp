#include <cstdio>
#include <queue>

using namespace std;

struct Game{
    int i;
    float f;
};

priority_queue<Game> q[3];
bool operator <(Game a, Game b){
    return a.f < b.f;
}

int main(){
    float outcome(1);
    Game temp;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            scanf("%f", &temp.f);
            temp.i = j;
            q[i].push(temp);
        }
    }
    for (int i = 0; i < 3; i++){
        outcome *= q[i].top().f;
        switch(q[i].top().i){
            case 0: printf("W ");   break;
            case 1: printf("T ");   break;
            case 2: printf("L ");   break;
        }
    }
    printf("%.2f", (outcome * 0.65 - 1) * 2);

    return 0;
}
