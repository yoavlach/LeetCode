class Solution {
public:
    int compress(vector<char>& chars)
    {
        string formattedSubStr = "";
        char currLetter = ' ';
        int rangeStart = 0, currLetterCounter = 0;
        bool needToUpdateCurrLetter = true;
        for (int i = 0; i < chars.size(); i++)
        {
            if (i == 0)
            {
                currLetter = chars[i];
                currLetterCounter = 1;
            }
            else if (currLetter == chars[i])
                currLetterCounter++;
            if(currLetter != chars[i] || i == chars.size() - 1)
            {
                needToUpdateCurrLetter = true;
                formattedSubStr = currLetter + (currLetterCounter == 1 ? "" : to_string(currLetterCounter));
                chars.erase(chars.begin() + rangeStart, chars.begin() + rangeStart + currLetterCounter);
                for (int j = 0; j < formattedSubStr.length(); j++)
                    chars.insert(chars.begin() + j + rangeStart, formattedSubStr[j]);
                i += formattedSubStr.length() - currLetterCounter;
                currLetter = chars[i];
                currLetterCounter = 1;
                rangeStart = i;
            }
        }
        return chars.size();
    }
};
