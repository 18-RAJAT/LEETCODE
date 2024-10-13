class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>&nums) {
        int n=nums.size();
        map<pair<int,int>,int>pq;
        for(int i=0;i<n;++i)
        {
            if(nums[i].size()>0)pq[{nums[i][0],i}]=0;
        }
        if(pq.size()==0)return{};
        if(pq.size()==1)return{pq.begin()->first.first,pq.begin()->first.first};
        int sza=pq.size(),start=pq.begin()->first.first,end=prev(pq.end())->first.first;
        if(start==end)return{start,end};
        while(pq.size()==sza)
        {
            int fi=pq.begin()->first.second;
            int se=pq.begin()->second;
            pq.erase(pq.begin());
            int j=se;
            for(;j<nums[fi].size() && nums[fi][j]==nums[fi][se];++j);
            if(j<nums[fi].size())
            {
                pq[{nums[fi][j],fi}]=j;
                int ns=pq.begin()->first.first,ne=prev(pq.end())->first.first;
                if(ne-ns<end-start)
                {
                    start=ns;
                    end=ne;
                    if(start==end)return{start,end};
                }
            }
        }
        return{start,end};
    }
};