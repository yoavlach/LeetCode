class Solution 
{
public:
    string removeStars(string s)
    {
        for (int i = 0; i < s.length() - 1 && s.length() > 0; i++)
        {
            if (s[i + 1] == '*')
            {
                s.erase(i, 2);
                i -= 2;
                if (i < -1)
                {
                    i = -1;
                }
            }
        }
        return s;
    }
};
