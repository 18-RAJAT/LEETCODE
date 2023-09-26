class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>cnt(26,0);
        vector<bool>vis(26,false);
        for(int i=0;i<n;++i)
        {
            cnt[s[i]-'a']++;
        }
        string ans="";
        for(int i=0;i<n;++i)
        {
            cnt[s[i]-'a']--;
            if(vis[s[i]-'a'])
            {
                continue;
            }
            while(!ans.empty() && ans.back()>s[i] && cnt[ans.back()-'a']>0)
            {
                vis[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i]-'a']=true;
        }
        return ans;
    }
};