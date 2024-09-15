class Solution {
public:
    int findTheLongestSubstring(string s) {
       int n = s.length();
       int mask=0, maxl=0;
       map<char,int>mp;
       mp[0]=-1;
       for(int i=0;i<n;i++)
       {
        if(s[i]=='a') mask^=(1<<0);
        else if(s[i]=='e') mask^=(1<<1);
        else if(s[i]=='i') mask^=(1<<2);
        else if(s[i]=='o') mask^=(1<<3);
        else if(s[i]=='u') mask^=(1<<4); 
       
       if(mp.find(mask)!=mp.end())
       {
        maxl = max(maxl,i-mp[mask]);
       }
       else
       {
        mp[mask]=i;
       }
           }
    return maxl;
    }
};