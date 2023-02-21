class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // vector<int>cnt(100000,0);
        // int n=nums.size();
        // for(int i=0;i<n;++i)
        // {
        //     cnt[nums[i]]++;
        // }
        // for(int i=0;i<cnt.size();++i)
        // {
        //     if(cnt[i]==1)
        //     {
        //         return i;
        //     }
        // }
        // return 0;
        
        
        
        //2nd approach
        function<int(int,int)>binarySearch=[&](int left,int right)
        {
            if(left==right)
            {
                return nums[left];
            }
            int mid=left+(right-left)/2;
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                {
                    return binarySearch(mid+2,right);
                }
                else
                {
                    return binarySearch(left,mid);
                }
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                {
                    return binarySearch(mid+1,right);
                }
                else
                {
                    return binarySearch(left,mid-1);
                }
            }
        };
        return binarySearch(0,nums.size()-1);
    }
};