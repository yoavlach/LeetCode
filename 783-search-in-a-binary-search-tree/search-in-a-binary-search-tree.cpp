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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        TreeNode* valNode = nullptr;
        if (root->left || root->right)
        {
            if (val > root->val)
            {
                if (root->right)
                    valNode = searchBST(root->right, val);
            }
            else if (val < root->val)
            {
                if (root->left)
                    valNode = searchBST(root->left, val);
            }
            else
            {
                valNode = root;
            }
        }
        else if (val == root->val)
            valNode = root;
        return valNode;
    }
};
