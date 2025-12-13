class Solution {
public:
    bool valid(string& s)
    {
        if(s.size()==0)return false;
        for(int i=0;i<s.size();++i)
        {
            if(!isalpha(s[i]) && !isdigit(s[i]) && s[i]!='_')return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,vector<string>>ump;
        for(int i=0;i<code.size();++i)
        {
            if(isActive[i] && valid(code[i]))ump[businessLine[i]].push_back(code[i]);
        }
        vector<string>ans;
        sort(ump["electronics"].begin(),ump["electronics"].end());
        for(int i=0;i<ump["electronics"].size();++i)
        {
            ans.push_back(ump["electronics"][i]);
        }
        sort(ump["grocery"].begin(),ump["grocery"].end());
        for(int i=0;i<ump["grocery"].size();++i)
        {
            ans.push_back(ump["grocery"][i]);
        }
        sort(ump["pharmacy"].begin(),ump["pharmacy"].end());
        for(int i=0;i<ump["pharmacy"].size();++i)
        {
            ans.push_back(ump["pharmacy"][i]);
        }
        sort(ump["restaurant"].begin(),ump["restaurant"].end());
        for(int i=0;i<ump["restaurant"].size();++i)
        {
            ans.push_back(ump["restaurant"][i]);
        }
        return ans;
    }
};