class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int max = 0, currGain = 0;
        for (auto i : gain)
        {
            currGain += i;
            if (currGain > max)
                max = currGain;
        }
        return max;
    }
};
