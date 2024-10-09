class Solution {
public:
    int minAddToMakeValid(string s) {
        int a=0,b=0;
        for(char ch:s)
        {
            if(ch=='(')
            {
                a++;
            }
            else if(a>0&&ch==')')
            {
                a--;
            }
            else
            {
                b++;
            }
        }
        return a+b;
    }
};