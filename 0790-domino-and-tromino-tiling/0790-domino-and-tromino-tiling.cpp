const int MOD=1000000007;
class Solution {
public:
    int numTilings(int n) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(5);
        if(n<=3)
        {
            return ans[n];
        }
        int j=1;
        for(int i=4;i<=n;i++)
        {
            int x=(2*(ans[i-1]%MOD)%MOD+ans[j]%MOD)%MOD;
            ans.push_back(x);
            j++;
        }
        return ans[n];
    }
};