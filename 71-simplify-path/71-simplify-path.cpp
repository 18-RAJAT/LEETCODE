class Solution {
public:
    string simplifyPath(string path) {
        
        stack <string> stk;
        
        for(int i = 0;i<path.size();i++)
        {
            if(path[i] == '/')
                continue;
            string s;
            
            while(i<path.size() and path[i] != '/')
                
            {
                s += path[i];
                i++;
            }
            
            if(s == ".")
              continue;
            
            
            else if(s == "..")
            {
                if(!stk.empty())
                  stk.pop();
            }
            else
            {
                stk.push(s);
            }
        }
        
        string result;
        
        while(!stk.empty())
        {
            result = "/" + stk.top() + result;
            stk.pop();
        }
        if(result.size() == 0)
        {
            return "/";
        }
        return result;
    }
};