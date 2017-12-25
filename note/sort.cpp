//
// Created by Tom Guo on 08/10/2017.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
    int value;
};

/* 排序算法 */

// 选择排序
template <class T>
void selectionSort(T*, int);
// 插入排序
template <class T>
void insertionSort(T*, int);

/* 比较函数 */

bool cmp(int, int);
bool cmpNode(Node, Node);
bool cmpString(string, string);

/* 输出函数 */

void output(int*, int);
void output(Node*, int);
void output(vector<int>);
void output(string*, int);

int main(){

    /* 选择排序 */

    int a[] = {2, 3, 4, 1, 6};
    selectionSort(a, 5);
    cout<<"选择排序后：";
    output(a, 5);

    /* 插入排序 */

    int b[] = {2, 3, 4, 1, 6};
    insertionSort(b, 5);
    cout<<"插入排序后：";
    output(a, 5);
    cout<<endl;

    /* sort函数 */

    // 不含cmp测试
    int arr[6] = {9, 4, 2, 5, 6, -1};
    sort(arr, arr + 4);
    cout<<"排序前四个后：";
    output(arr, 6);
    sort(arr, arr + 6);
    cout<<"排序前六个后：";
    output(arr, 6);
    cout<<endl;

    // 含cmp的int型测试
    sort(arr, arr + 6, cmp);
    cout<<"int数组排序后：";
    output(arr, 6);
    cout<<endl;

    // 含cmp的Node型测试
    Node arrNode[10];
    for(int i = 0; i < 10; i++)
        arrNode[i].value = 10 - i;
    cout<<"Node数组初始化后为：";
    output(arrNode, 10);
    sort(arrNode, arrNode + 10, cmpNode);
    cout<<"Node数组排序后：";
    output(arrNode, 10);
    cout<<endl;

    // vector的排序
    vector<int> vec;
    for(int i = 0; i < 10; i++)
        vec.push_back(i * 2);
    sort(vec.begin(), vec.end(), cmp);
    cout<<"排序后的vector为：";
    output(vec);
    cout<<endl;

    // string的排序
    string arrStr[3];
    arrStr[0] = "a";
    arrStr[1] = "abc";
    arrStr[2] = "xx";
    sort(arrStr, arrStr + 3, cmpString);
    cout<<"按长度排序后的字符串数组为：";
    output(arrStr, 3);

    return 0;
}

template <class T>
void selectionSort(T arr[], int size){

    for(int i = 0; i < size; i++){
        T k = i;
        for(int j = i; j < size; j++){
            if(arr[j] < arr[k])
                k = j;
        }
        swap(arr[k], arr[i]);
    }

}

template <class T>
void insertionSort(T arr[], int size){

    for(int i = 1; i < size; i++)
        for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--)
            swap(arr[j], arr[j - 1]);

}

void output(int arr[], int size){

    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}

void output(Node arr[], int size){

    for(int i = 0; i < size; i++)
        cout<<arr[i].value<<" ";
    cout<<endl;

}

void output(vector<int> vec){

    for(int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;

}

void output(string str[], int size){

    for(int i = 0; i < size; i++)
        cout<<str[i]<<" ";
    cout<<endl;

}

bool cmp(int a, int b){
    return a > b;
}

bool cmpNode(Node a, Node b){
    return a.value < b.value;
}

bool cmpString(string a , string b){
    return a.length() < b.length();
}
