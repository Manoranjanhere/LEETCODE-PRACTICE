
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int heat = heaters.size();
        int house = houses.size();
        vector<int> arr(house);  
        
        sort(heaters.begin(), heaters.end());  

        for (int i = 0; i < house; i++) {
            int l = 0;
            int r = heat - 1;
            int c = INT_MAX;

            while (l <= r) { 
                int mid = (l + r) / 2;
                if (heaters[mid] < houses[i]) {
                    c = min(abs(heaters[mid] - houses[i]), c);
                    l = mid + 1;
                } else if (heaters[mid] > houses[i]) {
                    c = min(abs(heaters[mid] - houses[i]), c);
                    r = mid - 1;
                } else {
                    c = 0;
                    break;
                }
            }
            
            if (l < heat) {
                c = min(c, abs(heaters[l] - houses[i]));
            }
            if (r >= 0) {
                c = min(c, abs(heaters[r] - houses[i]));
            }

            arr[i] = c;
        }

        int maxDist = 0;
        for (int i = 0; i < house; i++) {
            if (arr[i] > maxDist) {
                maxDist = arr[i];
            }
        }
        
        return maxDist;
    }
};
