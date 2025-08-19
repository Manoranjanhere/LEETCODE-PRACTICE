class FreqStack {
public:
    	unordered_map<int,int> mp;
	unordered_map<int,stack<int>> store;
	int maxfreq=0;
        FreqStack() {
        
    }
    
    void push(int val) {
		mp[val]++;
		if(mp[val]>maxfreq)
		{
			maxfreq=mp[val];
		}
		store[mp[val]].push(val);
	    }
    
    int pop() {
		int curr=store[maxfreq].top();
		store[maxfreq].pop();
		mp[curr]--;
		if(store[maxfreq].empty())
		{
			maxfreq--;
		}
		return curr;
            }
};
