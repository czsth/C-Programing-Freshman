/*
*define a macro "swap(x, y)" to swap x and y
*/

#include <stdio.h>
#define swap(x, y) ((x)^=(y)^=(x)^=(y))

int main(int argc, char const *argv[]) {
    int a = 123, b = 456;
    printf("a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
