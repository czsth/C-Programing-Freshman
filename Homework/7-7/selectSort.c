#include "selectSort.h"
#define SELECTSORT_H

void selectSort(void * cntner, size_t size, size_t len, int (*tgt)(const void *, const void *)){
    unsigned int i, j;   //loop var
    void * tmp = malloc(size);
    void * max;
    for(i = 0; i < len - 1; i++){
        max = cntner;
        for(j = 0; j < len - i; j++){
            if(tgt(cntner + j * size, max)){
                max = cntner + j * size;
            }
        }
        memcpy(tmp, cntner + (len - i - 1) * size, size);
        memcpy(cntner + (len - i - 1) * size, max, size);
        memcpy(max, tmp, size);
    }
    free(tmp);
}
