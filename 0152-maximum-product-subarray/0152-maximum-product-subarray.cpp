class Solution {
public:
    int maxProduct(vector<int>& nums) {


        double prefixProduct = 1;
        double suffixProduct = 1;

        int ans = INT_MIN;

        for(int i=0;i<nums.size();i++){
            
            if(prefixProduct==0) prefixProduct = 1;
            if(suffixProduct==0) suffixProduct = 1;

            prefixProduct *= (nums[i]);
            suffixProduct *= (nums[nums.size()-i-1]);

            double temp = prefixProduct;
            if(prefixProduct < suffixProduct) temp = suffixProduct;
            if(ans < temp) ans = temp;

        }

        return ans;
    }
};