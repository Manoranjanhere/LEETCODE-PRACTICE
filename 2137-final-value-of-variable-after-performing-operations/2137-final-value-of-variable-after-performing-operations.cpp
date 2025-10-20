class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int k =0;
        for(string i:operations)
        {
            if(i[0]=='+'||i[2]=='+')k++;
            else k--;
        }
        return k;
    }
};