class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;++i)
        {
            unordered_map<int,int>even,odd;
            for(int j=i;j<n;++j)
            {
                int tmp=nums[j];
                (tmp&1)?odd[tmp]++:even[tmp]++;
                if(even.size()==odd.size())ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};