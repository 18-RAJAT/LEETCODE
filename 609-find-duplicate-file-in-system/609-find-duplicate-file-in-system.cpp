class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>>mp;
        for(auto it:paths)
        {
            stringstream ss(it);
            string root;
            string s;
            getline(ss,root,' ');
            while(getline(ss,s,' '))
            {
                string content=s.substr(s.find('(')+1,s.find(')')-s.find('(')-1);
                string path=root+'/'+s.substr(0,s.find('('));
                mp[content].push_back(path);
            }
        }
        vector<vector<string>>ans;
        for(auto it:mp)
        {
            if(it.second.size()>1)
            {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};