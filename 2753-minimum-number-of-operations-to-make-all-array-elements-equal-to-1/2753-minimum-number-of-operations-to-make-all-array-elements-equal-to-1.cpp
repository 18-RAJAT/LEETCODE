class Solution {
public:
    int minOperations(vector<int>& nums) {
        function<int(int,int)>GCD=[&](int a,int b)->int
        {
            if(a==0)
            {
                return b;
            }
            return GCD(b%a,a);
        };
        int count=0;
        auto countOne=[&](vector<int>&nums)->int
        {
            for(int i=0;i<nums.size();++i)
            {
                if(nums[i]==1)
                {
                    count++;
                }
            }
            return count;
        };
        countOne(nums);
        if(count>0)
        {
            return nums.size()-count;
        }
        int mx=INT_MAX,num=1;
        for(int i=0;i<nums.size();++i)
        {
            int num=nums[i];
            for(int j=i+1;j<nums.size();++j)
            {
                num=GCD(num,nums[j]);
                if(num==1)
                {
                    mx=min(mx,j-i);
                    break;
                }
            }
            if(num!=1)
            {
                break;
            }
        }
        if(mx==INT_MAX)
        {
            return -1;
        }
        return mx+nums.size()-1;
    }
};