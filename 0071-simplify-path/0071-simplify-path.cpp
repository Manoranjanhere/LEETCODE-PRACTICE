class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string get="";
        for(int i=0;i<=path.size();i++)
        {
            if(i==path.size()||path[i]=='/'){
                if(get==".."){if(!st.empty())st.pop();}
                else if(get!=""&&get!="."){st.push(get);}
                get="";
            }
            else get+=path[i];
        }
        string ans ="";
        while(!st.empty())
        {
            ans='/'+st.top()+ans;
            st.pop();
        }
        if(ans=="")return "/";
        return ans;
    }
};