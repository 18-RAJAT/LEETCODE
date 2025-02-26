class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mx=0,mn=0,cur1=0,cur2=0;
        for(auto& x:nums)
        {
            cur1+=x,cur2+=x;
            mx=max(mx,cur1);
            mn=min(mn,cur2);
            if(cur1<0)cur1=0;
            if(cur2>0)cur2=0;
        }
        return max(mx,-mn);
    }
};