#include <stdio.h>
#include <stdint.h>


uint64_t gcd64(uint64_t u, uint64_t v) {
    if (!u || !v) return u | v;
    int shift;
    for (shift = 0; !((u | v) & 1); shift++) {
        u /= 2, v /= 2;
    }
    while (!(u & 1))
        u /= 2;
    do {
        while (!(v & 1))
            v /= 2;
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift
;
}

int main(int argc, char const *argv[])
{
	printf("gcd: %lu\n", gcd64(72 ,96));//24

	printf("gcd: %lu\n", gcd64(287, 105)); //7

	printf("gcd: %lu\n", gcd64(1320,121)); //11

	return 0;
}

