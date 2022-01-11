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
    vector<int>traverse(TreeNode* root, int& ans)
    {
        if(!root)
            return {INT_MAX, INT_MIN, 0};
        
        vector<int>left(traverse(root->left, ans)), right(traverse(root->right, ans));
        
        if(left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0])
            return {};
        
        int curr = left[2] + right[2] + root->val;
        
        ans = max(ans, curr);
        
        return {min(left[0], root->val), max(right[1], root->val), curr};
    }
    
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return max(0, ans);
    }
};