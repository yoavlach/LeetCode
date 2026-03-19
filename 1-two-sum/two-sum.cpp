class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numAndIndex;
        for(int i = 0; i < nums.size(); i++)
        {
            auto curr = numAndIndex.find(target - nums[i]);
            if(curr != numAndIndex.end())
                return { curr->second, i };
            numAndIndex[nums[i]] = i;
        }
        return {};
    }
};