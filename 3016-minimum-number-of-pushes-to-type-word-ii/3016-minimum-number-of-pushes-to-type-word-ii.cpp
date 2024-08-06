class Solution {
public:
    map<char,int>mp;
    bool comp(char a,char b)
    {
        return mp[a]>mp[b];
    }
    int minimumPushes(string word) {
        int n=word.size();
        for(int i=0;i<n;++i)
        {
            mp[word[i]]++;
        }
        vector<char>ans;
        for(auto& it:mp)
        {
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end(),bind(&Solution::comp,this,placeholders::_1,placeholders::_2));
        int words_get=0,pos=1,num=2;
        for(auto& it:ans)
        {
            words_get+=mp[it]*pos;
            if(num<9)
            {
                num++;
            }
            else
            {
                num=2;
                pos++;
            }
        }
        return words_get;
    }
};