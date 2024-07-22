class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string,greater<int>>mp;
        int n=names.size();
        for(int i=0;i<n;++i)
        {
            mp[heights[i]]=names[i];
        }
        int i=0;
        for(auto &it:mp)
        {
            names[i]=it.second;
            i++;
        }
        return names;
    }
};