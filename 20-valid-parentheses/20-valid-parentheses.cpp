class Solution {
public:
    bool isValid(string s) {
        
        stack<char> parenthis;
        
        for (char& c : s)
        {
            switch (c) 
            {
                    
                case '(': 
                case '{': 
                case '[': 
                parenthis.push(c); 
                    
                break;
                    
                case ')':
                    if (parenthis.empty() || parenthis.top()!='(') 
                        return false;
                    else  
                    
                    parenthis.pop(); 
                    
                    break;
                    
                     case '}':
                    
                    if (parenthis.empty() || parenthis.top()!='{') 
                        
                    return false; 
                    
                    else
                        
                    parenthis.pop(); break;

                    
                    case ']':
                    
                    if (parenthis.empty() ||parenthis.top()!='[') 
                        
                    return false;
                    
                    else
                    
                    parenthis.pop(); 
                    
                    break;
                    
                default: ; 
            }
        }
        return parenthis.empty() ;
    }
};