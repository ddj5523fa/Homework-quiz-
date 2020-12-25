#include <stdio.h>
#include <stdint.h>

int numberOfSteps (int num){
    int res=0,subtimes=0,divtimes=0;
    while(num>0)
    {
    int odd=num&1;
    int even=!(num&1);
    subtimes=subtimes+odd;
    divtimes=divtimes+even;
    num=(num-odd)>>even;
    };
    res=subtimes+divtimes;
    return res;
}

int main()
{
    printf("Test num=14 :\n\n");
    printf("output:%d\n",numberOfSteps (14));
    return 0;
}

