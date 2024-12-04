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
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(str1[i]==str2[j])
        //         {
        //             str1[i]=' ';
        //             str2[j]=' ';
        //             break;
        //         }
        //     }
        // }
        // string str3="";
        // for(char c:str2)
        // {
        //     if(c!=' ')
        //     {
        //         if(c=='a')
        //         {
        //             str3+='z';
        //         }
        //         else
        //         {
        //             str3+=char(c-1);
        //         }
        //     }
        // }
        // cout<<str3;
        // int k = str3.length();
        // if(k==0)
        // {
        //     return true;
        // }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<k;j++)
        //     {
        //         if(str1[i]==str3[j])
        //         {
        //             str1[i]=' ';
        //             str3[j]=' ';
        //             break;
        //         }
        //     }
        // }
        // cout<<" "<<str3;
        // int c=0;
        // for(char ch:str3)
        // {
        //     if(ch!=' ')
        //     {
        //         c++;
        //     }
        // }
        // if(c==0)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
    }
};