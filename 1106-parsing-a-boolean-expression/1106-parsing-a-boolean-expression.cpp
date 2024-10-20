class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        int sza=expression.size();
        for(int i=0;i<sza;++i)
        {
            if(expression[i] != ')')
            {
                s.push(expression[i]);
            }
            else
            {    
                int And=1,Or=0;
                while(!s.empty())
                {
                    char ch=s.top();
                    s.pop();
                    if(ch=='f')
                    {
                        And&=0;
                        Or|=0;
                    }
                    else if(ch=='t')
                    {
                        And &= 1;
                        Or |= 1;
                    }
                    else if(ch=='&')
                    {
                        s.push(And?'t':'f');
                        break;
                    }
                    else if(ch=='|')
                    {
                        s.push(Or?'t':'f');
                        break;
                    }
                    else if(ch=='!')
                    {
                        s.push(!Or ? 't' : 'f');
                        break;
                    }
                }
            }
        }
        return s.top()=='f'?0:1;
    } 
};