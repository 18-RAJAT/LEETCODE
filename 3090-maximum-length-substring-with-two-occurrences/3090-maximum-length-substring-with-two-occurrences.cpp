class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            array<int,26>cnt={0};
            int count=0;
            for(int j=i;j<n;++j)
            {
                if(cnt[s[j]-'a']==2)
                {
                    break;
                }
                cnt[s[j]-'a']++;
                count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};