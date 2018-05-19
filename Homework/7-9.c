/******************************************************************************
Description：
  输出输入字符串的数字、字母及其他字符个数
******************************************************************************/

#include <stdio.h>
#include <ctype.h>

void count(char * str, int * counter);

int main(int argc, char const *argv[]) {
    int counter[3] = {0};   //0 -> digit, 1 -> letter, 2 -> else
    char str[100];
    gets(str);
    count(str, counter);
    printf("#digit = %d, #letter = %d, #else = %d\n", counter[0], counter[1], counter[2]);

    return 0;
}

void count(char * str, int * counter){
    while(*str++){
        if(isdigit(*str)){
            counter[0]++;
        }
        else if(isalpha(*str)){
            counter[1]++;
        }
        else{
            counter[2]++;
        }
    }
}
