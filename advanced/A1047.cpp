//
// TODO
// 不懂为什么最后一个测试点超时
//

#include <iostream>
#include <set>

using namespace std;

void solution() {

    int course_count, student_count;
    cin>>student_count>>course_count;

    set<string> st[course_count + 1];
    string student_name;
    for (int i = 0; i < student_count; i++) {
        cin>>student_name;
        int registed_count, course_id;
        cin>>registed_count;
        for (int j = 1; j <= registed_count; j++) {
            cin>>course_id;
            st[course_id].insert(student_name);
        }
    }
    for (int i = 1; i <= course_count; i++) {
        cout<<i<<" "<<st[i].size()<<endl;
        for (set<string>::iterator it = st[i].begin(); it != st[i].end(); it++) {
            cout<<*it<<endl;
        }
    }
}

int main() {
    solution();
    return 0;
}