class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        
        AddingParentheses(result,"",n,0);
        
        return result;
        
    }
    
    void AddingParentheses(vector<string> &v,string str,int n , int m)
    {
        if(n == 0 and m == 0)
        {
            v.push_back(str);
            return;
        }
        
        if(m > 0)
        {
            AddingParentheses(v,str+")",n,m-1);
        }
        
        if(n > 0)
        {
            AddingParentheses(v,str+"(",n-1,m+1);
        }
    }
};