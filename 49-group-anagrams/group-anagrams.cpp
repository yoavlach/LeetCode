class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> anagrams;
        map<char, int> curr;
        map<map<char, int>, vector<string>> letterCounterAndAnagrams;
        for (string i : strs)
        {
            curr.clear();
            for (char j : i)
            {
                if (curr.find(j) != curr.end())
                    curr.find(j)->second++;
                else
                    curr[j] = 1;
            }
            if (letterCounterAndAnagrams.find(curr) != letterCounterAndAnagrams.end())
                letterCounterAndAnagrams.find(curr)->second.push_back(i);
            else
                letterCounterAndAnagrams[curr] = { i };
        }
        for (auto i : letterCounterAndAnagrams)
            anagrams.push_back(i.second);
        return anagrams;
    }

};