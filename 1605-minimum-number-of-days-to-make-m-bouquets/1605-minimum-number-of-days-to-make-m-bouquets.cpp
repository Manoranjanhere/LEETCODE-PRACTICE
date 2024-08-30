#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) {  // We have enough flowers for a bouquet
                    bouquets++;
                    flowers = 0;  // Reset for the next bouquet
                }
            } else {
                flowers = 0;  // Reset flowers count if bloom day exceeds current day
            }
            if (bouquets >= m) return true;  // We've made enough bouquets
        }
        return false;  // Not enough bouquets could be made
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // Use long long to prevent overflow
        if (static_cast<long long>(m) * k > n) return -1;  // Not enough flowers to make the required bouquets

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;

        // Binary search to find the minimum day
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                result = mid;  // Mid is a potential answer
                high = mid - 1;  // Try to find a smaller valid day
            } else {
                low = mid + 1;  // Increase the days to make bouquets
            }
        }

        return result;
    }
};
