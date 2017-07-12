#include <stdio.h>
#include <stdint.h>

uint32_t multiplixer(uint32_t a, uint32_t b)
{
    if (b == 0)
    {
        return 0;
    }
    else
    {
        return ((multiplixer(a, b>>1) << 1) + ((b & 0x1)? a: 0));
    } 
}

void main()
{
    printf("33 x 44 = %d\n", multiplixer(33, 44));
}
