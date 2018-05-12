/*
*   描述:给一个整形数组，元素个数 n，给一个整数k，满足 0<=k<=n
*       将后 n-k 个整数与前 k 个位置交换.不允许使用其他数组.
*   思想简述:将数组看成连续环路(头尾相接),将环向后转 k 次即可
*/

#include <stdio.h>
#include <string.h>

void exchange(int * const arr, const int n, const int k);
void myintcpy(int * dest, const int * src, const int len);

int main(int argc, char const *argv[]) {
    int arr[] = {12, 23, 24, 1, 3, 4, 12, 42, 2};
    exchange(arr, sizeof(arr) / sizeof(int), 4);

    int i;  //loop var
    for(i = 0; i < sizeof(arr) / sizeof(int); i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    return 0;
}


void exchange(int * const arr, const int n, const int k){
    int tmp = 0;
    int i;  //loop var
    for(i = 0; i < n - k; i++){
        tmp = arr[n - 1];
        myintcpy(arr + 1, arr, n - 1);
        arr[0] = tmp;
    }
}

void myintcpy(int * dest, const int * src, const int len){
    int i;  //loop var
    for(i = len - 1; i >= 0; i--){
        dest[i] = src[i];
    }
}
