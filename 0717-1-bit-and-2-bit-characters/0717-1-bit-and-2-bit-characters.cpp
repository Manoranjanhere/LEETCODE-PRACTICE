class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if(n==1)return true;
        n-=2;
        int k=0;
        while(n>=0&&bits[n]==1)
        {
            k++;
            n--;
        }
        return (k%2==0)?true:false;
        
    }
};