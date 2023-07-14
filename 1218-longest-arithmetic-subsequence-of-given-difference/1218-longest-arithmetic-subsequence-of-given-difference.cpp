class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int>mp;
        int ans=1;
        for(auto& x:arr)
        {
            if(mp.count(x-difference))
            {
                mp[x]=1+mp[x-difference];
            }
            else
            {
                mp[x]=1;
            }
            ans=max<int>(ans,mp[x]);
        }
        return ans;
    }
};