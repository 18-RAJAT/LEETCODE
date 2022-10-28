class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)
        {
            string str2=strs[i];
            sort(str2.begin(),str2.end());
            mp[str2].push_back(strs[i]);
        }
        vector<vector<string>>m;
        for(auto it:mp)
            m.push_back(it.second);
        return m;
    }
};