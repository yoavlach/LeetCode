class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        bool found = false;
        int leftSum = 0, rightSum = 0, left = 0, right = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            rightSum += nums[i];
        }
        found = leftSum == rightSum;
        for (; right < nums.size() && !found; left++, right++)
        {
            rightSum -= nums[right];
            leftSum += nums[left];
            found = leftSum == rightSum;
        }
        return found ? left : -1;
    }
};