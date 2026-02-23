class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occurrences;
        set<int> counters;
        bool unique = true;
        for (auto i : arr)
        {
            auto curr = occurrences.find(i);
            if (curr != occurrences.end())
            {
                curr->second++;
            }
            else
            {
                occurrences[i] = 1;
            }
        }
        for (auto i : occurrences)
        {
            auto curr = counters.find(i.second);
            if (curr != counters.end())
            {
                unique = false;
            }
            else
            {
                counters.insert(i.second);
            }
        }
        return unique;
    }
}; 