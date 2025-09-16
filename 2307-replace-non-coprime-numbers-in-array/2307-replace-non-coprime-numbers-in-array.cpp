class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        st.push(nums[0]);
        int i=1;
        while(i<n)
        {
            int x=nums[i];
            while(!st.empty() && __gcd(x,st.top())>=2)
            {
                int chk=(x/__gcd(x,st.top()))*st.top();
                x=chk;
                st.pop();
            }
            st.push(x);
            i++;
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};