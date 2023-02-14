class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        // for(int i=0;i<n;++i)
        // {
        //     for(int j=i+1;j<n;++j)
        //     {
        //         if(nums[i]+nums[j]==target)
        //         {
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};
        
        
        //reduce TC
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<n;++i)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(i);
            }
            mp[nums[i]]++;
        } 
        int f=nums[ans[0]];//1
        for(int i=0;i<n;++i)
        {
            if(nums[i]==(target-f))
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};