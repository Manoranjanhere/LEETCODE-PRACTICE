class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return solve(0,s,st,"");
    }
        int solve(int ind, string& s, unordered_set<string>& st, string temp){
            if(ind==s.length())
            {
                return 0;
            }
            else
            {
                temp+=s[ind];
                int op1=-1;
                int op2=-1;
                if(st.find(temp)==st.end())
                {
                    st.insert(temp);
                    op1=1+solve(ind+1,s,st,"");
                    st.erase(temp);
                }
                op2=solve(ind+1,s,st,temp);
                return max(op1,op2);
            }
        }

};