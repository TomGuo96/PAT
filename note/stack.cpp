//
// Created by Tom Guo on 10/10/2017.
//

#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> stk;
    for(int i = 1; i <= 10; i++)
        stk.push(i);
    for(int i = 1; i <= 3; i++)
        stk.pop();
    cout<<"该stack的顶部元素为："<<stk.top()<<endl;
    cout<<"该stack共有"<<stk.size()<<"个元素。"<<endl;
}