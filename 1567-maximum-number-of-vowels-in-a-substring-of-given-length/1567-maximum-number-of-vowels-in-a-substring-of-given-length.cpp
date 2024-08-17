class Solution {
public:
    int maxVowels(string s, int k) {
        string a="";
        int c=0;
        int n = s.length();
        vector<string> check ={"a","e","i","o","u"};
        for(int i=0;i<k;i++)
        {
            if(find(check.begin(),check.end(),string(1,s[i]))!=check.end())
            {
                c++;
            }
            a+=s[i];
        }
        int maxx =c;
        int start=0;
        for(int i=k;i<n;i++)
        {
            if(find(check.begin(),check.end(),string(1,s[i]))!=check.end())
           {
            c++;
           }
                       if(find(check.begin(),check.end(),string(1,s[start]))!=check.end())
           {
            c--;
           }
           start++;
           maxx=max(c,maxx);

        }
        return maxx;
    }
};