class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int start = 0;
        int end = 0;
        
        vector<int>result;
        
      while(start<nums1.size() and end<nums2.size())
        {
            if( nums1[start] == nums2[end] )
            {
                result.push_back(nums1[start]);
                start++;
                end++;
            }
            
            else if(nums1[start]<nums2[end])
            {
                start++;
            }
            
            else if(nums1[start]>nums2[end])
            {
                end++;
            }
        }
        
        return result;

    }
    
};
