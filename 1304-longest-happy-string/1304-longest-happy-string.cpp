#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        string ans="";
        while(!pq.empty())
        {
            auto a=pq.top();
            pq.pop();
            if(ans.size()>=2&& ans[ans.size()-1]==a.second&&ans[ans.size()-2]==a.second)
            {
                if(pq.empty())
                {
                    break;
                }
                auto b = pq.top();
                pq.pop();
                ans+=b.second;
                if(b.first-1>0)
                {
                    pq.push({b.first-1,b.second});
                }
                pq.push({a.first,a.second});
            }
            else
            {
                ans+=a.second;  
                if(a.first-1>0)
                {
                    pq.push({a.first-1,a.second});
                }
            }
        }
        return ans;
    }
};