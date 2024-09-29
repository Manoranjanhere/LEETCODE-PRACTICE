class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
        {
            return ans;
        }
        map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        ans.push_back("");
       for(char i:digits)
       {
            vector<string> temp;
            string a = mp[i-'0'];
            for(string j:ans)
            {
                for(char ch:a)
                {
                    temp.push_back(j+ch);
                }
            }
            ans.swap(temp);
       }
       return ans;
    }
};