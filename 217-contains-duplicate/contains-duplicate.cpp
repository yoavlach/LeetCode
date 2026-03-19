class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> saw;
        for(int i : nums)
        {
            if(saw.contains(i))
                return true;
            saw.insert(i);
        }
        return false;
    }
};