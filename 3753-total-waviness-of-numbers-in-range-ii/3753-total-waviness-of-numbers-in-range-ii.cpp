class Solution
{
    struct Node
    {
        long long count,sum;
    };
    Node dp[17][2][3][11][11];
    string s;
public:
    Node dfs(int i,bool tight,int state,int last1,int last2)
    {
        if(i==s.size())return {1,0};
        Node& ans=dp[i][tight][state][last1][last2];
        if(ans.count==-1)
        {
            ans={0,0};
            int lim=tight?s[i]-'0':9;
            for(int j=0;j<=lim;++j)
            {
                bool ok=tight && j==lim;
                Node child;
                if(state==0)
                {
                    if(j==0)child=dfs(i+1,ok,0,10,10);
                    else child=dfs(i+1,ok,1,j,10);
                    ans.count+=child.count;
                    ans.sum+=child.sum;
                }
                else if(state==1)
                {
                    child=dfs(i+1,ok,2,j,last1);
                    ans.count+=child.count;
                    ans.sum+=child.sum;

                }
                else
                {
                    int wave=last1<min(j,last2) || last1>max(j,last2);
                    child=dfs(i+1,ok,2,j,last1);
                    ans.count+=child.count;
                    ans.sum+=child.sum+wave*child.count;
                }
            }
        }
        return ans;
    }
    long long solve(long long num)
    {
        s=to_string(num);
        memset(dp,-1,sizeof(dp));
        return dfs(0,1,0,10,10).sum;
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2)-solve(num1-1);
    }
};