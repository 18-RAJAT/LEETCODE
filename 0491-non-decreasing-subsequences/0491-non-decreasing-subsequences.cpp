class Solution {
public:
    bool chkInc(vector<int>&v)
    {
        int n=v.size();
        for(int i=1;i<n;++i)
        {
            if(v[i]<v[i-1])
            {
                return false;
            }
        }
        return true;
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;

        int sft=1<<n;
        
        for(int i=0;i<sft;++i)
        {
            vector<int>v;
            for(int j=0;j<n;++j)
            {
                if(i&(1<<j))
                {
                    v.push_back(nums[j]);
                }
            }
            if(v.size()>=2)
            {
                if(chkInc(v))
                {
                    st.insert(v);
                }
            }
        }
        vector<vector<int>>res;
        for(auto &it:st)
        {
            res.push_back(it);
        }
        return res;
    }
};