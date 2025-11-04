class Solution{
public:
    vector<int>findXSum(vector<int>&nums,int k,int x){
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<=n-k;++i)
        {
            unordered_map<int,int>fz;
            for(int j=i;j<i+k;++j)
            {
                fz[nums[j]]++;
            }
            vector<pair<int,int>>pr;
            for(auto& [num,count]:fz)
            {
                pr.push_back({count,num});
            }
            sort(pr.begin(),pr.end(),[](const pair<int,int>&a,const pair<int,int>&b)
                 {
                    if(a.first==b.first)return a.second>b.second;
                    return a.first>b.first;
                });
            int sum=0;
            int temp=min(x,(int)pr.size());
            for(int j=0;j<temp;++j)
            {
                sum+=pr[j].first*pr[j].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};