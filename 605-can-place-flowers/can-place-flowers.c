bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int placeFlowersCounter = 0, i = 0;
    for(i = 0; i < flowerbedSize && placeFlowersCounter < n; i++)
    {
        if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i + 1 == flowerbedSize || flowerbed[i + 1] == 0))
        {
            flowerbed[i] = 1;
            placeFlowersCounter++;
        }
    }
    return placeFlowersCounter >= n;
}