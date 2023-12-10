class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int>ans;
        int n=variables.size();
        for(int i=0;i<=n-1;++i)
        {
            int p=variables[i][0],q=variables[i][1],r=variables[i][2],s=variables[i][3];
            int pos=1;
            for(int j=1;j<=q;++j)
            {
                pos=(pos*p)%10;
            }
            int update=1;
            for(int j=1;j<=r;++j)
            {
                update=(update*pos)%s;
            }
            if(update==target)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};