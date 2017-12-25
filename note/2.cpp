//
// Created by Tom Guo on 06/10/2017.
//

#include <iostream>

using namespace std;

//冒泡排序
template <class T>
void bubbleSort(T arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1 ; j++){
            if(arr[j] > arr[j + 1]){
                T temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){

    int arr[] = {2, 3, 5, 1};
    bubbleSort<int>(arr, 4);
    for(int i = 0; i < 4; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
