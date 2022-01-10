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
class BSTiterator {
private:
    stack<TreeNode*> st;
    bool reverse = true;
    
    void pushNode(TreeNode* Node)
    {
        for(; Node != NULL; )
        {
            st.push(Node);
            if(reverse == true)
                Node = Node->right;
            else
                Node = Node->left;
        }
    }

public:
    BSTiterator(TreeNode* root, bool isReverse)
    {
        reverse = isReverse;
        pushNode(root);
    }
    
    bool hasNext()
    {
        return !st.empty();
    }
    
    int next()
    {
        TreeNode* temp = st.top();
        st.pop();
        
        if(!reverse)
            pushNode(temp->right);
        else
            pushNode(temp->left);
        
        return temp->val;
    }

};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        
        BSTiterator left(root, false);
        BSTiterator right(root,true);
        
        int i = left.next();
        int j = right.next();
        
        while(i < j) 
        {
            if(i + j == k)
                return true;
            else if(i + j < k)
                i = left.next();
            else
                j = right.next();
        }
        return false;
    }
};