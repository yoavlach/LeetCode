int maxArea(int* height, int heightSize) {
    int i = 0, j = heightSize - 1, min = 0, largestArea = 0, currArea = 0;
    while(i != j)
    {
        if(height[i] > height[j])
        {
            min = height[j];
            currArea = min * (j - i);
            j--;
        }
        else
        {
            min = height[i];
            currArea = min * (j - i);
            i++;
        }
        if(currArea > largestArea) largestArea = currArea;
    }
    return largestArea;
}