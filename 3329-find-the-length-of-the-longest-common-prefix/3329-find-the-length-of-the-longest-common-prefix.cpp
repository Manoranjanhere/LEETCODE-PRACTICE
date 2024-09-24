class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> prex;
        int c=0;
        for(int i=0;i<arr1.size();i++)
        {
            string store=to_string(arr1[i]);
            string pre="";
            for(char ch:store)
            {
                pre+=ch;
                prex[pre]++;
            }
        }
        for(int i=0;i<arr2.size();i++)
        {
            string store=to_string(arr2[i]);
            string pre="";
            for(char ch:store)
            {
                pre+=ch;
                if(prex[pre]!=0)
                {
                    int n = pre.length();
                    c=max(c,n);
                }
            }
        }
        return c;
    }
};