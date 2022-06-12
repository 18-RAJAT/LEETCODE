class Solution {
public:
    int minimumMoves(string s) {
           int answer=0;
            for(int i=0;i<s.size();++i) 
                    if(s[i]=='X')answer++,i=i+2;
            return answer;
    }
};
