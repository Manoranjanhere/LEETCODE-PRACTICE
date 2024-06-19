class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(char c:s)
        {
            if(c=='('||c=='['||c=='{')
            {
                a.push(c);
            }
            
            else
            {
               if(a.empty()||
               (c==')'&&a.top()!='(')||
               (c=='}'&&a.top()!='{')||
               (c==']'&&a.top()!='['))
               {
                return false;
               }
               a.pop();
            }

        }
        return a.empty();
    }
};