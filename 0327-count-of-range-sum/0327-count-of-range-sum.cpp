
class Solution {
public:
    int solve(vector<int>& nums,int s,int e,int lower,int upper ){
        if(s==e){
            return nums[s]>=lower && nums[e]<=upper;
        }
        int m = s + (e-s)/2;
        int left = solve(nums,s,m,lower,upper);
        int right = solve(nums,m+1,e,lower,upper);
        int mer=0;
        vector<long long>sl(m-s+1);
        vector<long long>pr(e-m);
        sl[m-s]=(long long)nums[m];
        for(int i=m-1;i>=s;i--){
            sl[i-s]= sl[i-s+1] + (long long)nums[i];
        }        
        pr[0]=(long long)nums[m+1];
        for(int i=m+2;i<=e;i++){
         pr[i-(m+2-1)] = pr[i-1-(m+2-1)] + (long long)nums[i];
        }
        sort(sl.begin(),sl.end());
        sort(pr.begin(),pr.end());
        for(int i=0;i<sl.size();i++){
            // pr >=lower-s[i]
            // pr <=U-S[I]
            long long u1 = (long long)lower-(long long)sl[i];
            long long u2 = (long long)upper-(long long)sl[i];
            auto a = lower_bound(pr.begin(),pr.end(),u1);
            auto b = upper_bound(pr.begin(),pr.end(),u2);
            int l1 = pr.end()-a;
            int l2 = pr.end()-b;
            mer+=abs(l1-l2);
        }
   return left+right+mer;

    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        return solve(nums,0,nums.size()-1,lower,upper);
    }
};