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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<TreeNode*> r1Leaves;
        vector<TreeNode*> r2Leaves;
        bool similar = true;
        getLeaves(root1, r1Leaves);
        getLeaves(root2, r2Leaves);
        if (r1Leaves.size() != r2Leaves.size())
            similar = false;
        for (int i = 0; i < r1Leaves.size() && similar; i++)
            similar = r1Leaves[i]->val == r2Leaves[i]->val;
        return similar;
    }
private:
    void getLeaves(TreeNode* root, vector<TreeNode*>& buffer)
    {
        vector<TreeNode*> r;
        vector<TreeNode*> l;
        if (root)
        {
            if (!root->left && !root->right)
                buffer.push_back(root);
            else
            {
                if (root->left)
                {
                    getLeaves(root->left, l);
                    buffer.insert(buffer.end(), l.begin(), l.end());
                }
                if (root->right)
                {
                    getLeaves(root->right, r);
                    buffer.insert(buffer.end(), r.begin(), r.end());
                }
            }
        }
    }
};
