class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
vector<int> ans(n,0);
int prod=1;
int c=0;
int k=-1;
for(int i=0;i<n;i++)
{
	if(nums[i]==0)
	{
		c++;
		k=i;
	}
	else
	{
		prod*=nums[i];
	}
}
if(c>=2)return ans;
if(c==1){ans[k]=prod;
return ans;}
for(int i=0;i<n;i++)
{
ans[i]=prod/nums[i];
}
return ans;
    }
};