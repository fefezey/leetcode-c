#include <stdint.h>

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    int i;

    for (i = 0; i < 32; i++)
    {
        result = result << 1;
        result = result | (n & 1);
        n = n >> 1;
    }

    return result;
}