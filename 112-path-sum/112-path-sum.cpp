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
    bool helper(TreeNode *node, int req){
        if(!node) 
            return false;
        
        int x = req - node->val;
        
        if(node->left == NULL && node->right == NULL)
            return (x == 0);
    
        return helper(node->left, x) || helper(node->right, x);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root, targetSum);
    }
};