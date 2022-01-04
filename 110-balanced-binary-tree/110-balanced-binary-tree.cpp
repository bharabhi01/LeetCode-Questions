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
private:
    int Depth(TreeNode* node) {
        if(node == NULL)
            return 0;
        
        int lh = Depth(node->left);
        if(lh == -1)
            return -1;
        
        int rh = Depth(node->right);
        if(rh == -1)
            return -1;
        
        if(abs(lh - rh) > 1)
            return -1;
        
        return max(lh, rh) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return Depth(root) != -1;
    }
};