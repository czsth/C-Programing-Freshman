/*
* Another way to realize the function of 12-3-2
* A more explicit and neat way
*/

#include <stdio.h>

void reverse(char * str);

int main(int argc, char const *argv[]) {
    char str[50];
    gets(str);
    reverse(str);
    
    return 0;
}

void reverse(char * str){
    if(*(str + 1)){
        reverse(str + 1);
    }
    putchar(*str);
}
