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
    TreeNode* buildTree(vector<int> &nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int middle = (start + end)/2;
        
        TreeNode* root = new TreeNode(nums[middle]);
        
        root->left = buildTree(nums, start, middle - 1);
        root->right = buildTree(nums, middle + 1, end);
  
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return buildTree(nums, 0, n-1);
    }
};