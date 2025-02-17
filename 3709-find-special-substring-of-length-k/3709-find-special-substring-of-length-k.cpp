class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        vector<pair<char,int>>vp;
        for(auto it=s.begin();it!=s.end();)
        {
            auto nxt=find_if(it,s.end(),[&](char c){return c!=*it;});
            vp.emplace_back(*it,distance(it,nxt));
            it=nxt;
        }
        return any_of(vp.begin(),vp.end(),[&](auto&& it){return it.second==k;});
    }
};