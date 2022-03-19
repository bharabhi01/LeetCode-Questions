class Stack{
 public:
    int val;
    int freq;
    int time;

    Stack(int _val,int _freq, int _time)
    {
        val = _val;
        freq = _freq;
        time = _time;
    }
};

class comp {
  public:
    bool operator()(Stack a,Stack b)
    {
        if(a.freq == b.freq)
            return a.time < b.time;
        else
            return a.freq < b.freq;
    }
};

class FreqStack {
public:
    int time = 1;
    priority_queue<Stack,vector<Stack>,comp> pq;
    unordered_map<int,int> mp;
    
    FreqStack() {
        
    }
    
    void push(int val) 
    {
        mp[val]++;
        pq.push(Stack(val, mp[val], time));
		time++;
    }
    
    int pop() {
        int ans = pq.top().val;
        mp[ans]--;
        pq.pop();
		
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */