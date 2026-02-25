class Solution 
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        map<vector<int>, vector<int>> rowCount;
        vector<vector<int>> currVerticalAndHorizontalRow(2);
        int sameRowCount = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            currVerticalAndHorizontalRow[0] = {};
            currVerticalAndHorizontalRow[1] = {};
            for (int j = 0; j < grid[i].size(); j++)
            {
                currVerticalAndHorizontalRow[0].push_back(grid[i][j]);
                currVerticalAndHorizontalRow[1].push_back(grid[j][i]);
            }
            for (int k = 0; k < currVerticalAndHorizontalRow.size(); k++)
            {
                auto curr = rowCount.find(currVerticalAndHorizontalRow[k]);
                if (curr != rowCount.end())
                {
                    curr->second[k]++;
                }
                else
                {
                    vector<int> rowAndColCount = { 0, 0 };
                    rowAndColCount[k]++;
                    rowCount[currVerticalAndHorizontalRow[k]]= rowAndColCount;
                }
            }
        }
        for (auto i : rowCount)
        {
            sameRowCount += i.second[0] * i.second[1];
        }
        return sameRowCount;
    }
};
