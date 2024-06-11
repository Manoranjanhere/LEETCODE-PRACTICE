
import java.util.HashSet;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();

        HashSet<Character> set = new HashSet<>();
        int left = 0, right = 0, max = 0;

        while (right < n) {
            if (!set.contains(s.charAt(right))) {
                set.add(s.charAt(right));
                right++;
                max = Math.max(max, right - left);
            } else {
                set.remove(s.charAt(left));
                left++;
            }
        }

        return max;
    }
}