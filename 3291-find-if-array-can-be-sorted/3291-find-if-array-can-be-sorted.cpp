class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>num=nums;
        sort(num.begin(),num.end());
        function<int(int)>count_bit=[&](int bt)->int
        {
            int cnt=0;
            for(int i=0;i<10;++i)
            {
                if(bt&(1<<i))
                {
                    cnt++;
                }
            }
            return cnt;
        };
        int current_bit=count_bit(nums[0]);
        int same=0;
        for(int i=1;i<n;++i)
        {
            if(!(count_bit(nums[i])==current_bit))
            {
                same=i;
                current_bit=count_bit(nums[i]);
            }
            else
            {
                sort(nums.begin()+same,nums.begin()+i+1);
            }
        }
        return nums==num?true:false;
    }
};