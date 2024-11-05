class Solution {
public:
    bool validPalindrome(string s) {
        int l=0;
        int  r=s.length()-1;
        int c=0;
        while(l<=r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else 
            {
                return lastchance(s,l+1,r)||lastchance(s,l,r-1);
            }
            
        }
        return true;
    }
    bool lastchance(string s,int l, int r)
    {
        while(l<r)
        {
            if(s[l]==s[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};