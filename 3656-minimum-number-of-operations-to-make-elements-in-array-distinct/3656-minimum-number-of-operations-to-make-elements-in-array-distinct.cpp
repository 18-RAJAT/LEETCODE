class Solution{
public:
    int minimumOperations(vector<int>&nums){
        int n=nums.size(),ans=(n+2)/3;
        for(int k=0;k<=ans;++k)
        {
            int start=3*k;
            if(start>=n)return k;
            unordered_set<int>st;
            int ok=1;
            for(int i=start;i<n;++i)
            {
                if(st.find(nums[i])!=st.end())
                {
                    ok=0;
                    break;
                }
                st.insert(nums[i]);
            }
            if(ok)return k;
        }
        return ans;
    }
};