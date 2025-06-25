class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //variable size window...
        int n=s.size(),i=0,j=0,ans=0;
        map<char,int>mp;
        while(j<n)
        {
            mp[s[j]]++;
            while(mp[s[j]]>=2)
            {
                mp[s[i]]--,i++;
            }
            ans=max(ans,j-i+1),j++;
        }
        return ans;
    }
};