/***********************************************
*      Filename: A1054.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-13 22:51:05
# Last Modified: 2021-03-13 22:51:12
************************************************/
#include <iostream>
#include <map>
using namespace std;

map<int, int> graph;
int main(){
    int n, m, half, color;
    scanf("%d %d", &n, &m);
    half = (n * m) / 2;
    for (int i = 0; i < n * m; i++){
        scanf("%d", &color);
        if (graph.find(color) == graph.end()) graph[color] = 1;
        else graph[color]++;
        if (graph[color] >= half) {
            printf("%d\n", color);
            break;
        }
    }
    return 0;
}
