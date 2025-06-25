class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(m<n)return false;
        unordered_map<char,int>mp,mp1;
        for(auto& it:s1)mp[it]++;
        // for(int i=0;i+n-1<m;++i)
        for(int i=0;i<=m-n;++i)
        {
            mp1.clear();
            int j=i;
            while(j<=i+n-1)
            {
                mp1[s2[j]]++,j++;
            }
            if(mp==mp1)return true;
        }
        return false;
    }
};