class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        unordered_set<int>st;
        for(int i=1;i<strs.size();++i)
        {
            for(int j=0;j<strs[i].size();++j)
            {
                if(st.count(j)>=1 || strs[i-1][j]==strs[i][j])continue;
                if(strs[i][j]<strs[i-1][j])
                {
                    st.insert(j);
                    i=0;
                }
                break;
            }
        }
        return st.size();
    }
};