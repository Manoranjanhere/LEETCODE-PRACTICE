class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        int dotc=0;
        for(char ch:path)
        {
            if(isalpha(ch))
            {
                while(dotc)
                {
                    st.push('.');
                    dotc--;
                }
                st.push(ch);
                continue;
            }
            if(ch=='.')
            {
               dotc++;
            }
            else
            {
                if(dotc==1&&st.top()=='/')
                {
                    st.pop();
                }
                else if(dotc==2&&st.top()=='/')
                {
                    
                        st.pop();
                        while(!st.empty()&&st.top()!='/')
                        {
                            st.pop();
                        }
                }
                else
                {
                    while(dotc)
                    {
                        dotc--;
                        st.push('.');
                    }
                }
                dotc=0;
                if(ch=='/')
                {
                    if(!st.empty()&&st.top()=='/')continue;
                }
                st.push(ch);
            }
        }
                if(dotc==1&&st.top()=='/')
                {
                    st.pop();
                }
                else if(dotc==2&&st.top()=='/')
                {
                    st.pop();
                    while(!st.empty()&&st.top()!='/')
                    {
                        st.pop();
                    }
                }
                else
                {
                    while(dotc)
                    {
                        dotc--;
                        st.push('.');
                    }
                }
        string ans ="";
        while(!st.empty()&&st.top()=='/')
        {
            st.pop();
        }
        if(st.empty())return "/";
        while(!st.empty())
        {
            char curr = st.top();
            st.pop();
            ans=curr+ans;
        }
        return ans;
    }
};