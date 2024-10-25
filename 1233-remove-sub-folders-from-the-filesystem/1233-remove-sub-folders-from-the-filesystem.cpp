class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        string str=folder[0];
        int index=str.size();
        vector<string>ans;
        for(int i=1;i<folder.size();++i)
        {
            if(!(folder[i].find(str)==0 && folder[i][index]=='/'))
            {
                ans.push_back(str);
                str=folder[i];
                index=str.size();
            }
        }
        ans.push_back(str);
        return ans;
    }
};