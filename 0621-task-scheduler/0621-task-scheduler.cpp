class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s = tasks.size();
        unordered_map<char,int> mp;
        for(char i:tasks) {
            mp[i]++;
        }
        
        vector<int> st;
        for(auto i:mp) {
            st.push_back(i.second);
        }
        sort(st.rbegin(),st.rend());
        
        int lar = st[0]; // max frequency
        int c = 0;
        
        // count how many tasks have frequency == lar
        for(int i=0; i<st.size(); i++) {
            if(st[i] == lar) c++;
            else break;
        }
        
        // apply formula using your variables
        int ans = max(s, (lar - 1) * (n + 1) + c);
        return ans;
    }
};
