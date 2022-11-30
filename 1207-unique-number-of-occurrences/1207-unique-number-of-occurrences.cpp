class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        set<int>st;
        for(auto it:mp)
        {
            st.insert(it.second);
        }
        if(mp.size()==st.size())
        {
            return true;
        }
        return false;
    }
};