class Solution {
public:
    string decodeString(string s) {
        string digit="";
        stack<string> st;
	string final ="";
        for(char c:s)
        {
            if(isdigit(c))
            {
                digit+=c;
            }
            else if(c==']')
            {
                string curr=st.top();
                string word="";
                while(curr!="[")
                {
                    word=curr+word;
			st.pop();
			curr=st.top();
                }
		st.pop();
		int mul =0;
		if(!st.empty())
		{
			mul= stoi(st.top());
			st.pop();
		}
        string repeated="";
		for(int i=0;i<mul;i++)
		{
			repeated+=word;
		}
        st.push(repeated);
            }
            else
            {
                if(digit!="")
                {
                    st.push(digit);
                    digit="";
                }
                st.push(string(1,c));
            }
        }
        while(!st.empty())
        {
            final=st.top()+final;
            st.pop();
        }
	return final;
    }
};