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
class Solution {
public:
    int goodNodes(TreeNode* root)
    {
        bool inTreeRoot = seen.size() == 0;
        int goodNodesCounter = 0, prevPathMax = 0;
        if (inTreeRoot)
            currPathMax = root->val;
        prevPathMax = currPathMax;
        seen.insert(root);
        for (auto i : { root->left, root->right })
        {
            currPathMax = prevPathMax;
            if (inTreeRoot)
                currPathMax = root->val;
            if (i && seen.find(i) == seen.end())
            {
                if (i->val >= currPathMax)
                    currPathMax = i->val;
                goodNodesCounter += goodNodes(i);
            }
        }
        if (root->val >= prevPathMax || inTreeRoot)
            goodNodesCounter++;
        return goodNodesCounter;
    }
private:
    set<TreeNode*> seen;
    int currPathMax = 0;
};
