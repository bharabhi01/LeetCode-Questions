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
    struct S {
        bool isBST;
        int minVal, maxVal, sum;
    };
    
    S helper(TreeNode* root, int &res) {
        if(!root)
            return {true, INT_MAX, INT_MIN, 0};
        
        S left = helper(root->left, res);
        S right = helper(root->right, res);
        
        if(left.isBST && right.isBST && left.maxVal < root->val && right.minVal > root->val)
        {
            int sum = left.sum + right.sum + root->val;
            res = max(res, sum);
            
            return {true, min(left.minVal, root->val), max(right.maxVal, root->val), sum};
        }
        else
            return {false, 0, 0, 0};
    }
    
    int maxSumBST(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};