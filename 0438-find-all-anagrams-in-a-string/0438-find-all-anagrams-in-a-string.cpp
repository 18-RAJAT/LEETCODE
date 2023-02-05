class Solution {
public:
    bool check(int a[],int b[])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n=s.size();
        int m=p.size();
        if(n<m)
        {
            return ans;
        }
        int a[26];memset(a,0,sizeof(a));//Pfz
        int b[26];memset(b,0,sizeof(b));//window
        for(int i=0;i<m;i++)
        {
            a[s[i]-'a']++;
            b[p[i]-'a']++;
        }
        for(int i=m;i<n;i++)
        {
            if(check(a,b))
            {
                ans.push_back(i-m);
            }
            a[s[i]-'a']++;
            a[s[i-m]-'a']--;
        }
        if(check(a,b))
        {
            ans.push_back(n-m);
        }
        return ans;     
    }
};