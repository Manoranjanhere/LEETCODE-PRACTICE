class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> one;
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1')
            {
                one.push_back(i);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j:one)
            {
                count+=abs(j-i);
            }
            ans.push_back(count);
        }
        return ans;
    }
};