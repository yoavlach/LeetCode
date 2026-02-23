class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> difference = { { }, { } };
        map<int, vector<bool>> numsAndAmountsOfArrs;
        for (auto i : nums1)
        {
            auto curr = numsAndAmountsOfArrs.find(i);
            if (curr != numsAndAmountsOfArrs.end())
            {
                curr->second[0] = true;
            }
            else
            {
                numsAndAmountsOfArrs[i] = { true, false };
            }
        }
        for (auto i : nums2)
        {
            auto curr = numsAndAmountsOfArrs.find(i);
            if (curr != numsAndAmountsOfArrs.end())
            {
                curr->second[1] = true;
            }
            else
            {
                numsAndAmountsOfArrs[i] = { false, true };
            }
        }
        for (auto i : numsAndAmountsOfArrs)
        {
            if (i.second[0] == false)
            {
                difference[1].push_back(i.first);
            }
            if (i.second[1] == false)
            {
                difference[0].push_back(i.first);
            }
        }
        return difference;
    }
};
