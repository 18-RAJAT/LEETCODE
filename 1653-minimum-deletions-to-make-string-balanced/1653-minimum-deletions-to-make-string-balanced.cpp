class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int ans=0;
        for(auto& it:s)
        {
            if(it=='b')st.push(it);
            else if(it=='a')
            {
                if(!st.empty())st.pop(),ans++;
            }
        }
        return ans;
    }
};