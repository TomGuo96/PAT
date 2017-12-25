//
// Created by Tom Guo on 17/10/2017.
//

#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

node* create(int arr[]){
    node *p, *pre, *head;
    head = new node();
    head->next = NULL;
    pre = head;
    for(int i = 0; i < 5; i++){
        p = new node();
        p->data = arr[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int main(){
    int arr[5] = {4, 3, 6, 1, 2};
    node* L = create(arr);
    L = L->next;
    while(L != NULL){
        cout<<L->data;
        L = L->next;
    }
    return 0;
}