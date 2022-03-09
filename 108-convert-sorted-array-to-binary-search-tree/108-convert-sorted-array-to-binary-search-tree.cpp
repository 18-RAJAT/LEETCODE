
class Solution {
public:
    
    TreeNode* dummy(vector<int>& nums,int start,int end)
    {
        if(start >= end)
        {
            return NULL;
        }
        
        int mid = start + (end-start)/2;
        
        return new TreeNode( nums[mid] ,  dummy(nums,start,mid) ,  dummy(nums,mid+1,end) );
    }
    
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        
        return dummy(nums,0,nums.size());
            
    }
};
   