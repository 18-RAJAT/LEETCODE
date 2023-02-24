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
            int x=*st.rbegin();
            int y=*st.begin();
            int db=x-y;
            ans=min(ans,db);
            if(x%2==0)
            {
                st.erase(x);
                st.insert(x/2);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};