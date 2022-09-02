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
    vector<double> avg;
    vector<double>sum;
    vector<int>n;
    
    void rec(TreeNode* root, int level) {
        if(!root) 
            return;
        
        if(sum.size() > level)
        {
            sum[level] += root->val;
            n[level]++;
        }
        else
        {
            sum.push_back(root->val);
            n.push_back(1);
        }
        
        rec(root->left, level + 1);
        rec(root->right, level + 1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        rec(root, 0);
        
        for(int i = 0; i < sum.size(); i++)
            avg.push_back(sum[i] / (double)n[i]);

        return avg;
    }
};