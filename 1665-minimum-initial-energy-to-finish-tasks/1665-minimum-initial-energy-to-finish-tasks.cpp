class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a,vector<int>& b)
        {
            return (a[1]-a[0])>(b[1]-b[0]);
        });
        int ans=0,res=0;
        for(auto& it:tasks)
        {
            int x=it[0],y=it[1];
            if(res<y)
            {
                int rem=y-res;
                ans+=rem;
                res+=rem;
            }
            res-=x;
        }
        return ans;
    }
};