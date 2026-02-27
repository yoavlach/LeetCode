class Solution {
public:
    string decodeString(string s) 
    {
        string currBracket = "", strK = "", toDecode = "", decoded = "";
        int bracketCounter = 0, k = 0, i = 0;
        bool sawBracket = false, hasMoreBrackets = false;
        for(i = 0; i < s.length(); i++)
        {
            if (sawBracket && bracketCounter == 0 || (i == s.length() - 1 && s[i] == ']'))
            {
                k = stoi(strK);
                if (hasMoreBrackets)
                    toDecode = decodeString(currBracket);
                else
                    toDecode = currBracket;
                for (int j = 0; j < k; j++)
                    decoded += toDecode;
                sawBracket = false;
                strK = "";
                currBracket = "";
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (!sawBracket)
                    strK += s[i];
                else
                    currBracket += s[i];
            }
            else if (s[i] == '[')
            {
                if (sawBracket)
                    currBracket += s[i];
                bracketCounter++;
                if (bracketCounter > 1)
                    hasMoreBrackets = true;
                sawBracket = true;
            }
            else if (s[i] == ']')
            {
                bracketCounter--;
                if (sawBracket && bracketCounter > 0)
                    currBracket += s[i];
            }
            else
            {
                if (sawBracket)
                    currBracket += s[i];
                else
                    decoded += s[i];
            }
        }
        return decoded;
    }
}; 
