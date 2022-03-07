



class Solution{
public:
    
    int n;
    vector<vector<int>>answer;
    
    vector<int> Pair;
    
    vector<vector<int>> subsets(vector<int>& nums){
        
        n = nums.size();
        backtrack(0,nums);
        return answer;
        
    }
    
    void backtrack(int idx,vector<int>& nums)
    {
        if(idx == n)
        {
            answer.push_back(Pair);
        }
        
        else
        {
            Pair.push_back(nums[idx]);
            backtrack(idx+1,nums);
            Pair.pop_back();
            backtrack(idx+1,nums);
        }
    }
    
};



// class Solution {
// public:
    
//     vector<vector<int>>ans;
    
//     void helper (int i,vector<int>&nums,vector<int>&temp)
//     {
//         if(i == nums.size())
//         {
//             ans.push_back(temp);
//         }
        
//         else
//         {
//             //To Get The ith Element
//             temp.push_back(nums[i]);
            
            
//            helper (i+1,nums,temp);
//             temp.pop_back();
            
            
//             //To ignore The ith element
//             helper (i+1,nums,temp);
//         }
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
        
//             vector<int>temp;
            
//             helper (0,nums,temp);
            
//             return ans;
        
//     }
// };

