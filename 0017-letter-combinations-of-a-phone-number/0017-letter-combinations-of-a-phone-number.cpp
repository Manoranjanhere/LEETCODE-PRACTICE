class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string> ans;
        if(digits.size()==0)return ans;
        ans.push_back({""});
        for(char i:digits)
        {
            vector<string> temp;
            for(auto ch1:ans)
            {
                for(char ch2:mp[i])
                {   
                    temp.push_back(ch1+ch2);
                }
            }
            ans.swap(temp);
        }
        return ans;
    }
};