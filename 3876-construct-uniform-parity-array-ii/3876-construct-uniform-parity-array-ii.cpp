class Solution{
public:
    bool uniformArray(vector<int>&nums){
        int mn=INT_MAX,cnt=0;
        for(int i=0;i<nums.size();++i)
        {
            mn=min(mn,nums[i]);
            if(nums[i]%2)cnt++;
        }
        return mn%2 || cnt==0;
    }
};