class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        mp[0]=1;
        int check=nums[0]%k;
        //(i-(j+1)+1)=i-j>=2..
        for(int i=1;i<n;++i)
        {
            int tmp=check;
            check=(check+nums[i])%k;
            if(mp.count(check))return true;
            mp[tmp]++;
        }
        return false;
    }
};