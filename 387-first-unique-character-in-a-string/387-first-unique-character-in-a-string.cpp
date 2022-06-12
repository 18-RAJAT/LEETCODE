class Solution {
public:
    int firstUniqChar(string s) {
        int CH[256]={0};
            for(auto it : s) CH[it]++;
            for(int i=0;i<s.length();++i)
                    if(CH[s[i]]==1){return i;}
            return -1;
    }
};