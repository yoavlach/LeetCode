class Solution {
public:
    int maxVowels(string s, int k)
    {
        int start = 0, end = k;
        int currVowels = 0, maxVowels = 0;
        set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
        for (int i = 0; i < k; i++)
            if (vowels.find(s[i]) != vowels.end()) currVowels++;
        maxVowels = currVowels;
        for (; end < s.length(); start++, end++)
        {
            if (vowels.find(s[start]) != vowels.end()) currVowels--;
            if (vowels.find(s[end]) != vowels.end()) currVowels++;
            if (currVowels > maxVowels) maxVowels = currVowels;
        }
        return maxVowels;
    }
};
