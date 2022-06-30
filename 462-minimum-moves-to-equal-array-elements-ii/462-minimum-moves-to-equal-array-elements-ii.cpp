class Solution {
public:
    int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums.size()-1;
    int mid = (low+high)/2;

    int ct=0;
    for(int i=0;i<=mid;i++)
    {ct+=nums[mid]-nums[i];}
    
    for(int i=mid;i<=high;i++)
    {ct+=nums[i]-nums[mid];}
    return ct;
    }
};

