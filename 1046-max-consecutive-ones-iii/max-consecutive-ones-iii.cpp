class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int start = 0, end = 0, remaining = 0, maxOnes = 0, difference = 0;
        bool enteredLoop = false;
        if (nums.size() == 1)
            maxOnes = k > 0 ? 1 : 0;
        else
        {
            for (int i = 0; i < nums.size(); i++)
            {
                difference = 0;
                start = i;
                for (end = i; end < nums.size() - 1 && nums[end] == 1; end++)
                    enteredLoop = true;
                i = end;
                if (nums[end] == 0 && enteredLoop)
                    end--;
                remaining = k;
                enteredLoop = false;
                while (end < nums.size())
                {
                    if (nums[end] == 1 || (nums[end] == 0 && remaining >= 1))
                    {
                        enteredLoop = true;
                        if (nums[end] == 0 && remaining >= 1)
                            remaining--;
                        end++;
                    }
                    else
                        break;
                }
                if (enteredLoop)
                {
                    end--;
                    difference++;
                }
                enteredLoop = false;
                while (remaining > 0 && start >= 0)
                {
                    if (nums[start] == 1 || (nums[start] == 0 && remaining >= 1))
                    {
                        enteredLoop = true;
                        if (nums[start] == 0 && remaining >= 1)
                            remaining--;
                        start--;
                    }
                }
                if (enteredLoop)
                    start++;
                difference += end - start;
                if (difference > maxOnes)
                    maxOnes = difference;
            }
        }
        return maxOnes;
    }
}; 
