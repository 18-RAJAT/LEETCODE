class Solution {
public:
    int majorityElement(vector<int>& nums) {
     int maj=0;
            int ct=0;
            int n=nums.size();
            for(int i=0;i<n;++i){
            if(ct==0){maj=nums[i];}
            if(nums[i]==maj)ct++;
            else ct--;
            }
            return maj;
    }
};