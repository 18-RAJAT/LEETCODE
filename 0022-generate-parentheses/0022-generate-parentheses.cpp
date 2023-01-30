class Solution {
public:
    void par(vector<string>&brac,int open,int close,string s)
    {
        if(open==0 and close==0)
        {
            brac.push_back(s);
            return;
        }
        if(open>0)
        {
            par(brac,open-1,close+1,s+"(");
        }
        if(close>0)
        {
            par(brac,open,close-1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>brac;
        par(brac,n,0,"");
        return brac;
    }
};