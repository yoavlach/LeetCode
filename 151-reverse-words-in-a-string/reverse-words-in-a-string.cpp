class Solution {
public:
    string reverseWords(string s)
    {
        string reversed = "", currWord = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' || i == s.length() - 1)
            {
                if (s[i] == ' ')
                {
                    for (; s[i] == ' '; i++);
                    i--;
                }
                if (i == s.length() - 1 && s[i] != ' ')
                {
                    currWord += s[i];
                }
                if (!currWord.empty())
                {
                    reversed = currWord + ' ' + reversed;
                    currWord = "";
                }
            }
            else
            {
                currWord += s[i];
            }
        }
        reversed.erase(reversed.length() - 1, 1);
        return reversed;
    }
};