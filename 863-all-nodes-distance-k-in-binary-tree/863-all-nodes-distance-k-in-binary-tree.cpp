/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 1) Find Parents (using Level Order). 2) Use BFS to traverse in all direction till K. 3) Output
class Solution {
public:
    void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* target) {
        queue<TreeNode*>queue;
        queue.push(root);
        
        while(!queue.empty())
        {
            TreeNode* current = queue.front();
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
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        getParents(root, parent, target);
        
        queue<TreeNode*>queue;
        queue.push(target);
        
        unordered_map<TreeNode*, bool>visited;
        visited[target] = true;
        
        int currLevel = 0;
        
        while(!queue.empty()) 
        {
            int n = queue.size();
            
            if(currLevel++ == k)
                break;
            
            for(int i = 0; i < n; i++)
            {
                TreeNode* current = queue.front();
                queue.pop();
                
                if(current->left && !visited[current->left])
                {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                
                if(current->right && !visited[current->right])
                {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                
                if(parent[current] && !visited[parent[current]])
                {
                    queue.push(parent[current]);
                    visited[parent[current]] = true;
                }
            }
        }
        
        vector<int>ans;
        
        while(!queue.empty())
        {
            TreeNode* current = queue.front();
            queue.pop();
            ans.push_back(current->val);
        }
        
        return ans;
    }
};