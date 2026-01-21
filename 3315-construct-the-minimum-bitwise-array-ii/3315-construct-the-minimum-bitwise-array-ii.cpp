class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;++i)
        {
            int res=-1,ok=1;
            while((nums[i]&ok)!=0)
            {
                res=nums[i]-ok,ok<<=1;
            }
            nums[i]=res;
        }
        return nums;
    }
};