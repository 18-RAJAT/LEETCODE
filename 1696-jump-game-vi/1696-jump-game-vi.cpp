class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1 and k>=1){return nums[0];}
        deque<int> q; //O(k)
        vector<int> dp(n); //O(n)
        
        dp[n-1]=nums[n-1]; 
        q.push_back(n-1);
        
        for(int i=n-2;i>=0;i--) 
        { 
            //O(n)
            if(q.front()-i>k) {q.pop_front();}
            
            dp[i]=nums[i]+dp[q.front()];
            
            while(q.size() and dp[q.back()]<dp[i]){q.pop_back();}
            q.push_back(i);
        }
        return dp[0];
    }
};