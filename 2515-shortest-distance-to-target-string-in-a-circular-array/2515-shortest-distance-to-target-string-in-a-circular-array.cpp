class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        map<string,vector<int>>mp;
        int n=words.size();
        for(int i=0;i<n;++i)mp[words[i]].push_back(i);
        int ans=INT_MAX;
        if(mp.find(target)==mp.end())return -1;
        else
        {
            for(int i=0;i<mp[target].size();++i)
            {
                if(mp[target][i]>startIndex)
                {
                    int a=mp[target][i]-startIndex;
                    int b=n-(mp[target][i]-startIndex);
                    ans=min({ans,a,b});
                }
                else
                {
                    int a=startIndex-mp[target][i];
                    int b=n-(startIndex-mp[target][i]);
                    ans=min({ans,a,b});
                }
            }
        }
        return ans;
    }
};