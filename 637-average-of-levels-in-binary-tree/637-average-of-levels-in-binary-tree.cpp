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
    int height(TreeNode * root) {
        if(root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    
    vector<double> printLevelOrder(TreeNode* root) {
        int h = height(root), i;
        vector<double> res;
        
        for(i = 1; i <= h; i++)
        {
            double sum = 0, node = 0;
            
            printCurrentLevel(root, i, sum, node);
            
            res.push_back(sum/node);
        }
        
        return res;
    }

    void printCurrentLevel(TreeNode* root, int level, double& sum , double& node) {
        if(root == NULL)
            return;
        
        if(level == 1)
        {
            sum += root->val;
            node += 1;
        }
        else if(level > 1) 
        {
            printCurrentLevel(root->left, level - 1, sum, node);
            printCurrentLevel(root->right, level - 1, sum, node);
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        return printLevelOrder(root);
    }
};