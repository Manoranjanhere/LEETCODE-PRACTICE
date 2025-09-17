class FoodRatings {
public:
	struct cmp{
		bool operator()(const pair<int,string>&a,const pair<int,string>&b)const
	{
		if(a.first==b.first)
		{
			return a.second<b.second;
		}
		return a.first>b.first;
	}
	};
	unordered_map<string,set<pair<int,string>,cmp>>cui;
	unordered_map<string,pair<string,int>> foo;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n= foods.size();
	for(int i=0;i<n;i++)
	{
		cui[cuisines[i]].insert({ratings[i],foods[i]});
	foo[foods[i]]={cuisines[i],ratings[i]};
	}
    }
    
    void changeRating(string food, int newRating) {
        auto &[cuisine, oldRating] = foo[food];
	cui[cuisine].erase({oldRating,food});
	cui[cuisine].insert({newRating,food});
    oldRating= newRating;
    }
    
    string highestRated(string cuisine) {
        return cui[cuisine].begin()->second;
    }
};