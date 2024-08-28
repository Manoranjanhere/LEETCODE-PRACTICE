class Solution {
public:
    int findMin(vector<int>& arr) {
        int l=0,last=arr.size()-1;
        int r=last;
        if(arr[l]>arr[r])
        {
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(mid==last||mid==0)
                {
                    break;
                }
                if(arr[mid]<arr[mid-1]&&arr[mid]<arr[mid+1])
                {
                    return arr[mid];
                }
                else if(arr[mid]>arr[last])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        else
        {
            return arr[0];
        }
        return arr[r];
    }
};