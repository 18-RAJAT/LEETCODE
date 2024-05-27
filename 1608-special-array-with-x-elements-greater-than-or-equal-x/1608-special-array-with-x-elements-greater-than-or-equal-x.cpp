class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<=nums.size();++i)
        {
            int lb=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            if(i==nums.size()-lb)
            {
                return i;
            }
        }
        return -1;
    }
};