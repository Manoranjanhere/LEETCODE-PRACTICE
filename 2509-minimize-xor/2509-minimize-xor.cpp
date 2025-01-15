class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2); 
        int w=num1;
        int s1;
        int s2;
        while(true)
        {
            if(__builtin_popcount(w)==n)
            {
                s1=w;
                break;
            }
            w++;
        }
        w=num1-1;
        bool workdone=false;
        while(w>0)
        {
            if(__builtin_popcount(w)==n)
            {
                s2=w;
                workdone=true;
                break;
            }
            w--;
        }
        if(!workdone)
        {
            return s1;
        }
        else
        {
            int f = s1^num1;
            int s = s2^num1;
            if(f>s)
            {
                return s2;
            }
            else
            {
                return s1;
            }
        }

    }
};
