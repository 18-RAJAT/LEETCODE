class Solution {
public:
    void sortColors(vector<int>& nums) {
      // sort(nums.begin(),nums.end());
     int start=0,end=nums.size()-1,mid=0;
            while(mid<=end)
            {
                    switch(nums[mid])
                    {
                            case 0:
                            swap(nums[start++],nums[mid++]);
                                    break;
                            case 1:
                             mid++;
                                    break;
                            case 2:
                            swap(nums[mid],nums[end--]);
                                    break;
                    }
            }
        
    }
};