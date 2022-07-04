class Solution {
public:
    int hRob(int curIdx,int target,vector<int>& nums) {
        //space optimization in tabulation
        int n=0;//n==next
        int nxt=nums[curIdx];
        for(int i=curIdx-1;i>=target;--i)
        {
            int rob=nums[i]+n;
            int noRob=nxt;
            int currAmt=max(rob,noRob);n=nxt;nxt=currAmt;
        }
        return nxt;
    }
    int rob(vector<int>&nums)
    {
        int n=nums.size();
        if(n==1){return nums[0];}
        return max(hRob(n-1,1,nums),hRob(n-2,0,nums));
    }
};