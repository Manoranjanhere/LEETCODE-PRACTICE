class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if(n==0)return;
        int len = nums1.length;
        int end = len-1;
        while(n>0&&m>0)
        {
            if(nums1[m-1]>=nums2[n-1])
            {
                nums1[end]=nums1[m-1];
                m--;
            }
            else
            {
                nums1[end]=nums2[n-1];
                n--;
            }
            end--;
        }
        while(n>0)
        {
            nums1[end]=nums2[n-1];
            n--;
            end--;
        }
    }
}