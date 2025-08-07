/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int i = 0, largest = 0;
    *returnSize = candiesSize;
    bool* arr = (bool*)malloc(candiesSize * sizeof(bool));
    if(!arr)
    {
        printf("Unsuccessful malloc!");
        return NULL;
    }
    for(i = 0; i < candiesSize; i++)
    {
        if(candies[i] > largest)
        {
            largest = candies[i];
        }
    }
    for(i = 0; i < candiesSize; i++)
    {
        arr[i] = (candies[i] + extraCandies) >= largest;
    }
    return arr;
}