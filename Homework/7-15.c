/******************************************************************************
Description：
    十六进制字符串转化为十进制整数
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int convert(char * hex_str, size_t len);
int isHexNum(char ch);
int hextoInt(char ch);

int main(int argc, char const *argv[]) {
    char * my_hex_str = "0x1ab3d8";
    int result = convert(my_hex_str, sizeof(my_hex_str));
    printf("%d\n", result);

    return 0;
}

int convert(char * hex_str, size_t len){
    int i = 0;  //loop var
    int result = 0;
    if(hex_str[1] == 'X' || hex_str[1] == 'x'){		//is started with "0x" or "0X", offset loop var
    	i = 2;
	}
    for(; i < len; i++){
        if(!isHexNum(hex_str[i])){
            result = -1;
            break;
        }
        else{
            result = result * 16 + hextoInt(hex_str[i]);
        }
    }
    return result;
}


int isHexNum(char ch){
    return isdigit(ch) || (isalpha(ch) && ((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F')));
}

int hextoInt(char ch){
    int rtn;
    if(isdigit(ch)){
        rtn = ch - '0';
    }
    else if(isupper(ch)){
        rtn = ch - 'A' + 10;
    }
    else if(islower(ch)){
        rtn = ch - 'a' + 10;
    }
    return rtn;
}
