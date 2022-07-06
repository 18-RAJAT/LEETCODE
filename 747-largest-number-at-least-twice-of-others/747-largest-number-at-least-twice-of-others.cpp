class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx=INT_MIN,idx=-1;
        for(int i=0;i<nums.size();++i){if(nums[i]>mx){mx=nums[i];idx=i;}}
        for(int i=0;i<nums.size();++i){if(mx!=nums[i])if(mx>=2*nums[i])continue;else return -1;}
        return idx;
    }
};
