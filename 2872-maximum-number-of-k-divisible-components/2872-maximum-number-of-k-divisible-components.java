import java.util.ArrayList;
class Solution {
    private long Dfs(int n,int par,long[] ans,ArrayList<ArrayList<Integer>> adj,int[] values,int k)
    {
        long res=values[n];
        for(int it:adj.get(n))
        {
            if(it!=par)res+=Dfs(it,n,ans,adj,values,k);
        }
        if(res%k==0)
        {
            ans[0]++;
            return 0;
        }
        return res;
    }
    public int maxKDivisibleComponents(int n,int[][] edges,int[] values,int k) {
        ArrayList<ArrayList<Integer>>adj=new ArrayList<>();
        for(int i=0;i<n;++i)adj.add(new ArrayList<>());
        for(int[] it:edges)
        {
            adj.get(it[0]).add(it[1]);
            adj.get(it[1]).add(it[0]);
        }
        long[] ans=new long[1];
        Dfs(0,-1,ans,adj,values,k);
        return (int)ans[0];
    }
}