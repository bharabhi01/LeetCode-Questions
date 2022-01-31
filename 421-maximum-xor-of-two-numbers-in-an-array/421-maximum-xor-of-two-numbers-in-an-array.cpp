struct Node {
    Node* links[2];
    
    bool containsKey(int index) {
        return (links[index] != NULL);
    }
    
    Node* get(int index) {
        return links[index];
    }
    
    void put(int index, Node* node) {
        links[index] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) 
    {
        Node* node = root; 
        for(int i = 31; i >= 0; i--) 
        {
            int bit = (num >> i) & 1; 
            if(!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }     
    }
               
    int findMax(int num) {
        Node* node = root;
        int maxNum = 0;
        
        for(int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            
            if(node->containsKey(!bit)) {
                maxNum = maxNum | (1 <<i);
                node = node->get(!bit);
            }
            else {
                node = node->get(bit);
            }
        }
        
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        
        for(auto &it: nums) trie.insert(it);
        
        int maxi = 0;
        
        for(auto &it: nums) maxi = max(maxi, trie.findMax(it));
        
        return maxi;
        
    }
};