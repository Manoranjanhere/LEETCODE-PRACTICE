class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ind =0;
        string common="";
        string test = strs[0];
        while(true)
        {
            for(int i=0;i<strs.size();i++)
            {
                if(strs[i].size()<=ind||strs[i][ind]!=test[ind])
                {
                    return common;
                }
            }
            common+=test[ind];
            ind++;
        }
        return common;
    }
};