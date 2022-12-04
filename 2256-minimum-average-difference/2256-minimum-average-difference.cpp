class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int prefixR=0,prefixL=0;
        for(auto it:nums)
            
        prefixR+=it;

        int mn=INT_MAX,ans=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            prefixR-=nums[i];
            prefixL+=nums[i];
            // int temp=abs(prefixL-(prefixR));
            int temp=abs(prefixL/(i+1)-prefixR/(n-i-1));
            if(temp<mn)
            {
                mn=temp;
                ans=i;
            }
        }
        if(mn>(prefixL+nums.back())/n)
        {
            return n-1;
        }
        return ans;
    }
};