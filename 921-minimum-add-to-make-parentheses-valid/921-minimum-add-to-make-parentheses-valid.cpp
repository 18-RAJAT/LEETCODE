class Solution {
public:
    int minAddToMakeValid(string s) {
        int ct = 0,answer = 0;
        
        for(int i =0;i<s.length();i++)
        {
            if(s[i]=='(')
            {ct++;}
            else ct--;
            if(ct<0){answer+=abs(ct);ct=0;}
        }
        answer+=abs(ct); 
        
        return answer;
    }
};