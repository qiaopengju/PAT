/*3-4 14:30-*/
#include <iostream>
#include <set>
using namespace std;

struct student{
    string name, gender, id;
    int grade;
    student(string _name, string _gender, string _id, int _grade):
        name(_name), gender(_gender), id(_id), grade(_grade) {}
    friend bool operator < (student A, student B){
        return A.grade < B.grade;
    }
};

int main(){
    int N, grade;
    string name, gender, id;
    bool girlAb(true), boyAb(true); //是否缺席
    set<student> boy, girl;

    cin >> N;
    while(N--){
        cin >> name >> gender >> id >> grade;
        if (gender == "M"){ //boy
            boyAb = false;
            boy.insert(student(name, gender, id, grade));
        }
        else{ //girl
            girlAb = false;
            girl.insert(student(name, gender, id, grade));
        }
    }
    set<student>::iterator boyIt, girlIt;
    if (!boyAb && !girlAb){
        boyIt = boy.begin();
        girlIt = girl.end();
        girlIt--;
        cout << girlIt->name << " " << girlIt->id << endl;
        cout << boyIt->name << " " << boyIt->id << endl;
        cout << girlIt->grade - boyIt->grade;
    }else{
        if (girlAb) cout << "Absent" << endl;
        else{
            girlIt = girl.end();
            girlIt--;
            cout << girlIt->name << " " << girlIt->id << endl;
        }
        if (boyAb) cout << "Absent" << endl;
        else{
            boyIt = boy.begin();
            cout << boyIt->name << " " << boyIt->id << endl;
        }
        cout << "NA";
    }

    return 0;
}
