class Solution {
public:
unordered_set<string>numset;
int n;
    string generate(string curr)
    {
        if(curr.size()==n)
        {
            if(numset.find(curr)==numset.end())
            {
                return curr;
            }
            return "";
        }
        string addzero=generate(curr+"0");
        if(addzero.size()>0)
        {
            return addzero;
        }
        return generate(curr+"1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        for(string s:nums)
        {
            numset.insert(s);
        }
        return generate("");
    }
};