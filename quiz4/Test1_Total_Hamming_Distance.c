#include <stdio.h>


int totalHammingDistance(int* nums, int numsSize){
int res = 0, n = numsSize;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int num=0 ;num<numsSize;num++) {
                if ((nums[num]>>i) & (1)) ++cnt;
            }
            res += cnt * (n - cnt);
        }
        return res;
}
int main ()
{
    int nums[]={4,14,2};
    printf("%d\n",totalHammingDistance(nums, 3));
}
