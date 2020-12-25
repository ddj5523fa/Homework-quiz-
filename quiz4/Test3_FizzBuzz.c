#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#define MSG_LEN 8
static inline bool is_divisible(uint32_t n, uint64_t M) {
    return n * M <= M - 1;
}

static uint64_t M3 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 3 + 1;

static uint64_t M5 = UINT64_C(0xFFFFFFFFFFFFFFFF) / 5 + 1;

void branch(size_t i)
{
    char buf[10];
    if (i % 3 == 0) sprintf(buf, "Fizz");
    if (i % 5 == 0) sprintf(buf, "Buzz");
    if (i % 15 == 0) sprintf(buf, "FizzBuzz");
    if ((i % 3) && (i % 5)) sprintf(buf, "%lu", i);
}

void bitwise(size_t i)
{
    char buf[10];
    uint8_t div3 = is_divisible(i, M3);
    uint8_t div5 = is_divisible(i, M5);
    // 如果是3或5的倍數，要輸出的長度皆為4，如果是15的倍數，要輸出長度為8
    unsigned int length = (2 << div3) << div5;
    char fmt[MSG_LEN + 1];
    strncpy(fmt, &"FizzBuzz%u"[(MSG_LEN >> div5) >> (div3 << 2)], length);
    fmt[length] = '\0';
    sprintf(buf, fmt, i);
}

int main(int argc, char *argv[])
{
    const int TestSize=99999999;
    printf("bitwise_Test:\n");

    double t1=(double)clock() / CLOCKS_PER_SEC;
    for(int i=0;i<TestSize;i++)
        bitwise(i);
    double time1=(double)clock() / CLOCKS_PER_SEC-t1;

    printf("%f (Sec)\n",time1);
    printf("branch_Test:\n");

    double t2=(double)clock() / CLOCKS_PER_SEC;
    for(int i=0;i<TestSize;i++)
        branch(i);
    double time2=(double)clock() / CLOCKS_PER_SEC-t2;

    printf("%f (Sec)\n",time2);

    return 0;
}
