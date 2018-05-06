/*
*use Recursive algorithm to output a string in reversal order
*/

#include <stdio.h>
#include <string.h>

void rPuts(char * strH, char * strT);       //Head and Tail

int main(int argc, char const *argv[]) {
    char str[50];
    gets(str);
    rPuts(str, str + strlen(str) - 1);

    return 0;
}

void rPuts(char * strH, char * strT){
    if(strH == strT){
        putchar(*strH);
    }
    else{
        putchar(*strT);
        rPuts(strH, strT - 1);
    }
}
