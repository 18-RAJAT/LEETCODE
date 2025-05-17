class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int cnt[3];
        memset(cnt,0,sizeof(cnt));
        
        for(int i=0;i<n;i++)
        {
            cnt[nums[i]]++;
        }
        int idx=0;
        for(int i=0;i<3;i++)
        {
            while(cnt[i]--)
            {
                nums[idx]=i;idx++;
            }
        }
    }
};