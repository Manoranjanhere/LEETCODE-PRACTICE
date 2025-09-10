#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
		vector<unordered_set<int>>st(languages.size());
		for(int i=0;i<languages.size();i++)
		{
			for(int lang:languages[i])
			{
				st[i].insert(lang);
			}
		}
		unordered_set<int> notgot;
		for(auto i:friendships)
		{
			int f1 = i[0]-1;
			int f2 = i[1]-1;
			bool got = false;
			for(int lang:languages[f1])
			{
				if(st[f2].count(lang))
				{
					got=true;
					break;
				}
			}
			if(!got)
			{
				notgot.insert(f1);
				notgot.insert(f2);
			}
		}
		if(notgot.size()==0)return 0;
		vector<int> count(n+1,0);
		for(int i:notgot)
		{
			for(int lang:languages[i])
			{
				count[lang]++;
			}
		}
		int best = 0;
		for(int i=1;i<=n;i++)
		{
			best =max(best,count[i]);
		}
		return notgot.size()-best;
            }
};
