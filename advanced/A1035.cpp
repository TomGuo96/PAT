#include <iostream>
#include <queue>

using namespace std;

// 修改密码
bool modifiedPass(string &pass){
    bool ret = false;
    for(int i = 0; i < pass.length(); i++){
        if(pass[i] == '1'){
            pass[i] = '@';
            ret = true;
        } else if(pass[i] == 'l'){
            pass[i] = 'L';
            ret = true;
        } else if(pass[i] == '0'){
            pass[i] = '%';
            ret = true;
        } else if(pass[i] == 'O'){
            pass[i] = 'o';
            ret = true;
        }
    }
    return ret;
}

void solution(){

    int size;
    cin>>size;

    // count1计数总用户数，count2计数修改密码用户数
    int count1 = 0, count2 = 0;
    queue<string> q;
    for(int i = 0; i < size; i++){

        string UID, Pass;
        cin>>UID>>Pass;

        // 若修改了密码，则入队q等待输出
        if(modifiedPass(Pass)){
            q.push(UID);
            q.push(Pass);
            count2++;
        }
        count1++;

    }

    // 具体输出
    if(count1 == 1 && count2 == 0){
        cout<<"There is 1 account and no account is modified"<<endl;
    } else if(count2 == 0){
        cout<<"There are "<<count1<<" accounts and no account is modified"<<endl;
    } else {
        cout<<count2<<endl;
        while(!q.empty()){
            cout<<q.front();
            q.pop();
            cout<<" "<<q.front()<<endl;
            q.pop();
        }
    }

}

int main() {
    /**
     * 测试用例：
     * 3 Team000002 Rlsp0dfa Team000003 perfectpwd Team000001 R1spOdfa
     * 期待结果：
     * 2 Team000002 RLsp%dfa Team000001 R@spodfa
     */
    solution();
    return 0;
}