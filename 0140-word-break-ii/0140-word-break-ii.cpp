class Solution {
public:
    vector<string> ans;
    bool solve(string s,vector<string>& words,string temp)
    {
        if(s.size()==0)
        {
            ans.push_back(temp);
            return true;
        }
        bool check=0;
        for(int i=1;i<=s.size();++i)
        {
            string str=s.substr(0,i);
            bool ok=0;
            for(int j=0;j<words.size();++j)
            {
                if(str==words[j])
                {
                    ok=1;
                    break;
                }
            }
            if(ok && solve(s.substr(i),words,temp+str+' '))
            {
                check=1;
            }
        }
        return check;
    }
    vector<string> wordBreak(string s,vector<string>& wordDict) {
        solve(s,wordDict,"");
        for(int i=0;i<ans.size();++i)
        {
            ans[i].pop_back();
        }
        return ans;
    }
};