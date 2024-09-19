class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+'||s[i]=='-'||s[i]=='*')
            {
                vector<int> asn1 = diffWaysToCompute(s.substr(0,i));
                vector<int> asn2 = diffWaysToCompute(s.substr(i+1));
            
                for(int j=0;j<asn1.size();j++)
                {
                    for(int k=0;k<asn2.size();k++)
                    {
                        if(s[i]=='+') ans.emplace_back(asn1[j]+asn2[k]);
                        if(s[i]=='-') ans.emplace_back(asn1[j]-asn2[k]);
                        if(s[i]=='*') ans.emplace_back(asn1[j]*asn2[k]);
                    }
                }
            }
        }
        if(ans.size()==0)
        {
            ans.push_back(stoi(s));
        }
        return ans;
    }
};