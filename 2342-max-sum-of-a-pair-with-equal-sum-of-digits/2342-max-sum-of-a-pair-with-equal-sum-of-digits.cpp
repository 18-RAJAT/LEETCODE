class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int mx=-1;
        map<int,priority_queue<int>>m;
        for(int i=0;i<nums.size();++i)
        {
            int sum=0;
            int n=nums[i];
            while(n>0)
            {sum += n%10;n/=10;}
            m[sum].push(nums[i]);
            if(m[sum].size()>=2)
            {
                int p=m[sum].top();
                m[sum].pop();
                int q = m[sum].top();
                m[sum].push(p);
                mx=max(mx,p+q);
            }
        }
        return mx;
    }
};