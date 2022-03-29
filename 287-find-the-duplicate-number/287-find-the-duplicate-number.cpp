// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        
        
// //BRUTE FORCE APPROACH.....!!
//         int index = 0;
        
//         //Sort
//         sort(nums.begin(),nums.end());
        
//         for(int i=0;i<nums.size()-1;++i)
//      {
//                 //Break this loop
//             if(nums[i] == nums[i+1])
//             {
//                 index = nums[i];
//                 break;
//             }
            
//       }
        
//         return index;
        
//     }
// };





//USING BINARY SEARCH...!!

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
  
        int start = 1;
        int end = nums.size()-1;
        int count;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            count = 0;
            
            for(int n  : nums)
            {
                if(n <= mid)
                {
                    count++;
                }
            }
            
            //Binary search left side
            if(count <= mid)
            {
                start = mid + 1;
            }
            
            //Binary search right side
            else
            {
                end = mid - 1;
            }
        }
        return start;
    }
};

