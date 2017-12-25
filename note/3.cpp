//
// Created by Tom Guo on 06/10/2017.
//

#include <cstdio>
#include <cstring>

int main(){

    int arr[5] = {1, 2, 3, 4, 5};

    /*
     * 建议初学者只用该函数赋0或-1为初值
     */

    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < 5; i++)
        printf("%4d ", arr[i]);
    printf("\n");

    memset(arr, -1, sizeof(arr));
    for(int i = 0; i < 5; i++)
        printf("%4d ", arr[i]);
    printf("\n");

    return 0;
}