class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                mp[(nums[i]*nums[j])]++;
            }
        } 
        int ans=0;
        for(auto& it:mp)
        {
            if(it.second>1)
            {
                ans+=(((it.second*(it.second-1)/2))*8);
            }
        }
        return ans;
    }
};