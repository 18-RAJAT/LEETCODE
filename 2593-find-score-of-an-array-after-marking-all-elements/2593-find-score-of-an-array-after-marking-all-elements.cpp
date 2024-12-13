class Solution{
public:
    long long findScore(vector<int>&nums){
        int n=nums.size();
        vector<bool>ok(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;++i)pq.push({nums[i],i});
        long long score=0;
        while(!pq.empty())
        {
            auto[F,S]=pq.top();
            pq.pop();
            if(ok[S])continue;
            score+=F;
            ok[S]=true;
            if(S>0)ok[S-1]=true;
            if(S<n-1)ok[S+1]=true;
        }
        return score;
    }
};