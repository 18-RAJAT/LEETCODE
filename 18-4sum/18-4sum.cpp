// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
//         vector<vector<int>>result;
        
//         int n = nums.size();
//         if(nums.size() == 0)
//         {
//             return result;
//         }
        
//         sort(nums.begin(),nums.end());
        
//         //taking the 2 pointers i and j 
//         for(int i=0;i<n;++i)
//         {
//             for(int j=i+1;j<n;++j)
//             {
                
//                 int NewTarget = target-nums[i]-nums[j];
                
//                 int start = j+1; //This is the starting pointer of remaning array...!!
//                 int end = n-1; //Ending pointer...!!
                
//                 while(start < end)
//                 {
//                     int sum = nums[start] + nums[end];
                    
//                     if(sum < NewTarget)
//                     {
//                         start++;
//                     }
                    
//                     else if(sum > NewTarget)
//                     {
//                         end--;
//                     }
                    
//                     else
//                     {
//                         //taking the temp variable
//                         vector<int>temp(4,0);
                        
//                         temp[0] = nums[i];
//                         temp[1] = nums[j];
//                         temp[2] = nums[start];
//                         temp[3] = nums[end];
                        
//                         result.push_back(temp);
                        
//                         //Skipping the duplicates...!!
                        
//                         while(start < end and nums[start] == temp[2])
//                          start++;
                        
//                         while(start < end and nums[end] == temp[3])
//                           end--;                    
//                     }
//                 }
                
//                 while(j+1 < n and nums[j+1] == nums[j])
//                     j++;
//             }
            
//                while(i+1 < n and nums[i+1] == nums[i])
//                    i++;
//         }
        
//         return result;
        
//     }
// };


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
  
        vector<vector<int>>result;
        if(nums.size() == 0)
        {
            return result;
        }
        
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int NewTarget = target - nums[i] - nums[j];
                int start = j+1;
                int end = n-1;
                
                while(start < end)
                {
                    int sum = nums[start] + nums[end];
                    
                    if(sum < NewTarget)
                    {
                        start++;
                    }
                    
                    else if(sum > NewTarget)
                    {
                        end--;
                    }
                    
                    else
                    {
                        vector<int>temp(4,0);
                        
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[start];
                        temp[3] = nums[end];
                        
                        result.push_back(temp);
                        
                        while(start < end and nums[start] == temp[2])
                            start++;
                        
                        while(start < end and nums[end] == temp[3])
                            end--;
                    }
                }
                
                while(j+1 < n and nums[j+1] == nums[j])
                    j++;
                
            }
            
               while(i+1 < n and nums[i+1] == nums[i])
                   i++;
        }
            
        return result;
    
    }
};