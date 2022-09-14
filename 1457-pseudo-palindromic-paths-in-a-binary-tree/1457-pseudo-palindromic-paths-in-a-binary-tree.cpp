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
    void preorder(TreeNode* root,int& count,vector<int> &dig) {
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            dig[root->val]++;
            int oddcount = 0;
            
            for(int i = 1; i <= 9; i++)
            {
                if(dig[i] % 2)
                    oddcount++;
            }
            
            if(oddcount < 2) 
                count++;
            
            dig[root->val]--;
            
            return;
        }
        
        dig[root->val]++;
        
        preorder(root->left, count, dig);
        preorder(root->right, count, dig);
        
        dig[root->val]--;
    }
    
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int>ans;
        vector<int>dig(10, 0);
        
        int count = 0;
        
        preorder(root, count, dig);
        
        return count;
    }
};