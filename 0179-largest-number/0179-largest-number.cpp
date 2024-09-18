class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> array;
        for (int num : nums) {
            array.push_back(to_string(num));
        }

        sort(array.begin(),array.end(),[](const string& a,const string &b)
        {
            return (a+b)>(b+a);
        });

        if (array[0] == "0") {
            return "0";
        }

        string largest;
        for (auto num : array) {
            largest += num;
        }

        return largest;
    }
};