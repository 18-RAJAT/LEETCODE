class Solution {
public:
    int check(string& s,string t,int k)
    {
        int n=s.size(),m=t.size(),j=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]==t[j])j++;
            if(j==m)k--,j=0;
        }
        return k<=0;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string>q;
        q.push("");
        string ans="";
        while(!q.empty())
        {
            for(int i=0;i<q.size();++i)
            {
                auto F=q.front();q.pop();
                for(char j='a';j<='z';++j)
                {
                    if(check(s,F+j,k))
                    {
                        ans=F+j;
                        q.push(F+j);
                    }
                }
            }
        }
        return ans;
    }
};