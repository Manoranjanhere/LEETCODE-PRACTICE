class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;
        int n = classes.size();
        if(n==1)
        {
           return ((double)(classes[0][0])+extraStudents)/((double)(classes[0][1])+extraStudents);
        }
        for(int i=0;i<n;i++)
        {
	    double gain =(double)(classes[i][0]+1)/(classes[i][1]+1)-(double)classes[i][0]/classes[i][1];
            pq.push({gain,i});
        }
        for(int i=0;i<extraStudents;i++)
        {
            auto curr =pq.top();
            auto idx = curr.second;
            pq.pop();
            classes[idx][0]+=1;
            classes[idx][1]+=1;
            double newGain = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1) - 
                             (double)classes[idx][0] / classes[idx][1];
            pq.push({newGain, idx});
        }
        double ans =0;
        for(int i=0;i<n;i++)
        {
            ans+=(double)classes[i][0]/classes[i][1];
        }
        return ans/n;
    }
};