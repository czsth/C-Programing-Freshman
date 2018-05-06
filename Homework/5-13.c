/*
*write a function "int digit(int a, int b)"
*if b <= the number of digit of a,
*return the number of a's on digit b(count from left)
*if b > the number of digit of a,
*return -1.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int digit(char * num, unsigned int b);
int check(char * num);      //check if any illeagal char inside

int main(int argc, char const *argv[]) {
    char num[50];
    do{
        printf("input an integer:");
        gets(num);
    }while(check(num));     //if returned an error, keep inputing

    unsigned int b;
    printf("input digit:");
    scanf("%d", &b);

    printf("%d\n",digit(num, b));

    return 0;
}

int digit(char * num, unsigned int b){
    if(b > strlen(num)){
        return -1;
    }
    else{
        return num[b - 1] - '0';
    }
}

int check(char * num){
    int i;
    for(i = 0; num[i]; i++){
        if(!isdigit(num[i])){       //if is not digit, return an error
            return 1;
        }
    }
    return 0;
}
