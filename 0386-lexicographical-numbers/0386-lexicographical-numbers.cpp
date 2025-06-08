class Solution {
public:
    void recur(int i,int n,vector<int>& ans)
    {
        if(n<i)return;
        ans.push_back(i);
        for(int j=0;j<=9;++j)recur(i*10+j,n,ans);
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;++i)recur(i,n,ans);
        return ans;
    }
};