/******************************************************************************
Description：
  判断字符串是否回文（函数定义在isPalindrome.h中）
******************************************************************************/

#include <stdio.h>
#include "isPalindrome.h"

int main(int argc, char const *argv[]) {
    int rsl = isPalindrome("abcdcba");	//rsl refers to "result"
    printf("%d\n", rsl);
    return 0;
}
