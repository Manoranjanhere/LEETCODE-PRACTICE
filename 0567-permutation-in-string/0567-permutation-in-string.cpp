class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1>n2) return false;
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        for(char c:s1)
        {
            c1[c-'a']++;
        }
        for(int i=0;i<n1;i++)
        {
            c2[s2[i]-'a']++;
        }
        if(c1==c2) return true;
        for(int i=n1;i<n2;i++)
        {
            c2[s2[i]-'a']++;
            c2[s2[i-n1]-'a']--;
            if(c2==c1) return true;
        }
        return false;


    }
};