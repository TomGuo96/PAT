//
// Created by Tom Guo on 25/10/2017.
//

#include <iostream>
#include <vector>

using namespace std;

struct student {
    string name, id;
    int grade;
    student(string _name, string _id, int _grade):name(_name), id(_id), grade(_grade) {}
};

bool cmp(student s1, student s2) {
    return s1.grade > s2.grade;
}

void solution() {

    int size;
    cin>>size;

    vector<student> vi;
    string name, id;
    int grade;
    for (int i = 0; i < size; i++) {
        cin>>name>>id>>grade;
        vi.push_back(student(name, id, grade));
    }

    sort(vi.begin(), vi.end(), cmp);

    int floor, roof, start;
    cin>>floor>>roof;
    int count = 0;
    for (int i = 0; i < vi.size(); i++) {
        if (vi[i].grade >= floor && vi[i].grade <= roof) {
            if (count == 0)
                start = i;
            count++;
        }
    }

    if (count == 0)
        cout<<"NONE"<<endl;
    else
        for (int i = start, j = 0; j < count; i++, j++)
            cout<<vi[i].name<<" "<<vi[i].id<<endl;

}

int main() {
    solution();
    return 0;
}