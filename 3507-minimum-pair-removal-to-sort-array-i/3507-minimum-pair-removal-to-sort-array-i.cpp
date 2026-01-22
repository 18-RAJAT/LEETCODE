class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
        while(1)
        {
            int ok=1;
            for(int i=1;i<nums.size();++i)
            {
                if(nums[i]<nums[i-1])
                {
                    ok=0;
                    break;
                }
            }
            if(ok || nums.size()<=1)break;
            int n=nums.size(),mn=INT_MAX,id=0;
            for(int i=0;i<n-1;++i)
            {
                int x=nums[i]+nums[i+1];
                if(x<mn)mn=x,id=i;
            }
            int x=nums[id]+nums[id+1];
            nums[id]=nums[id]+nums[id+1];
            nums.erase(nums.begin()+id+1);
            cnt++;
        }
        return cnt;
    }
};