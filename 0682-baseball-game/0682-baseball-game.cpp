class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string i:operations)
        {
            if(isdigit(i[0])|| (i[0] == '-' && i.size() > 1))
            {
                st.push(stoi(i));
            }
            else
            {
                if(i=="C")
                {
                    st.pop();
                }
                else if(i=="D")
                {
                    int top = st.top();
                    st.push(top*2);
                }
                else
                {
                    int fir = st.top();
                    st.pop();
                    int sec = st.top();
                    int sum = fir+sec;
                    st.push(fir);
                    st.push(sum);
                }
            }
        }
        int ans =0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};