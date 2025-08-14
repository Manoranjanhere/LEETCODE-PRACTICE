class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int ans = -1;
        for(int i=0;i<n-2;i++)
        {
            if(num[i]==num[i+1]&&num[i]==num[i+2])
            {
                ans=max(ans,num[i]-'0');
            }
        }
        if(ans==-1)return "";
        return string(3,ans+'0');
    }
};