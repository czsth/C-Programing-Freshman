/******************************************************************************
Description：
  实现strncpy()函数，字符串拷贝
******************************************************************************/

#include <stdio.h>
#include <string.h>

char * mystrncpy(char * dest, const char * src, int len);

int main(int argc, char const *argv[]) {
    char str1[] = "Hello world", str2[50];
    mystrncpy(str2, str1, sizeof(str1));
    puts(str2);

    return 0;
}

char * mystrncpy(char * dest, const char * src, int len){
    memcpy(dest, src, len);
    dest[len] = 0;
    return dest;
}
