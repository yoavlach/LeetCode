char * mergeAlternately(char * word1, char * word2){
    int i = 0, word1Len = strlen(word1), word2Len = strlen(word2), mergedLen = word1Len + word2Len + 1;
    char* merged = (char*)calloc(mergedLen, sizeof(char));
    if(!merged)
    {
        printf("Unsuccessful calloc!");
        return NULL;
    }
    for(i = 0; word1[i / 2] && word2[i / 2] ; i++)
    {
        if(i % 2 == 0)
        {
            merged[i] = word1[i / 2];
        }
        else
        {
            merged[i] = word2[i / 2];
        }
    }
    if(word1Len > word2Len)
    {
        for(; i < mergedLen; i++)
        {
            merged[i] = word1[i - word2Len];
        }
    }
    else if(word2Len > word1Len)
    {        
        for(; i < mergedLen; i++)
        {
            merged[i] = word2[i - word1Len];
        }
    }
    return merged;
}