#include "isPalindrome.h"

int isPalindrome(const char * str){
    return isPalindrome_internal(str, str + strlen(str) - 1);
}

int isPalindrome_internal(const char * head, const char * tail){
    if(tail - head <= 0){
        return 1;
    }
    else{
        if(*head != *tail){
            return 0;
        }
        else{
            return isPalindrome_internal(++head, --tail);
        }
    }
}
