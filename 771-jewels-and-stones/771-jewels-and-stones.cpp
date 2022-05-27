class Solution {
public:
    int numJewelsInStones(string j, string s) {
        set<char>st(j.begin(),j.end());
            int ans=0;
            for(auto it : s)
                    if(st.count(it))ans++;
                            return ans;
    }
};