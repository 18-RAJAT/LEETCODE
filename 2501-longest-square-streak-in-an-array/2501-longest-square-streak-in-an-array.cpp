class Solution {
public:
    const int N=1e5;
    int longestSquareStreak(vector<int>& nums) {
        int ans=0;
        map<long long int,long long int>mp;
        int count=0;
        for(int i=0;i<nums.size();++i)
        {
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();++it)
        {
            int count=0;
            long long int x=it->first;
            if(x<=N)
            {
                if(mp.count(x*x))
                {
                    count++;
                    long long int temp=x*x;
                    while(mp.count(temp))
                    {
                        count++;
                        temp*=temp;
                    }
                }
            }
            ans=max(count,ans);
        }
        return (ans==0)?-1:ans;
    }
};