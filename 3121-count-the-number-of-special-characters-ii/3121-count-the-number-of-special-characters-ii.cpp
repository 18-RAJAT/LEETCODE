class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int>mp;
        int ans=0;
        for(auto& it:word)
        {
            if(mp.find(it)!=mp.end())
            {
                if(mp[it]==1)ans++,mp[it]=0;
            }
            else if(islower(it))
            {
                if(mp.find(toupper(it))!=mp.end() && mp[toupper(it)]==0)ans--,mp[toupper(it)]=-1;
                else if(mp.find(toupper(it))!=mp.end() && mp[toupper(it)]==-1)continue;
                else if(mp[toupper(it)]!=-2)mp[toupper(it)]=1;
            }
            else if(isupper(it))mp[it]=-2;
        }
        return ans;
    }
};