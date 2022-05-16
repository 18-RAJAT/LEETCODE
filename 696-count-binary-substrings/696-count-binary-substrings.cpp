class Solution {
public:
    int countBinarySubstrings(string s) {
            
            int curlen=1,prevlen=0,ct=0;
            for(int i=1;i<s.size();++i)
            {
            if(s[i]==s[i-1]){curlen++;}
            else{prevlen=curlen; curlen=1;}
            if(prevlen>=curlen)ct++;
            }
            return ct;
    }
};