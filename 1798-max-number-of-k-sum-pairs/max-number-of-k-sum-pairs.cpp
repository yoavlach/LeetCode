class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        map<int, vector<int>> numsAndIndexes;
        vector<int> curr;
        int counter = 0, currVal = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            auto currPair = numsAndIndexes.find(nums[i]);
            if (currPair == numsAndIndexes.end())
            {
                curr.push_back(i);
                numsAndIndexes[nums[i]] = curr;
                curr.erase(curr.begin());
            }
            else
            {
                currPair->second.push_back(i);
            }
        }
        for (auto it : numsAndIndexes)
        {
            currVal = it.first;
            if (numsAndIndexes.find(k - currVal) != numsAndIndexes.end())
            {
                if (currVal * 2 == k)
                {
                    counter += it.second.size() / 2;
                }
                else
                {
                    counter += it.second.size() > numsAndIndexes.find(k - currVal)->second.size() ? 
                        numsAndIndexes.find(k - currVal)->second.size() : it.second.size();
                    numsAndIndexes.erase(k - currVal);
                }
            }
        }
        return counter;
    }
};
