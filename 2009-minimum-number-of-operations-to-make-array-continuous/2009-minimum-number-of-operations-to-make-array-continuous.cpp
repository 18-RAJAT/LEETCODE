class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        int first=0,last=n-1;
        int unique=0;
        for(int i=0;i<n;++i)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==1)
            {
                unique++;
            }
            while(nums[i]-nums[first]>=n)
            {
                mp[nums[first]]--;
                if(mp[nums[first]]==0)
                {
                    unique--;
                }
                first++;
            }
            last=min(last,n-unique);//n-unique is the number of elements that are not unique
        }
        return last;
    }
};