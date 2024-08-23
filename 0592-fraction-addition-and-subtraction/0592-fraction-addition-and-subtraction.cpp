class Solution {
public:
    int lcm(int a,int b)
    {
        return (a*b)/gcd(a,b);
    }
    string fractionAddition(string n) {
        vector<int> num;
        vector<int> dem;
        int temp;
        int j=0;
        string nu="";
        while(j<n.size())
        {
             
            nu="";
                while(n[j]!='/')
                {
                    nu+=n[j];
                    j++;
                }
                if(!nu.empty())
                {
                temp=stoi(nu);
                num.push_back(temp);
                }
                
                j++;
                nu="";
                while(j<n.size()&&n[j]!='+'&&n[j]!='-')
                {
                    nu+=n[j];
                    j++;
                }
                if(!nu.empty())
                {
                temp= stoi(nu);
                dem.push_back(temp);
                }
                
        }
        int lcmm = 1;
        int sz = dem.size();
        for(auto i: dem)
        {
            lcmm=lcm(lcmm,i);
            cout<<lcmm<<endl;
        }
        int top=0;
        for(int i=0;i<sz;i++)
        {
            top+= (lcmm/dem[i])*num[i];
            cout<<num[i]<<" "<<dem[i]<<endl;
        }
        if(top!=0)
        {
        int com= gcd(lcmm,top);
        lcmm/=com;
        top/=com;
        }
        string ans ="";
        if(top==0)
        {
           ans=to_string(top)+"/1";
        }
        else
        {
            ans=to_string(top)+"/"+to_string(lcmm);
        }
        return ans;
    }
};