class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        int sz=basket1.size(),mn=INT_MAX;
        for(int i=0;i<sz;++i)
        {
            mp[basket1[i]]++;
            mp[basket2[i]]--;
            mn=min({mn,basket1[i],basket2[i]});
        }
        vector<int>v1,v2;
        for(auto& [i,j]:mp)
        {
            if(j%2)return -1;
            int ok=abs(j)/2;
            if(j>=1)v1.insert(v1.end(),ok,i);
            else v2.insert(v2.end(),ok,i);
        }
        if(v1.size()!=v2.size())return -1;
        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        long long res=0;
        for(int i=0;i<v1.size();++i)
        {
            res+=min({v1[i],v2[i],2*mn});
        }
        return res;
    }
};