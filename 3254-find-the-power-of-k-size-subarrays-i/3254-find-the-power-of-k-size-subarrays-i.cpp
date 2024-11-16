class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=1 || k<=1)return nums;
        vector<int>ans(n-k+1,0);
        for(int i=0;i<=n-k;++i)
        {
            int res=1e9,ok=0;
            for(int j=i;j<i+k-1;++j)
            {
                if(1+nums[j]==nums[j+1])
                {
                    res=nums[j+1];
                    continue;
                }
                else
                {
                    ans[i]=-1,ok=1;
                    break; 
                }  
            }
            if(!ok)ans[i]=res;
        }
        return ans;
    }
};