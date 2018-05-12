#include <stdio.h>
#include <string.h>

void * mystrncat(char * dest, const char * src, int len);

int main(int argc, char const *argv[]) {
    char str1[20] = "Hello ", str2[] = "World";
    mystrncat(str1, str2, sizeof(str2));
    puts(str1);

    return 0;
}

void * mystrncat(char * dest, const char * src, int len){
    dest += strlen(dest);
    memcpy(dest, src, strlen(src) + 1);
    return dest;
}
