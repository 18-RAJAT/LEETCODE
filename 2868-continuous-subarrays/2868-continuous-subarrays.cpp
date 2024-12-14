class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int>mx,mn;
        long long l=0,r=0,ans=0;
        long long n=nums.size();
        for(int i=0;i<n;++i)
        {
            //dec
            while(!mx.empty() && nums[mx.back()]<nums[i])
            {
                mx.pop_back();
            }
            mx.push_back(i);
            //monotonic inc
            while(!mn.empty() && nums[mn.back()]>nums[i])
            {
                mn.pop_back();
            }
            mn.push_back(i);
            
            while(nums[mx.front()]-nums[mn.front()]>2)
            {
                if(mx.front()<mn.front())
                {
                    l=mx.front()+1;mx.pop_front();
                }
                else
                {
                    l=mn.front()+1;mn.pop_front();
                }
            }
            ans+=i-l+1;
        }
        return ans;
    }
};