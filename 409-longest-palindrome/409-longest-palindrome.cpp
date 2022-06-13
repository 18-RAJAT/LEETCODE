class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(int i = 0; i < s.size(); i++) mp[s[i]]++;      // step 1
        int ans = 0;
        vector<int>odds;
        for(auto i : mp)
        {                                  // step 2
            if(i.second % 2 != 0) odds.push_back(i.second);
            else ans += (i.second);
        }
        if(odds.size() != 0)
        {                            // step 3
            ans += odds[0];
            for(int i = 1; i < odds.size(); i++) ans += (odds[i]-1);
        }
        return ans;
    }
};