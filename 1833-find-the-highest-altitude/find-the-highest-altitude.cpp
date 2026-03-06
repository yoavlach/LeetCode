class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int max = 0, currGain = 0;
        int gainSize = gain.size();
        for(int i = 0; i < gainSize; i++)
        {
            currGain += gain[i];
            if (currGain > max)
                max = currGain;
        }
        return max;
    }
};
