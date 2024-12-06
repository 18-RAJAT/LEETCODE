class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st(banned.begin(),banned.end());
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            if(st.count(i))continue;
            if(i<=maxSum)
            {
                ans++,maxSum-=i;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};