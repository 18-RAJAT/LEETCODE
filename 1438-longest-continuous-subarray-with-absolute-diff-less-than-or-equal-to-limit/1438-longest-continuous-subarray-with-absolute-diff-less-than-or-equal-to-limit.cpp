class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int>ms;
        int j=0,ans=1;
        for(int i=0;i<n;i++)
        {
            ms.insert(nums[i]);
            for(;!ms.empty() && *ms.rbegin()-*ms.begin()>limit;)ms.erase(ms.find(nums[j++]));
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};