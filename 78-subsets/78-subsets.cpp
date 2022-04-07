class Solution {
public:
    
   int n;
    
    //Store the answer in answer vector
    vector<vector<int>>answer;
    
    //Pair to Pair we will take the answer variables
    vector<int>pair;
    
    //Subset Function we will write to use or taking the nums and backtrack call and then return answer....!!
    vector<vector<int>> subsets(vector<int>& nums) {
    
        n = nums.size();
        backtrack(0,nums);
        return answer;
    }
    
    //This function is works on like when the pair we will created then again backtrack and find the pair of the function....!!
    
    void backtrack(int index,vector<int>& nums)
    {
        if(index == n)
        {
            answer.push_back(pair);
        }
        
        else
        {
            
            //This will given pair
            pair.push_back(nums[index]);
            
            //Backtracking
            backtrack(index+1,nums);
            
            //When the pair will be created then  the pair will be poped out
            pair.pop_back();
            
            //When one pair is created then next pair will be create again again again when the string is not over...!!
            backtrack(index+1,nums);
        }
    }
};