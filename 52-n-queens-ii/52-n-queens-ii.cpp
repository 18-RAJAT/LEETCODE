class Solution {
        int result;
public:
        void dfs(int n,int d,int r,int d1,int d2)
        {
                if(d==n){result++;return;}
                for(int i=0;i<n;++i)
                {
                        int current=1<<i;
                        if((current&r) or (current&d1) or (current&d2)){continue;}
                        dfs(n,d+1,(current|r),(current|d1)<<1,(current|d2)>>1);
                }
        }
        
    int totalNQueens(int n) {
        result=0;
            dfs(n,0,0,0,0);
            return result;
    }
};
