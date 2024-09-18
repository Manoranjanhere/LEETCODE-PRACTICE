class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> st1;
        unordered_map<string,int> st2;
        vector<string> ans;
        string store="";
        for(auto i:s1)
        {
            if(i!=' ')
            {
                store+=i;
            }
            else
            {
                st1[store]++;
                store="";
            }
        }
        st1[store]++;
        store="";
        for(auto i:s2)
        {
            if(i!=' ')
            {
                store+=i;
            }
            else
            {
                st2[store]++;
                store="";
            }
        }
        st2[store]++;
        for(auto i:st1)
        {
            if(st2.find(i.first)==st2.end()&&st1[i.first]==1)
            {
                ans.push_back(i.first);
            }
        }
        for(auto i:st2)
        {
            if(st1.find(i.first)==st1.end()&&st2[i.first]==1)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};