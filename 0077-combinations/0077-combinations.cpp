class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        function<void(vector<vector<int>>&,int,int,int,vector<int>&)>solve=[&](vector<vector<int>>&ans,int n,int initial,int k,vector<int>&combinantion)->void
        {
            if(combinantion.size()==k)
            {
                ans.push_back(combinantion);
                return;
            }
            for(int i=initial;i<=n;++i)
            {
                combinantion.push_back(i);
                solve(ans,n,i+1,k,combinantion);
                combinantion.pop_back();
            }
        };
        vector<int>combination;
        vector<vector<int>>result;
        solve(result,n,1,k,combination);
        return result;
    }
};