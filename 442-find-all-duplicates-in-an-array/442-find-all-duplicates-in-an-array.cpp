//--------------------------This solution gives me TLE---------------------------------
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
        
//         if(nums.empty())
//             return {};
        
//         vector<int>answer;
        
//         for(int i=0;i<nums.size();++i)
//         {
//             for(int j=i+1;j<nums.size();++j)
//             {
//                 if(nums[i] != nums[j])
//                     continue;
                
//                 else
//                 {
//                     answer.push_back(nums[i]);
//                     break;
//                 }
//             }
//         }
       
//         return answer;
        
//     }
// };



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int>answer;
        int n = nums.size();
        
        for(int i=0;i<n;++i)
        {
            int num = abs(nums[i]);
            
            if(nums[num-1]<0)
            {
                answer.push_back(num);
            }
            else
            {
                nums[num-1] *= -1;
            }
        }
        
        return answer;
        
    }
};










