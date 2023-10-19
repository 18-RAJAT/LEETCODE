class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        function<int(int,int,int)>binary_search=[&](int left,int right,int key)->int
        {
            while(left<=right)
            {
                int mid=left+(right-left)/2;
                if(nums[mid]==key)
                {
                    return mid;
                }
                else if(nums[mid]>key)
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            return -1;
        };
        for(int i=0;i<n;++i)//first number
        {
            if(i>0 && nums[i]==nums[i-1])//duplicate
            {
                continue;
            }
            for(int j=i+1;j<n;++j)//second number
            {
                if(j>i+1 && nums[j]==nums[j-1])//dupicate
                {
                    continue;
                }
                int third=-(nums[i]+nums[j]);//third number
                int k=binary_search(j+1,n-1,third);
                if(~k)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                }
            }
        }
        return ans;
    }
};