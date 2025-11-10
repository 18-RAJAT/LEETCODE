class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;++i)
        {
            if(st.empty())
            {
                if(nums[i]!=0)st.push(nums[i]);
            }
            else
            {
                while(!st.empty() && nums[i]<=st.top())
                {
                    if(st.top()!=nums[i])ans++;
                    st.pop();
                }
                if(nums[i]!=0)st.push(nums[i]);
            }
        }
        ans+=st.size();
        return ans;
    }
};