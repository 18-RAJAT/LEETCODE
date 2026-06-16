class Solution {
public:
    string processStr(string s) {
        string ans;
        for(auto& it:s)
        {
            if(it=='*')
            {
                if(ans.size()>=1)ans.pop_back();
            }
            else if(it=='#')ans+=ans;
            else if(it=='%')
            {
                reverse(ans.begin(),ans.end());
            }
            else ans.push_back(it);
        }
        return ans;
    }
};