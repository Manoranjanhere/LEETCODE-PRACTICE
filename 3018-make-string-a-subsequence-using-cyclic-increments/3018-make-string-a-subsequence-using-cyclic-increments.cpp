class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int left=0;
        for(int i=0;i<n;i++)
        {
            if(str1[i]==str2[left]||(str1[i]+1)==str2[left]||(str1[i]=='z'&&str2[left]=='a'))
            {
                left++;
                if(left==m)
                {
                    return true;
                }
            }
        }
        return false;
    }
};