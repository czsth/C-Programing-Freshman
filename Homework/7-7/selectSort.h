#ifndef STRING_H
    #include <string.h>
    #define STRING_H
#endif

#ifndef STDLIB_H
    #include <stdlib.h>
    #define STDLIB_H
#endif

/*
* Func Name:    selectSort
* Description:  use select sort to sort a container
* Parameter:    ctner: first address of container
*               size: size of element in container
*               len: length of container(number of elements in container)
*               tgt: test-greater-than: return + int when first Parameter greater than the second
                    Note: the "greater-then" here is the concept of "partial order" in Discrete Mathematics
*/
void selectSort(void * cntner, size_t size, size_t len, int (*tgt)(const void *, const void *));


