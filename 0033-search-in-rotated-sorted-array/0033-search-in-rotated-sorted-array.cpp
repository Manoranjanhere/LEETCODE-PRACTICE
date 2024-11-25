class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int l=0;
        int h=n-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(arr[mid]==target)
            {
                return mid;
            }
            if(arr[l]<=arr[mid])
            {
                if(target >= arr[l] && target < arr[mid])
                {
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(target > arr[mid] && target <= arr[h])
                {
                    l=mid+1;
                }
                else
                {
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};