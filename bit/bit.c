#include <stdint.h>
#include <stdio.h>

uint32_t func(uint32_t x)
{
    uint32_t n = x;
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = ((n & 0xff00ff00) >>  8) | ((n & 0x00ff00ff) <<  8);
    n = ((n & 0xf0f0f0f0) >>  4) | ((n & 0x0f0f0f0f) <<  4);
    n = ((n & 0xcccccccc) >>  2) | ((n & 0x33333333) <<  2);
    n = ((n & 0xaaaaaaaa) >>  1) | ((n & 0x55555555) <<  1);
    return n;
}

uint32_t inverse32oldFasion(uint32_t x)
{
    uint32_t n = 0;

    for (int i = 0; i < 31 ; i++) {
        n |= x & 0x1;
        x >>= 1;
        n <<= 1;
    }

    return n;
}

uint16_t inverse16oldFasion(uint16_t x)
{
    uint16_t n = 0;

    for (int i = 0; i < 15 ; i++) {
        n |= x & 0x1;
        x >>= 1;
        n <<= 1;
    }

    return n;
}

uint32_t inverse32(uint32_t x)
{
    uint32_t n = x;
    uint32_t mask1[5] = {0xffff0000, 0xff00ff00, 0xf0f0f0f0, 0xcccccccc, 0xaaaaaaaa};
    uint32_t mask2[5] = {0x0000ffff, 0x00ff00ff, 0x0f0f0f0f, 0x33333333, 0x55555555};

    for(int i = 0; i < 5; i++) {
//       printf("inverse32: %08x +\n", n);
        n = ((n & mask1[i]) >> (16>>i)) | ((n & mask2[i]) << (16>>i));
//       printf("inverse32: %08x - \n", n);
    }

    return n;
}

uint16_t inverse16(uint16_t x)
{
    uint16_t n = x;
    uint16_t mask1[5] = {0xff00, 0xf0f0, 0xcccc, 0xaaaa};
    uint16_t mask2[5] = {0x00ff, 0x0f0f, 0x3333, 0x5555};

    for(int i = 0; i < 4; i++) {
//        printf("inverse16: %04x +\n", n);
        n = ((n & mask1[i]) >> (8>>i)) | ((n & mask2[i]) << (8>>i));
//        printf("inverse16: %04x - \n", n);
    }

    return n;
}

void main()
{
    printf("org:\n");
    printf("0x00000001 -> 0x%08x\n",func(0x00000001));
    printf("0x00000002 -> 0x%08x\n",func(0x00000002));
    printf("0x00000004 -> 0x%08x\n",func(0x00000004));
    printf("0x00000008 -> 0x%08x\n",func(0x00000008));
    printf("0x00000010 -> 0x%08x\n",func(0x00000010));
    printf("0x00000020 -> 0x%08x\n",func(0x00000020));
    printf("0x00000040 -> 0x%08x\n",func(0x00000040));
    printf("0x00000080 -> 0x%08x\n",func(0x00000080));
    printf("0x80000000 -> 0x%08x\n",func(0x80000000));
    printf("0x40000000 -> 0x%08x\n",func(0x40000000));
    printf("0x20000000 -> 0x%08x\n",func(0x20000000));
    printf("0x10000000 -> 0x%08x\n",func(0x10000000));
    printf("0x08000000 -> 0x%08x\n",func(0x08000000));
    printf("0x04000000 -> 0x%08x\n",func(0x04000000));
    printf("0x02000000 -> 0x%08x\n",func(0x02000000));
    printf("0x01000000 -> 0x%08x\n",func(0x01000000));

    printf("inverse32:\n");
    printf("0x00000001 -> 0x%08x\n",inverse32(0x00000001));
    printf("0x00000002 -> 0x%08x\n",inverse32(0x00000002));
    printf("0x00000004 -> 0x%08x\n",inverse32(0x00000004));
    printf("0x00000008 -> 0x%08x\n",inverse32(0x00000008));
    printf("0x00000010 -> 0x%08x\n",inverse32(0x00000010));
    printf("0x00000020 -> 0x%08x\n",inverse32(0x00000020));
    printf("0x00000040 -> 0x%08x\n",inverse32(0x00000040));
    printf("0x00000080 -> 0x%08x\n",inverse32(0x00000080));
    printf("0x80000000 -> 0x%08x\n",inverse32(0x80000000));
    printf("0x40000000 -> 0x%08x\n",inverse32(0x40000000));
    printf("0x20000000 -> 0x%08x\n",inverse32(0x20000000));
    printf("0x10000000 -> 0x%08x\n",inverse32(0x10000000));
    printf("0x08000000 -> 0x%08x\n",inverse32(0x08000000));
    printf("0x04000000 -> 0x%08x\n",inverse32(0x04000000));
    printf("0x02000000 -> 0x%08x\n",inverse32(0x02000000));
    printf("0x01000000 -> 0x%08x\n",inverse32(0x01000000));

    printf("inverse16:\n");
    printf("0x0001 -> 0x%04x\n",inverse16(0x0001));
    printf("0x0002 -> 0x%04x\n",inverse16(0x0001));
    printf("0x0004 -> 0x%04x\n",inverse16(0x0001));
    printf("0x0008 -> 0x%04x\n",inverse16(0x0001));
    printf("0x1000 -> 0x%04x\n",inverse16(0x1000));
    printf("0x2000 -> 0x%04x\n",inverse16(0x2000));
    printf("0x4000 -> 0x%04x\n",inverse16(0x4000));
    printf("0x8000 -> 0x%04x\n",inverse16(0x8000));

    printf("inverse32oldFasion:\n");
    printf("0x00000001 -> 0x%08x\n",inverse32oldFasion(0x00000001));

    printf("inverse16oldFasion:\n");
    printf("0x0001 -> 0x%04x\n",inverse16oldFasion(0x0001));
}
