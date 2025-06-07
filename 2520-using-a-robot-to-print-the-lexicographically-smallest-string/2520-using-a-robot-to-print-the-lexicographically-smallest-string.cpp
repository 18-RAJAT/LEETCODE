class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<int>ar(26,0);
        for(auto& it:s)ar[it-'a']++;
        string ans;
        stack<char>st;
        char ch='a';
        for(auto& it:s)
        {
            st.push(it);
            ar[it-'a']--;

            while(ch<='z' && ar[ch-'a']==0)ch++;
            while(!st.empty() && st.top()<=ch)
            {
                ans+=st.top();
                st.pop();
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};