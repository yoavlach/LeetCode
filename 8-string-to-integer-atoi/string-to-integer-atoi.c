#define MAX_INT 2147483647
#define MIN_INT (-2147483648)
int myAtoi(char* s) {
    int sLen = strlen(s);
    long long int num = 0;
    bool startedNum = false, isPositive = true, sawSign = false;
    for(int i = 0; i < sLen; i++)
    {
        if(s[i] != ' ')
        {
            if(s[i] == '+' || s[i] == '-')
            {
                if(startedNum || sawSign)
                {
                    break;
                }
                if(s[i] != '+')
                {
                    isPositive = false;
                }
                sawSign = true;
            }
            else if(s[i] > '9' || s[i] < '0')
            {
                break;
            }
            else
            {
                startedNum = true;
            }
            if(startedNum)
            {
                num = num * 10LL + s[i] - '0';
                if((!isPositive && num * (-1) <= MIN_INT))
                {
                    num = MIN_INT;
                    break;
                }
                else if(num >= MAX_INT)
                {
                    num = MAX_INT;
                    break;
                }
            }
        }
        else if(startedNum || sawSign)
        {
            break;
        }
    }
    if(!isPositive)
    {
        num *= (-1);
    }
    return (int)num;
}