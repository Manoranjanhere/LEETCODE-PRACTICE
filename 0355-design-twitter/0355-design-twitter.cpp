class Twitter {
public:
    unordered_map<int,unordered_set<int>>follows;
    unordered_map<int,vector<pair<int,int>>>post;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>>all;
        for(auto t:post[userId])all.push_back(t);
        for(int f:follows[userId])
        {
            for(auto t:post[f])all.push_back(t);
        }
        sort(all.begin(),all.end(),[](auto &a,auto&b)
        {
            return a.first>b.first;
        });
        vector<int> ans;
        for(int i=0;i<all.size()&&i<10;i++)
        {
            ans.push_back(all[i].second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */