class Solution {
public:
    vector<vector<int>>arr;
    int dp(int i,int left,int right,vector<int>& nums, vector<int>& multipliers){
        if(i>=multipliers.size())
            return 0;
        
        if(arr[left][i]!=INT_MIN)
            return arr[left][i];  
        int op1=dp(i+1,left+1,right,nums,multipliers)+multipliers[i]*nums[left];
        int op2=dp(i+1,left,right-1,nums,multipliers)+multipliers[i]*nums[right];
        return arr[left][i]=max(op1,op2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        arr.resize(1000,vector<int>(1000,INT_MIN));
        return dp(0,0,nums.size()-1,nums,multipliers);
    }
};