class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int len = tasks.size();
		vector<int>freq(26);
        
		for(int i = 0; i < len; i++)
			freq[tasks[i] - 'A']++;
        
		sort(freq.begin(),freq.end());
        
		int maxFreq = freq[25] - 1;
		int idle = maxFreq * n;
        
		for(int i = 24; i >= 0; i--)
			 idle -= min(maxFreq, freq[i]);
        
		return idle < 0 ? len : len + idle;
	}
};