/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if(root)
            res = getRes({ root });
        return res;
    }
private:
    vector<vector<int>> getRes(vector<TreeNode*> levelNodes)
    {
        vector<TreeNode*> nextLevelNodes;
        vector<int> intLevelNodes;
        vector<vector<int>> res;
        vector<vector<int>> received;
        for (TreeNode* levelNode : levelNodes)
            intLevelNodes.push_back(levelNode->val);
        res.push_back(intLevelNodes);
        for (TreeNode* treeNode : levelNodes)
        {
            if (treeNode->left)
                nextLevelNodes.push_back(treeNode->left);
            if (treeNode->right)
                nextLevelNodes.push_back(treeNode->right);
        }
        if (nextLevelNodes.size() > 0)
        {
            received = getRes(nextLevelNodes);
            res.insert(res.end(), received.begin(), received.end());
        }
        return res;
    }
};
