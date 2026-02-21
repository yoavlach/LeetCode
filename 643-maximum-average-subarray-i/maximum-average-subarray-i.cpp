class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        double currAvg = 0, maxAvg = INT_MIN;
        int start = 0, end = k, sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        currAvg = double(sum) / k;
        if (currAvg > maxAvg)
        {
            maxAvg = currAvg;
        }
        for (; end < nums.size(); end++, start++)
        {
            sum -= nums[start];
            sum += nums[end];
            currAvg = double(sum) / k;
            if (currAvg > maxAvg)
            {
                maxAvg = currAvg;
            }
        }
        return maxAvg;
    }
};
