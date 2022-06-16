class Solution {
public:
    int minimumMoves(string s) {
                int ct=0;
            for(int i=0;i<s.length();++i)
            {
                    if(s[i]=='X'){ct++;i=i+2;}
            }
            return ct;
    }
};
