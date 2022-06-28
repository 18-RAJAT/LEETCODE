class Solution {
public:
    int minDeletions(string s) {
        vector<int>v1(26,0);
        int ct=0;
        for(int i=0;i<s.size();++i)
            v1[s[i]-'a']++;
        sort(v1.begin(),v1.end());
        for(int i=0;i<25;++i)
        {
            if(v1[i]==v1[i+1] and v1[i]!=0)
            {ct++;v1[i]--;i=0;}
        }
        return ct;
    }
};