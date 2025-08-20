bool isSubsequence(char* s, char* t) {
    int i = 0, currChIndex = 0;
    char currCh = s[currChIndex];
    for(i = 0; t[i] && s[currChIndex]; i++)
    {
        if(t[i] == currCh)
        {
            currChIndex++;
            currCh = s[currChIndex];
        }
    }    
    return currChIndex >= strlen(s);
}