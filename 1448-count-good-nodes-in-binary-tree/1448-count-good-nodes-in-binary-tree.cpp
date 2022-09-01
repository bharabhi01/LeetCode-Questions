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
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        return goodNodesRec(root, INT_MIN);
    }
    
    int goodNodesRec(TreeNode* root, int maxVal) {
        int res = 0;
        if(!root)
            return 0;
        
        if(root->val >= maxVal)
            res++;
        
        maxVal = max(maxVal, root->val);
        
        return res + goodNodesRec(root->left, maxVal) + goodNodesRec(root->right, maxVal);
    }
};