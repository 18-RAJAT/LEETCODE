class Solution {
public:
    string clearStars(string s) 
    {
        int n=s.size();
        int cnt=count(s.begin(),s.end(),'*');
        if(cnt+cnt==s.size())return "";
        map<char,vector<int>>mp;
        for(int i=0;i<n;++i)
        {
            char ch=s[i];
            if(ch=='*')
            {
                for(auto& [F,S]:mp)
                {
                    if(S.size()) 
                    {
                        int x=S.back();
                        mp[F].pop_back();
                        s[x]='.';
                        break;
                    }
                }
            }
            else mp[ch].push_back(i);
        }
        string ans;
        for(auto& it:s)
        {
            if(isalpha(it))ans+=it;
        }
        return ans;
    }
};