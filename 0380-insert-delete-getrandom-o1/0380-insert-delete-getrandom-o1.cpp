class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
        {
            return false;
        }
        nums.push_back(val);
        mp[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;
        else
        {
            int ind = mp[val];
            mp[nums[nums.size()-1]]=ind;
            swap(nums[nums.size()-1],nums[ind]);
            nums.pop_back();
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        int r = rand()%nums.size();
        return nums[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */