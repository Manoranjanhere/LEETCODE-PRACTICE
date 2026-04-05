class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(char ch:moves)
        {
            if(ch=='U'){i-=1;}
            if(ch=='D'){i+=1;}
            if(ch=='L'){j-=1;}
            if(ch=='R'){j+=1;}
        }
        if(i==0&&j==0)return true;
        return false;
    }
};