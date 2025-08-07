class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
	for(string i:tokens)
	{
		if(i=="+")
		{
			int d1 = stoi(st.top());
			st.pop();
			int d2 = stoi(st.top());
			st.pop();
			st.push(to_string(d1+d2));
		}
		else if(i=="-")
		{
			int d1 = stoi(st.top());
			st.pop();
			int d2 = stoi(st.top());
			st.pop();
			st.push(to_string(d2-d1));
		}
		else if(i=="*")
		{
			int d1 = stoi(st.top());
			st.pop();
			int d2 = stoi(st.top());
			st.pop();
			st.push(to_string(d1*d2));
		}
		else if(i=="/")
		{
			int d1 = stoi(st.top());
			st.pop();
			int d2 = stoi(st.top());
			st.pop();
			st.push(to_string(d2/d1));
		}
		else
		{
			st.push(i);
		}
	}
	return stoi(st.top());
    }	
};