class Solution {
public:
    int minLength(string s) {
    while(true)
    {
        size_t ind1= s.find("AB");
        size_t ind2= s.find("CD");
        if(ind1==string::npos&&ind2==string::npos)
        {
            return s.length();
        }
            if(ind1!=string::npos)
            {
                s=s.substr(0,ind1)+s.substr(ind1+2);
            }
            else if(ind2!=string::npos)
            {
                s=s.substr(0,ind2)+s.substr(ind2+2);
            }
        
    }
    }
};