class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string>ans;
        vector<int>idx;
        for(int i=0;i<n;++i)
        {
            if(i==0)
            {
                idx.push_back(i);
            }
            else
            {
                if(groups[i]!=groups[i-1])
                {
                    idx.push_back(i);
                }
            }
        }
        for(int i=0;i<idx.size();++i)
        {
            ans.push_back(words[idx[i]]);
        }
        return ans;
    }
};