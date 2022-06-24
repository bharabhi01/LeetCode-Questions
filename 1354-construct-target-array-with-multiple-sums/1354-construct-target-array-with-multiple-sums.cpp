class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        long long sum = 0;
        
        for(int x : target)
        {    
            sum += x;
            pq.push(x);
        }
        
        while(pq.top() != 1)
        {
            int y = pq.top();
            pq.pop();
            
            sum -= y;
            
            if(y <= sum || sum < 1)
                return false;
            
            y %= sum;
            sum += y;
            
            pq.push(y ? y: sum);
        }
        return true; 
    }
};