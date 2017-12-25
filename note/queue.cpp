//
// Created by Tom Guo on 10/10/2017.
//

#include <iostream>
#include <queue>

using namespace std;

struct fruit{
    string name;
    int price;
    fruit(string name, int price){
        this->name = name;
        this->price = price;
    }
    friend bool operator < (const fruit &f1, const fruit &f2){
        return f1.price > f2.price;
    }
};

void output(queue<int>);
void output(priority_queue<int>);
void output(priority_queue<int, vector<int>, greater<int>>);

int main(){

    /*********
     * 普通队列
     *********/

    queue<int> q;
    for(int i = 1; i <= 10; i++)
        q.push(i);
    cout<<"队列的队头元素为："<<q.front()<<"，队尾元素为："<<q.back()<<endl;

    /* pop() */

    q.pop();
    cout<<"队列出队一个元素后："<<"共有"<<q.size()<<"个元素，它们是";
    output(q);

    cout<<endl;

    /*********
     * 优先队列
     *********/

    // 不设置优先级
    priority_queue<int> pq;
    for(int i = 1; i <= 10; i++)
        pq.push(i);
    cout<<"初始化后的优先队列为(默认优先级）：";
    output(pq);

    // 设置优先级
    priority_queue<int, vector<int>, greater<int>> pq_bw;
    for(int i = 1; i <= 10; i++)
        pq_bw.push(i);
    cout<<"初始化后的优先队列为(设置优先级）：";
    output(pq_bw);

    // 结构体的优先级设置
    priority_queue<fruit> pq_fruit;
    fruit f1("桃子", 3);
    fruit f2("梨子", 4);
    fruit f3("苹果", 1);
    pq_fruit.push(f1);
    pq_fruit.push(f2);
    pq_fruit.push(f3);
    cout<<"结构体的优先队列的第一个元素为："<<pq_fruit.top().name<<"，优先级为："<<pq_fruit.top().price<<endl;

}

void output(queue<int> q){
    if(q.empty())
        return;
    else if(q.size() == 1){
        cout<<q.front()<<endl;
    }
    cout<<q.front();
    q.pop();
    while(!q.empty()){
        cout<<" "<<q.front();
        q.pop();
    }
    cout<<endl;
}

void output(priority_queue<int> pq){
    if(pq.empty())
        return;
    else if(pq.size() == 1){
        cout<<pq.top()<<endl;
    }
    cout<<pq.top();
    pq.pop();
    while(!pq.empty()){
        cout<<" "<<pq.top();
        pq.pop();
    }
    cout<<endl;
};

void output(priority_queue<int, vector<int>, greater<int>> pq){
    if(pq.empty())
        return;
    else if(pq.size() == 1){
        cout<<pq.top()<<endl;
    }
    cout<<pq.top();
    pq.pop();
    while(!pq.empty()){
        cout<<" "<<pq.top();
        pq.pop();
    }
    cout<<endl;
}