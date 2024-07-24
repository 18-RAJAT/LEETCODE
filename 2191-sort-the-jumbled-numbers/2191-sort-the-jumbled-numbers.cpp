class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>> mpp;
        vector<int>a;
        for(int i=0;i<n;++i)
        {
            int x=nums[i],sum=0,p=1;
            if(nums[i]==0)
            {
                sum=mapping[0];
            }
            while(x)
            {
                int cur=x%10;
                sum+=mapping[cur]*p;
                p*=10;
                x/=10;
            }
            mpp[sum].push_back(nums[i]);
        }
        for(auto& x:mpp)
        {
            for(auto& y:x.second)
            {
                a.push_back(y);
            }
        }
        return a;
    }
};