class Solution {
public:
    int numTilePossibilities(string tiles) 
    {
            int n = tiles.size();
            set<string> store;
            vector<bool> used(n,false);
            solve(tiles,store,used,"");
            return store.size()-1;
            
       }
       void solve(string tiles,set<string>&store,vector<bool>& used,string curr)
       {
            store.insert(curr);
            for(int i=0;i<tiles.size();i++)
            {
                if(!used[i])
                {
                    used[i]=true;
                    solve(tiles,store,used,curr+tiles[i]);
                    used[i]=false;
                }
            }
       }
};