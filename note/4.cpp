//
// Created by Tom Guo on 06/10/2017.
//

#include <cstdio>
#include <cstring>

int main(){

//    char str[5][5];
//    // ^_^
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++){
//            str[i][j] = getchar();
//        }
//        getchar();
//    }
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++){
//            putchar(str[i][j]);
//        }
//        putchar('\n');
//    }

//    // I don't like you. QAQ T_T I like you.
//    char str1[20], str2[5][20];
//    gets(str1);
//    for(int i = 0; i < 3; i++)
//        gets(str2[i]);
//    puts(str1);
//    for(int i = 0; i < 3; i++)
//        puts(str2[i]);

//    // 书上说要为字符数组最后添加\0（ASCII码值为0，表示NULL），否则会输出乱码，实际上没有看到该现象
//    char str3[15];
//    for(int i = 0; i < 3; i++)
//        str3[i] = getchar();
//    puts(str3);
//    printf("%d%d\n", (int)str3[3], (int)str3[4]);

    // strcmp() 按字典序比较
    printf("%d\n", strcmp("abc", "abd"));

    // strcpy(str1, str2) 把str2的值赋给str1，包含结束符

    // strcat(str1, str2) 把str2接到str1上去


    return 0;
}