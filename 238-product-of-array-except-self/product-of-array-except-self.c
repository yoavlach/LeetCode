/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i = 0, j = 0, product = 0, zerosCounter = 0;
    bool hasZero = false;
    int* answer = (int*)calloc(numsSize, sizeof(int));
    if(!answer)
    {
        printf("Unsuccessful calloc!");
        return NULL;
    }
    *returnSize = numsSize;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            if(product == 0)
            {
                product++;
            }
            product *= nums[i];
        }
        else
        {
            hasZero = true;
            zerosCounter++;
        }
    }
    if(zerosCounter > 1)
    {
        product = 0;
    }
    for(i = 0; i < numsSize; i++)
    {
        if(hasZero)
        {
            if(nums[i] != 0)
            {
                answer[i] = 0;
            }
            else
            {
                answer[i] = product;
            }
        }
        else
        {
            answer[i] = product / nums[i];
        }
    }
    return answer;
}