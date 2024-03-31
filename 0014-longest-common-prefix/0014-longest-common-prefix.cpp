class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string ans="";
        string First=strs[0],Last=strs[n-1];
        for(int i=0;i<First.size();++i)
        {
            if(First[i]!=Last[i])
            {
                return ans;
            }
            ans+=First[i];
        }
        return ans;
    }
};