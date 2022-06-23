class Solution {
public:
    static bool comparator(vector<int> &a, vector<int> &b)
    {
        return (a[1] < b[1]);
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comparator);
        
        int n = courses.size();
        
        priority_queue<int>pq;
        int sum = 0;
        
        for(auto it: courses)
        {
            int dur = it[0];
            int deadline = it[1];
            
            if(sum + dur <= deadline)
            {
                sum += dur;
                pq.push(dur);
            }
            else if(pq.size() && pq.top() > dur)
            {
                sum += dur - pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        
        return pq.size();
    }
};