#include <stdio.h>
#include <stdlib.h>

int singleNumber(int nums[], int numsSize, int times)
{
    int res = 0;
    for (int i = 0; i < 32; ++i)
    {
        int sum = 0;
        for (int j = 0; j < numsSize; ++j)
        {
            sum += (nums[j] >> i) & 1;
        }
        res |= (sum % times) << i;
    }
    return res;
}

void main()
{
    int nums5[] = {2,2,2,2,2,4,5,5,5,5,5};
    int nums4[] = {4,4,4,3,3,3,5,4,3};
    int nums3[] = {3,3,3,15};
    printf("%d\n", singleNumber(nums5, 11, 5));
    printf("%d\n", singleNumber(nums4, 9, 4));
    printf("%d\n", singleNumber(nums3, 4, 3));

}
