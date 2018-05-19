/* bubblt sort with pointor */
#include <stdio.h>

void bubbleSort(int *, int);
void swap(int *, int *);

int main(int argc, char const *argv[]) {
    int arr[10] = {12, 33, 52, 12, 53, 74, 24, 63, 97, 12};
    int i;   //loop var
    // for(i = 0; i < 10; i++){
    //     scanf("%d", arr + i);
    // }
    bubbleSort(arr, 10);
    for(i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}

void bubbleSort(int *arr, int len){
    int i, j;
    for(i = 0; i < len - 1; i++){
        for(j = 0; j < len - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
