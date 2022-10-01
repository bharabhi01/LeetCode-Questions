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
    TreeNode* getParents(TreeNode* root, map<TreeNode*, TreeNode*> &parent, int start) {
        queue<TreeNode*>queue;
        queue.push(root);
        
        TreeNode* res;
        
        while(!queue.empty())
        {
            TreeNode* current = queue.front();
            
            if(current->val == start)
                res = current;
            
            queue.pop();
            
            if(current->left)
            {
                parent[current->left] = current;
                queue.push(current->left);
            }
            
            if(current->right)
            {
                parent[current->right] = current;
                queue.push(current->right);
            }
        }
        
        return res;
    }

    int findMaxDistance(map<TreeNode*,TreeNode*> &mpp, TreeNode* target) {
        queue<TreeNode*> q; 
        q.push(target); 
        
        map<TreeNode*, int> vis; 
        vis[target] = 1;
        
        int maxi = 0; 
        
        while(!q.empty()) 
        {
            int size = q.size();
            int flag = 0; 
            
            for(int i = 0; i < size; i++) 
            {
                auto current = q.front();
                q.pop();
                
                if(current->left && !vis[current->left]) 
                {
                    flag = 1; 
                    vis[current->left] = 1; 
                    q.push(current->left); 
                }
                
                if(current->right && !vis[current->right]) 
                {
                    flag = 1; 
                    vis[current->right] = 1; 
                    q.push(current->right); 
                }

                if(mpp[current] && !vis[mpp[current]]) 
                {
                    flag = 1; 
                    vis[mpp[current]] = 1; 
                    q.push(mpp[current]); 
                } 
            }
            
            if(flag) 
                maxi++; 
        }
        
        return maxi; 
    }
    
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*>mpp;
        TreeNode* target = getParents(root, mpp, start);
        
        int maxi = findMaxDistance(mpp, target);
        
        return maxi;
    }
};