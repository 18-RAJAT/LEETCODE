class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(const auto&it:details)
        {
            
            auto x=it[11]-'0';
            auto y=it[12]-'0';
            ans+=x*10+y>=61;
            
        }
        return ans;
    }
};