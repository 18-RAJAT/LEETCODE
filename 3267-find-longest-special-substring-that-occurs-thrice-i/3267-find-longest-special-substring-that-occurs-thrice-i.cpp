class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        int ans=-1;
        for(int length=1;length<=n;++length)
        {
            auto recur=[&](string str)->bool
            {
                for(int i=0;i<str.size();++i)
                {
                    if(str[i]!=str[0])
                    {
                        return false;
                    }
                }
                return true;
            };
            unordered_map<string,int>mp;
            for(int i=0;i<=n-length;++i)
            {
                string substr=s.substr(i,length);
                if(recur(substr))
                {
                    mp[substr]++;
                    if(mp[substr]>=3)
                    {
                        ans=max<int>(ans,length);
                    }
                }
            }
        }
        return ans;
    }
};