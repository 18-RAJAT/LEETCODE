class Solution {
public:
    int longestWPI(vector<int>& hours) {
        //using monotonic stack
        int n=hours.size();
        vector<int>prefix(n+1);
        for(int i=0;i<n;++i)
        {
            prefix[i+1]=prefix[i]+(hours[i]>8?1:-1);
        }
        stack<int>st;
        for(int i=0;i<=n;++i)
        {
            if(st.empty() || prefix[st.top()]>prefix[i])
            {
                st.push(i);
            }
        }
        int ans=0;
        for(int i=n;~i;--i)
        {
            while(!st.empty() && prefix[st.top()]<prefix[i])
            {
                ans=max(ans,i-st.top());
                st.pop();
            }
        }
        return ans;
    }
};