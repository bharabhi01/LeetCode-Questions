class MyCalendarThree {
private:
    int maxi;
    map<int, int> m;
    
public:
    MyCalendarThree() {
        m.emplace(-1, 0);
        maxi = 0;
    }
    
    int book(int start, int end) {
        auto startIt = --m.upper_bound(start);
        startIt = m.emplace(start, startIt->second).first;
        
        auto endIt = --m.upper_bound(end);
        endIt = m.emplace(end, endIt->second).first;
        
        for (auto it = startIt; it != endIt; ++it) 
        {
            ++it->second;
            maxi = max(maxi, it->second);
        }
        
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */