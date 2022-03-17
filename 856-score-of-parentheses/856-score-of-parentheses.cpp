class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int answer = 0;
        int depth_multiplier = 2;
        
        for(int i=1;i<s.length();++i)
        {
            if(s[i] == '(')
            {
                depth_multiplier = depth_multiplier*2;
        //Another way is -> depth_multiplier = depth_multiplier<<1;
            }
            
            else
            {
                depth_multiplier = depth_multiplier/2; 
       //Another way is -> depth_multiplier = depth_multiplier>>1;
                
                if(s[i-1] == '(')
                    answer += depth_multiplier;
            }
        }
        
        return answer;
        
    }
};