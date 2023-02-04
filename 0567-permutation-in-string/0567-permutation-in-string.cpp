class Solution {
public:
    bool cmp(int a[26],int b[26])
    {
        for(int i=0;i<26;++i)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m)
        {
            return false;
        }
        int cnt1[26];memset(cnt1,0,sizeof(cnt1));
        for(int i=0;i<n;++i)
        {
            int idx1=s1[i]-'a';
            cnt1[idx1]++;
        }
        int i=0;
        int window=n;
        int cnt2[26];memset(cnt2,0,sizeof(cnt2));
        while(i<window)
        {
            int idx2=s2[i]-'a';
            cnt2[idx2]++;
            i++;
        }
        if(cmp(cnt1,cnt2))
        {
            return true;
        }
        while(i<m)
        {
            char currPos=s2[i];
            int idx=currPos-'a';
            cnt2[idx]++;
            
            char prev=s2[i-window];
            idx=prev-'a';
            
            cnt2[idx]--;
            i++;
            
            if(cmp(cnt1,cnt2))
            {
                return true;
            }
        }
        return false;
    }
};