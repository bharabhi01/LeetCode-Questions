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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ;
        
        
        int n = queries.size();
        
        for(int i = 0; i < n; i++)
        {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }
        
        sort(oQ.begin(), oQ.end());
        
        vector<int>ans(n, 0);
        int ind = 0;
        int m = nums.size();
        
        Trie trie;
        
        for(int i = 0; i < n; i++)
        {
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int qind = oQ[i].second.second;
            
            while(ind < m && nums[ind] <= ai) 
            {
                trie.insert(nums[ind]);
                ind++;
            }
            
            if(ind == 0) ans[qind] = -1;
            else ans[qind] = trie.findMax(xi);            
            
        }
        
        return ans;
    }
};