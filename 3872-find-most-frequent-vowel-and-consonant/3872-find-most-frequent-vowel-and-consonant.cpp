class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> vowel;
        unordered_map<char,int>consonant;
        int vowmax=0;
        int conmax=0;
        int n = s.size();
        for(char ch:s)
        {
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            {
                vowel[ch]++;
                if(vowel[ch]>vowmax)
                {
                    vowmax=vowel[ch];
                }
            }
            else
            {
                consonant[ch]++;
                if(consonant[ch]>conmax)
                {
                    conmax=consonant[ch];
                }
            } 
        }
        return conmax+vowmax;
    }
};