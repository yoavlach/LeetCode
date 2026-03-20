class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> anagrams;
        vector<int> letterCounter(26);
        map<vector<int>, vector<string>> letterCounterAndAnagrams;
        for (const string& i : strs)
        {
            fill(letterCounter.begin(), letterCounter.end(), 0);
            for (char j : i)
                letterCounter[j - 'a']++;
            auto curr = letterCounterAndAnagrams.find(letterCounter);
            if (curr != letterCounterAndAnagrams.end())
                curr->second.push_back(i);
            else
                letterCounterAndAnagrams[letterCounter] = { i };
        }
        for (auto i : letterCounterAndAnagrams)
            anagrams.push_back(i.second);
        return anagrams;
    }
};
