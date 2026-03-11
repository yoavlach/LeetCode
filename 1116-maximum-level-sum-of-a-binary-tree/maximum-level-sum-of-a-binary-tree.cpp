class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        return getMaxSum({ root }, 1)[1];
    }
private:
    vector<int> getMaxSum(vector<TreeNode*> levelNodes, int level)
    {
        int currSum = 0, maxSum = 0, maxLevel = level;
        vector<int> maxSumAndLevel;
        vector<TreeNode*> nextLevelNode;
        for (auto i : levelNodes)
        {
            currSum += i->val;
            if (i->right)
                nextLevelNode.push_back(i->right);
            if (i->left)
                nextLevelNode.push_back(i->left);
        }
        if (nextLevelNode.size() > 0)
        {
            maxSumAndLevel = getMaxSum(nextLevelNode, level + 1);
            maxSum = maxSumAndLevel[0];
            maxLevel = maxSumAndLevel[1];
        }
        if (currSum >= maxSum)
        {
            maxSum = currSum;
            maxLevel = level;
        }
        return { maxSum, maxLevel };
    }
};
