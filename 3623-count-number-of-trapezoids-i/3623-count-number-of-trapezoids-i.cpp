class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int Mod=1000000007;
        map<long long,long long>mp;
        for(auto& it:points)mp[it[1]]++;
        int n=mp.size();
        vector<long long>arr;
        for(auto it=mp.begin();it!=mp.end();++it)
        {
            long long temp=((it->second)*(it->second-1))/2;
            arr.push_back(temp%Mod);
        }
        long long ans=0,res=0;
        for(auto& it:arr)res+=it;
        for(int i=0;i<arr.size();++i)
        {
            ans=(ans+arr[i]*(res-arr[i]))%Mod;
            res-=arr[i];
        }
        return ans;
    }
};