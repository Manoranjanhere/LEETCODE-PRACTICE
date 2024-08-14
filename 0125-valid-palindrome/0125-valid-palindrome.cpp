class Solution {
public:
    bool isPalindrome(string s) {
        string res ="";
        for(char c:s)
        {
            if(isalnum(c))
            {
                res+=tolower(c);
            }
        }
        cout<<res;
        int i=0;
        int j = res.length()-1;
        while(i<j)
        {
            if(res[i]!=res[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};