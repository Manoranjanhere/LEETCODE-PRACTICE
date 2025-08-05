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
            for(auto ch1:mp[i])
            {
                for(auto ch2:ans)
                {   
                    temp.push_back(ch2+ch1);
                }
            }
            ans.swap(temp);
        }
        return ans;
    }
};