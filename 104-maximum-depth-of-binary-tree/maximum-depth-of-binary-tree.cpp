class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        int rDepth = 1, lDepth = 1;
        if (root)
        {
            if (root->right)
            {
                rDepth = 1 + maxDepth(root->right);
            }
            if (root->left)
            {
                lDepth = 1 + maxDepth(root->left);
            }
        }
        else
        {
            rDepth = 0;
            lDepth = 0;
        }
        return rDepth > lDepth ? rDepth : lDepth;
    }
};
