class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq(26,0);
        for(auto& it:s)
        {
            freq[it-'a']++;
        }
        for(auto& it:t)
        {
            freq[it-'a']--;
        }
        int ans=0;
        for(auto& it:freq)
        {
            ans+=abs<int>(it);
        }
        return ans/2;
    }
};