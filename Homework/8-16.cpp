/* 需要使用可变长的字符串，所以使用了C++的string类 */

#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    if(argc > 1){
        std::string str = argv[0];
        for(int i = 1; i < argc; i++){
            str += argv[i];     // string类的运算符重载
        }
        std::cout << str << std::endl;  // string类的运算符重载
    }
    return 0;
}
