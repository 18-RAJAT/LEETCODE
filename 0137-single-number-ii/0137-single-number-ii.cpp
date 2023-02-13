class Solution {
public:
    int ans;
    int singleNumber(vector<int>& nums) {
        // return accumulate(nums.begin(),nums.end(),0,[](int a,int b){return a^b;});
        // return accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        map<int,int>hsh;
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            hsh[nums[i]]++;
        }
        for(int i=0;i<n;++i)
        {
            if(hsh[nums[i]]==1)
            {
                return nums[i];
            }
        }
        return 0;
    }
};