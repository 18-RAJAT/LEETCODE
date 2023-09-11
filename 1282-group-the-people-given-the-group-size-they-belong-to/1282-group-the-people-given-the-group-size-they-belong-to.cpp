class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        vector<vector<int>>ans;
        vector<int>temp[n+1];
        for(int i=0;i<n;++i)
        {
            temp[groupSizes[i]].push_back(i);
        }
        for(int i=1;i<=n;++i)
        {
            int sz=temp[i].size();
            for(int j=0;j<sz;j+=i)
            {
                vector<int>temp2;
                for(int k=j;k<j+i;++k)
                {
                    temp2.push_back(temp[i][k]);
                }
                ans.push_back(temp2);
            }
        }
        return ans;      
    }
};