class Solution{
    public:
    int findDuplicate(vector<int>&nums)
    {
       int start = 0;
       int end = nums.size()-1;
        int ct;
            
            while(start <= end)
            {
                    int mid = start + (end - start)/2;
                    ct = 0;
                    
                    for(auto n : nums)
                    {
                            if(n <= mid)
                            {
                                    ct++;
                            }
                    }
                    
                    if(ct <= mid)
                    {
                            start = mid + 1;
                    }
                    else
                    {
                            end = mid - 1;
                    }
            }
            return start;
    }
};
