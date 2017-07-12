#include <stdio.h>

void main()
{
    void *p;
    unsigned int i = 0x3;

    p = &i;

    printf("Before: *p as %x\n", *(unsigned int*)p);

    *(unsigned int*)p = *((unsigned int*)p) & ~1;
//    *p = (*p)) & ~1;

    printf("After:  *p as %x\n", *(unsigned int*)p);
}
