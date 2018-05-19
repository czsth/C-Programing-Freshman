/* reverse the order of element in an array, without using another */
#include <stdio.h>

void reverse(int *, int);
void reverse_internal(int *, int *);

int main(int argc, char const *argv[]) {
    int arr[10] = {12, 33, 52, 12, 53, 74, 24, 63, 97, 12};
    int i;
    printf("Original:\t");
    for(i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
    reverse(arr, 10);
    printf("Reversed:\t");
    for(i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void reverse(int *arr, int len){
    reverse_internal(arr, arr + len - 1);
}

void reverse_internal(int *head, int *tail){
    if(head >= tail){
        return;
    }
    int tmp;
    tmp = *tail;
    *tail = *head;
    *head = tmp;
    reverse_internal(head + 1, tail - 1);
}
