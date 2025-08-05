bool isPalindrome(int x) {
    int tmp = x, i = 0;
    unsigned int reverse = 0;
    if(x < 0)
    {
        return false;
    }
    for(i = 0; tmp; i++)
    {
        reverse = reverse * 10 + (tmp % 10);
        tmp /= 10;
    }
    return reverse == x;
}