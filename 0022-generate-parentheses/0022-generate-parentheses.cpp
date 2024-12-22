class Solution {
public:
    void parenthesis(vector<string>&B,int open,int close,string s)
    {
        if(open==0 and close==0)
        {
            B.push_back(s);
            return;
        }
        if(open>0)
        {
            parenthesis(B,open-1,close+1,s+"(");
        }
        if(close>0)
        {
            parenthesis(B,open,close-1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>B;
        parenthesis(B,n,0,"");
        return B;
    }
};