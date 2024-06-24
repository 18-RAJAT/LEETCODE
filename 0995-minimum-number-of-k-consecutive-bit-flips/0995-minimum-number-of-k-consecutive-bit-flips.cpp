class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        queue<int>que;
        for(int i=0;i<n;++i)
        {
            int check=que.size()%2==0?nums[i]:1-nums[i];
            if(check==0)
            {
                ans++;
                que.push(i+k-1);
            }
            if(!que.empty() && i==que.front())que.pop();
        }
        if(!que.empty())
        {
            return -1;
        }
        return ans;
    }
};