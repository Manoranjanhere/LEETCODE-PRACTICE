class Solution {
public:
    int getLucky(string s, int k) {
        string a="";
        for(char ch:s)
        {
            int num=char(ch-'a'+1);
            a+=to_string(num);
        }
        while(k>0)
        {
            k--;
            int ans=0;
            for(char ch:a)
            {
                ans+=(ch-'0');
            }
            a=to_string(ans);
        }
        return stoi(a);
    }
};