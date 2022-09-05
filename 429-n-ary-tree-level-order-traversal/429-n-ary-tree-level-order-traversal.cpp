/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> ans;
        
        if(root == nullptr)
            return ans;
        q.push(root);
        
        while(!q.empty())
        {
            int si = q.size();
            vector<int> ds;
            
            for(int i = 0; i < si; i++)
            {
                Node* node = q.front();
                q.pop();
                
                ds.push_back(node->val);
                
                for(auto m : node->children)
                    q.push(m);
            }
            
            ans.push_back(ds);
        }
        
        return ans;
    }
};