class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
	for(string i:tokens)
	{
		if(i=="+"||i=="-"||i=="*"||i=="/")
		{
			int d1 = st.top();
			st.pop();
			int d2 = st.top();
			st.pop();
			if(i=="+")st.push(d2+d1);
			else if(i=="-")st.push(d2-d1);
			else if(i=="*")st.push(d2*d1);
			else if(i=="/")st.push(d2/d1);
		}
		else
		{
			st.push(stoi(i));
		}
	}
	return st.top();
    }	
};