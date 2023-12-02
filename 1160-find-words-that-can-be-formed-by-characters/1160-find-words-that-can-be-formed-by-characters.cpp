class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        map<char,int>mp;
        for(auto i:chars)
        {
            mp[i]++;
        }
        for(auto i:words)
        {
            map<char,int>temp;
            temp.clear();
            for(auto j:i)
            {
                temp[j]++;
            }
            bool flag=true;
            for(auto j:temp)
            {
                if(mp[j.first]<j.second)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                ans+=i.size();
            }
        }
        return ans;
    }
};