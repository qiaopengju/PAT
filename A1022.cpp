/***********************************************
*      Filename: A1022.cpp
*
*        Author: qiaopengju
*   Description: ---
*        Create: 2021-03-12 08:37:54
# Last Modified: 2021-03-12 09:21:59
************************************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

map<string, set<int> > title, author, key, publisher, year;
int main(){
    int n, m, id;
    char tmpc;
    cin >> n;
    for (int i = 0; i < n; i++){
        string t, a, k, p, y;
        cin >> id; getchar();
        getline(cin, t);
        title[t].insert(id);
        getline(cin, a);
        author[a].insert(id);
        do{
            cin >> k;
            tmpc = getchar();
            key[k].insert(id);
        } while (tmpc != '\n');
        getline(cin, p);
        publisher[p].insert(id);
        getline(cin, y);
        year[y].insert(id);
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        string search;
        scanf("%d: ", &id);
        getline(cin, search);
        cout << id << ": " << search << endl;
        switch(id){
            case 1: 
                if (title[search].size() == 0) cout << "Not Found" << endl;
                for (auto it : title[search]) printf("%07d\n", it); break;
            case 2: 
                if (author[search].size() == 0) cout << "Not Found" << endl;
                for (auto it : author[search]) printf("%07d\n", it); break;
            case 3: 
                if (key[search].size() == 0) cout << "Not Found" << endl;
                for (auto it : key[search]) printf("%07d\n", it); break;
            case 4: 
                if (publisher[search].size() == 0) cout << "Not Found" << endl;
                for (auto it : publisher[search]) printf("%07d\n", it); break;
            case 5: 
                if (year[search].size() == 0) cout << "Not Found" << endl;
                for (auto it : year[search]) printf("%07d\n", it); break;
        }
    }
    return 0;
}
