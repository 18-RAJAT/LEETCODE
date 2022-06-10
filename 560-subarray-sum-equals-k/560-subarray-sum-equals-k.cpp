class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
            int n=nums.size();
            if(n==0){return 0;}
            map<int,int>mp;
            int sum=0,i=0,ct=0;
            while(i<n)
            {
                    sum=sum+nums[i];
                    if(sum==k){ct++;}
                    
                    if(mp.find(sum-k)!=mp.end())
                    ct=ct+mp[sum-k];
                    mp[sum]++;
                    i=i+1;
            }
            return ct;
    }
};
