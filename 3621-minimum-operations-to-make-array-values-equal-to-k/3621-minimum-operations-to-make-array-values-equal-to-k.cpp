class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(auto& it:nums)
        {
            if(it<k)return-1;
        }
        set<int>st;
        for(auto& it:nums)
        {
            if(it>k)st.insert(it);
        }
        return st.size();
    }
};