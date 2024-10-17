class Solution {
public:
    int maximumSwap(int num) {
        char max='0';
        int ind=0;
        int ind2=0;
        string a =to_string(num);
        string b= a;
        int n = a.size();
        sort(a.rbegin(),a.rend());
        for(int i=0;i<n;i++)
        {
            if(a[i]==b[i])
            {
                continue;
            }
            else
            {
                ind =i;
                break;
            }
        }
        for(int i=ind;i<n;i++)
        {
            if(b[i]>=max)
            {
                max=b[i];
                ind2=i;
            }
        }
        cout<<ind<<" "<<ind2;
        swap(b[ind],b[ind2]);
        return stoi(b);
    }
};