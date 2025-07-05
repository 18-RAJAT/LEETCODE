class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto& it:arr)mp[it]++;
        int ans=-1;
        for(int i=1;i<=500;++i)
        {
            if(mp[i]==i)ans=i;
        }
        return ans;
    }
};