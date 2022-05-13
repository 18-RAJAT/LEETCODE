class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            
            unordered_map<string,vector<string>>mp;
            for(auto i : strs)
            {
                    string temp = i;
                    sort(temp.begin(),temp.end());
                    mp[temp].push_back(i);
            }
            vector<vector<string>>result;
            for(auto i : mp)
            {
                    result.push_back(i.second);
            }
        return result;
    }
};