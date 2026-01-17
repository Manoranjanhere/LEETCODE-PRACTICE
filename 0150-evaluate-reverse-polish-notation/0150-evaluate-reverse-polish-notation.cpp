class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(string i:tokens)
        {
            if(i=="+"||i=="-"||i=="*"||i=="/")
            {
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                if(i=="+")st.push(to_string(a+b));
                if(i=="-")st.push(to_string(b-a));
                if(i=="*")st.push(to_string(a*b));
                if(i=="/")st.push(to_string(b/a));
            }
            else st.push(i);
        }
        return stoi(st.top());
    }
};