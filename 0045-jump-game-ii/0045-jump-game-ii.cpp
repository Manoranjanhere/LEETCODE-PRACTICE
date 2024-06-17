class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int jumps = 0;     // number of jumps to reach the end
        int farthest = 0;  // farthest point that can be reached
        int current_end = 0; // end of the range that can be reached with the current number of jumps

        for (int i = 0; i < n - 1; ++i) {
            // update the farthest point that can be reached
            farthest = max(farthest, i + nums[i]);

            // if we've reached the end of the range for the current jump, update the jump count
            if (i == current_end) {
                jumps++;
                current_end = farthest;

                // if the farthest point is the end or beyond, break early
                if (current_end >= n - 1) break;
            }
        }

        return jumps;
    }
};
