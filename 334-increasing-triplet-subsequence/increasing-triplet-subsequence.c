#include <math.h>
bool increasingTriplet(int* nums, int numsSize) {
    int i = 0, smallest = pow(2, 31) - 1, second_smallest = pow(2, 31) - 1;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] <= smallest)
        {
            smallest = nums[i];
        }
        else if(nums[i] <= second_smallest)
        {
            second_smallest = nums[i];
        }
        else
        {
            return true;
        }
    }
    return false;
}