class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string ans ="";
        for(int i=0;i<n;i++)
        {
            int a=1;
            while(i<n&&word[i]==word[i+1])
            {
                a++;
                i++;
            }
            while(a>9)
            {
                ans+=to_string(9);
                ans+=word[i];
                a-=9;
            }
            ans+=to_string(a);
            ans+=word[i];

        }
        return ans;
    }
};