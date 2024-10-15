class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        vector<int>pos;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='0')
            {
                pos.push_back(i);
            }
        }
        long long ans=0;
        for(int i=0;i<pos.size();++i)
        {
            ans+=abs(pos[i]-i);
        }
        return ans;
    }
};