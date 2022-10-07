class MyCalendarThree {
public:
    map<int, int>timeSum;
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        timeSum[start]++;
        timeSum[end]--;
        
        int result = 0, sum = 0;
        
        for(auto &[time, diff] : timeSum)
        {
            sum += diff;
            result = max(result, sum);
        }
        
        return result;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */