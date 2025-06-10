class Solution{
public:
    int maxDifference(string s){
        map<char,int>mp;
        for(auto& it:s)mp[it]++;
        int mx=-1e9,mn=1e9;
        for(auto& it:mp)
        {
            if(it.second&1)mx=max(mx,it.second);
            else mn=min(mn,it.second);
        }
        return mx-mn;
    }
};