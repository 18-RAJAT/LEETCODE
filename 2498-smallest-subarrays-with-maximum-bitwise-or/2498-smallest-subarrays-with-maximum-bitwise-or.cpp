class Solution {
public:
     vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1),last(30,0);
        for(int i=n-1;~i;--i)
        {
            for(int j=0;j<30;++j)
            {
                if(nums[i]&(1<<j))last[j]=i;
                res[i]=max(res[i],last[j]-i+1);
            }
        }
        return res;
    }
};