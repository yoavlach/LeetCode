class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> appearanceCounter;
        vector<int> res(k);
        vector<set<int>> appearAsIndex(nums.size() + 1);
        int insertCounter = 0;
        for(int i : nums)
        {
            auto curr = appearanceCounter.find(i);
            if(curr == appearanceCounter.end())
            {
                appearanceCounter[i] = 1;
                appearAsIndex[1].insert(i);
            }
            else
            {
                appearAsIndex[curr->second].erase(i);
                curr->second++;
                appearAsIndex[curr->second].insert(i);
            }
        }
        for(int i = appearAsIndex.size() - 1; i >= 0 && insertCounter < k; i--)
        {
            for(int j : appearAsIndex[i])
            {
                res[insertCounter] = j;
                if(++insertCounter == k)
                    break;
            }
        }
        return res;
    }
};