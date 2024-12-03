class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int cnt=0;
        for(auto& it:spaces)
        {
            ans.append(s.begin()+cnt,s.begin()+it);
            ans+=" ",cnt=it;
        }
        ans.append(s.begin()+cnt,s.end());
        return ans;
    }
};