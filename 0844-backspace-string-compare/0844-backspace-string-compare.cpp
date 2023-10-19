class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        auto check=[&](string &s)->string
        {
            string ans;
            for(auto &it:s)
            {
                if(it=='#')
                {
                    if(ans.size())
                    {
                        ans.pop_back();
                    }
                }
                else
                {
                    ans.push_back(it);
                }
            }
            return ans;
        };
        return check(s)==check(t)?true:false;      
    }
};