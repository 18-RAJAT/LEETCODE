class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>mp;
        for(auto &i:tickets)
        {
            mp[i[0]].insert(i[1]);
        }
        vector<string>ans;
        stack<string>st;
        st.push("JFK");
        while(!st.empty())
        {
            string s=st.top();
            if(mp[s].empty())
            {
                ans.push_back(s);
                st.pop();
            }
            else
            {
                st.push(*mp[s].begin());
                mp[s].erase(mp[s].begin());
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};