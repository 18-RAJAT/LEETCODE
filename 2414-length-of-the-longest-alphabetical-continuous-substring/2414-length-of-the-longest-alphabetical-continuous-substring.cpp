class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int curr=1;
        int maxi=1;
        for(int i=1;i<n;++i)
        {
            if(s[i]!=s[i-1])
            {
                if(s[i]==s[i-1]+1)
                {
                    curr++;
                }
                else
                {
                    maxi=max(maxi,curr);curr=1;
                }
            }
        }
        return max(maxi,curr);
    }
};