class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();

        int maxx =0;
        int curr_max=0;
        int lastcount=0;
        int lf=-1;
        int slf=-1;
        for(auto i:fruits)
        {
            if(i==lf||i==slf)
            {
                curr_max++;
            }
            else
            {
                curr_max=lastcount+1;
            }
            if(i==lf)
            {
                lastcount++;
            }
            else
            {
                lastcount=1;
            }
            if(i!=lf)
            {
                slf=lf;
                lf=i;
            }
            maxx=max(maxx,curr_max);
        }
        return maxx;
    }
};