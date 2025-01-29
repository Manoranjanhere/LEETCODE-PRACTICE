class Solution {
public:
    vector<string> wordSubsets(vector<string>& mainWords, vector<string>& requiredWords) {
       int n1 = mainWords.size();
       int n2 = requiredWords.size();
       vector<string> ans;
        unordered_map<char,int> mp;
       for(string i:requiredWords)
       {
        unordered_map<char,int> mpc;
            for(char ch:i)
            {
                mpc[ch]++;
            }
            for(auto val:mpc)
            {
                char fis = val.first;
                mp[fis]=max(mp[fis],mpc[fis]);
            }

       }
        for(string i:mainWords)
        {
            unordered_map<char,int> submp;
            for(char ch:i)
            {
                submp[ch]++;
            }
            bool work =true;
            for(auto j:mp)
            {
                char k = j.first;
                if(submp[k]<mp[k])
                {
                    work =false;
                    break;
                }
            }
            if(work)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};