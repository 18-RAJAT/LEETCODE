class Solution {
public:
    int findTheLongestSubstring(string s){
        int state=0,maxlen=0;
        unordered_map<int,int>m;m[0]=-1;
        for(int i=0;i<s.size();++i)
        {
            switch(s[i])
            {
                case 'a': state^=1; break;
                case 'e': state^=2; break;
                case 'i': state^=4; break;
                case 'o': state^=8; break;
                case 'u': state^=16; break;
            }
            if(m.find(state)!=m.end())
            {
                maxlen=max(maxlen,i-m[state]);
            }
            else
            {
                m[state]=i;
            }
        }
        return maxlen;
    }
};