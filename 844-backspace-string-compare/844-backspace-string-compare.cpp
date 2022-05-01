class Solution {
public:
    bool backspaceCompare(string s, string t) {

            
            stack<char>s1,s2;
            
            for(auto & i : s)
            {
                    if(i == '#' and s1.size() > 0)
                    {
                            s1.pop();
                    }
                    
                    if(i >= 'a' and i <= 'z')
                    {
                            s1.push(i);
                    }
            }
            
            
            for(auto & i : t)
            {
                    if(i == '#' and s2.size() > 0)
                    {
                            s2.pop();
                    }
                    
                    if(i >= 'a' and i <= 'z')
                    {
                            s2.push(i);
                    }
            }
            return s1 == s2;
    }
};