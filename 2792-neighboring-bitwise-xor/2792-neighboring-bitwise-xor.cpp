class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x=0;
        for(auto i:derived)
        {
            x^=i;
        }
        return x==0;
    }
};