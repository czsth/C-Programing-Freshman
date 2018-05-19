/******************************************************************************
Description：
  使用选择排序对给定数组排序（使用了通用的排序算法）
******************************************************************************/

#include <stdio.h>
#define STDIO_H

#include "selectSort.h"
#define SELECTSORT_H

int tgt(const void * a, const void * b);

int main(int argc, char const *argv[]) {
    int arr[] = {1, 34, 65, 4, -32, 49, 32};
    selectSort(arr, sizeof(int), sizeof(arr) / sizeof(int), tgt);

    int i;
    for(i = 0; i < sizeof(arr) / sizeof(int); i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}

int tgt(const void * a, const void * b){
    if( *((int *)a) > *((int *)b) ){
        return 1;
    }
    return 0;
}

/*
*   The following comments are encoded in UTF-8
*   写个小结
*   关于头文件的 防止多次包含 的机制：应该是只需要在头文件里使用，源文件只要包含之后记得 define 就可以
*   关于内存的位置：内存地址是按 byte（字节）计算的，不要与 bit 弄混
*   关于 C 与 C++：C++ (似乎)不允许对 void * 直接进行算数操作（而是要求先指定类型），在 C++ 中应该使用泛型编程制造通用函数
*/
