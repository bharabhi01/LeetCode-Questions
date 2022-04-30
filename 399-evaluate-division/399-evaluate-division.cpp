class Solution {
public:
    double check(string up, string down, unordered_map<string,unordered_map<string, double>> &mpp, unordered_set<string> &str)
    {
        if(mpp[up].find(down) != mpp[up].end()) 
            return mpp[up][down];   
    
        for (auto i : mpp[up])
        {
            if(str.find(i.first) == str.end())
            {
                str.insert(i.first);
                double tmp = check(i.first, down, mpp, str);
                if(tmp) 
                    return i.second * tmp;
            }
        }
        
        return 0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>>mpp;
        vector<double>res;
        
        for(int i = 0; i < values.size(); i++)
        {
            mpp[equations[i][0]].insert(make_pair(equations[i][1], values[i]));
            mpp[equations[i][1]].insert(make_pair(equations[i][0], 1 / values[i]));
        }
        
        for(auto i: queries)
        {
            unordered_set<string>str;
            double tmp = check(i[0], i[1], mpp, str);
            
            if(tmp)
                res.push_back(tmp);
            else
                res.push_back(-1);
        }
        
        return res;
    }
};