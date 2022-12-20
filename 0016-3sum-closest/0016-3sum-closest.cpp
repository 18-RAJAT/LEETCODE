class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<=2)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        //3 sum closest
        int max=nums[0]+nums[1]+nums[2];
        
        for(int i=0;i<nums.size();i++)
        {
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int temp=nums[i]+nums[j]+nums[k];
                if(abs(target-temp)<abs(max-target))
                {
                    max=temp;
                }
                if(target<temp)
                {
                    k--;
                }
                else if(target>temp)
                {
                    j++;
                }
                else
                {
                    return target;
                }
            }
        }
        return max;
    }
};