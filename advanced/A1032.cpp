#include <iostream>
#include <iomanip>

using namespace std;

struct node {
    int next;
    char data;
    bool show;
    node() {
        show = false;
        next = -1;
    }
};

void solution(){

    int head1, head2, size;
    cin>>head1>>head2>>size;

    node arr[100001];
    for(int i = 0; i < size; i++){
        int address;
        cin>>address;
        cin>>arr[address].data>>arr[address].next;
    }

    // 遍历第一条链表，为出现的节点做标记
    int p = head1;
    while (p != -1){
        arr[p].show = true;
        p = arr[p].next;
    }

    // 遍历第二条链表，查找第一个标记为true的节点
    p = head2;
    while (p != -1){
        if(arr[p].show){
            cout.fill('0');
            cout<<setw(5)<<p<<endl;
            return;
        }
        p = arr[p].next;
    }
    cout<<-1<<endl;

}

int main() {
    /**
     * 测试用例：
     * 11111 22222 9 67890 i 00002 00010 a 12345 00003 g -1 12345 D 67890 00002 n 00003 22222 B 23456 11111 L 00001 23456 e 67890 00001 o 00010
     * 期待结果：
     * 67890
     *
     * 测试用例：
     * 00001 00002 4 00001 a 10001 10001 s -1 00002 a 10002 10002 t -1
     * 期待结果：
     * -1
     */
    solution();
    return 0;
}