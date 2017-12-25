//
// Created by Tom Guo on 25/10/2017.
//

#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>

using namespace std;

struct node {
    int address, data, next;
};

void solution() {

    int head, size, sublist_len;
    cin>>head>>size>>sublist_len;

    node list[100000];
    int address;
    for (int i = 0; i < size; i++) {
        cin>>address;
        list[address].address = address;
        cin>>list[address].data>>list[address].next;
    }

    int p = head;
    vector<int> vi, sk;
    while (p != -1) {
        sk.push_back(p);
        if (sk.size() == sublist_len) {
            for (int j = sublist_len - 1; j >= 0; j--)
                vi.push_back(sk[j]);
            sk.clear();
        }
        p = list[p].next;
    }

    cout.fill('0');
    if (vi.size() != 0) {
        cout<<setw(5)<<list[vi[0]].address<<" "<<list[vi[0]].data<<" ";
        for (int i = 1; i < vi.size(); i++) {
            cout<<setw(5)<<list[vi[i]].address<<endl;
            cout<<setw(5)<<list[vi[i]].address<<" "<<list[vi[i]].data<<" ";
        }
        for (int i = 0; i < sk.size(); i++) {
            cout<<setw(5)<<list[sk[i]].address<<endl;
            cout<<setw(5)<<list[sk[i]].address<<" "<<list[sk[i]].data<<" ";
        }
        cout<<-1<<endl;
        return;

    }
}

int main() {
    solution();
    return 0;
}