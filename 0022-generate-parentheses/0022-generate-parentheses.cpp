class Solution {
public:
    void generate(vector<string>&ans,int open,int close,string s)
    {
            if(open==0 and close==0)
            {
                ans.push_back(s);
                return;
            }
            if(open>0)
            {
                generate(ans,open-1,close+1,s+"(");
            }
            if(close>0)
            {
                generate(ans,open,close-1,s+")");
            }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(ans,n,0,"");
        return ans;
    }
};