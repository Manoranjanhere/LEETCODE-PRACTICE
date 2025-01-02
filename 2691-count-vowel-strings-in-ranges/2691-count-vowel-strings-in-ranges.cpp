class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        cout<<n;
        vector<int> make;
        int i=0;
        vector<int> ans;
        for(string a:words)
        {
            if((a[0]=='a'||a[0]=='e'||a[0]=='i'||a[0]=='o'||a[0]=='u')&&(a[a.length()-1]=='a'||a[a.length()-1]=='e'||a[a.length()-1]=='i'||a[a.length()-1]=='o'||a[a.length()-1]=='u'))
            {
                i++;
            }
            make.push_back(i);
        }
        for(int i:make)
        {
            cout<<i<<" ";
        }
        for(auto i:queries)
        {
            int sub=0;
            if(i[0]!=0)
            {
                sub=make[i[0]-1];
            }
            ans.push_back(make[i[1]]-sub);
        }
        return ans;
    }
};