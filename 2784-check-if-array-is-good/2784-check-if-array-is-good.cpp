class Solution {
public:
    bool isGood(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)return false;
        vector<int>ar(205,0);
        for(int i=0;i<n;++i)ar[nums[i]]++;
        for(int i=1;i<n;++i)
        {
            if(i==n-1) 
            {
                if(ar[i]!=2) return false;
            }
            else
            {
                if(ar[i]!=1) return false;
            }
        }
        return true;
    }
};