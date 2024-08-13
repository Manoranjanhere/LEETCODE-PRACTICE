class Solution {
public:
    int countPoints(string rings) {
        map<int, set<char>> mp;
        
        for(int i = 0; i < rings.length(); i += 2) {
            char color = rings[i];
            int rod = rings[i + 1] - '0';
            mp[rod].insert(color);
        }
        
        int count = 0;
        for(auto& rod : mp) {
            if(rod.second.size() == 3) // Checking if the rod has all three colors
                count++;
        }
        
        return count;
    }
};
