class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        set<int>st;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                st.insert(nums[i]);
            }
            else
            {
                st.insert(nums[i]*2);
            }
        }
        int ans=INT_MAX;
        while(st.size()>0)
        {
            int mx=*st.rbegin();
            int mn=*st.begin();
            ans=min(ans,mx-mn);
            if(mx%2==0)
            {
                st.erase(mx);
                st.insert(mx/2);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};