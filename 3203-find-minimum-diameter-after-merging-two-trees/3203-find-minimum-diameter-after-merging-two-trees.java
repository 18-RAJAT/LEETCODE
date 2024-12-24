class Solution {
    int res=0;
    int MinHeight(List<Integer>[] arr)
    {
        if(arr.length==1) return 0;
        List<Integer>ans=new ArrayList<>();
        int pos=0;
        for(int i=0;i<arr.length;++i) if(arr[i].size()==1) ans.add(i);
        int n=arr.length;
        while(n>=3)
        {
            n-=ans.size();
            List<Integer> t=new ArrayList<>();
            for(Integer i:ans)
            {
                int nxt=arr[i].iterator().next();
                arr[nxt].remove(i);
                if(arr[nxt].size()==1) t.add(nxt);
            }
            ans=t;
            pos++;
        }
        res=Math.max(res,ans.size()==1?2*pos:2*pos+1);
        return ans.size()==1?pos:pos+1;
    }
    public int minimumDiameterAfterMerge(int[][] edges1,int[][] edges2) {
        int n=edges1.length+1,m=edges2.length+1;
        List<Integer>[] arr=new ArrayList[n];
        List<Integer>[] brr=new ArrayList[m];
        for(int i=0;i<n;++i) arr[i]=new ArrayList<>();
        for(int j=0;j<m;++j) brr[j]=new ArrayList<>();
        for(int[] it:edges1)
        {
            arr[it[0]].add(it[1]);
            arr[it[1]].add(it[0]);
        }
        for(int[] it:edges2)
        {
            brr[it[0]].add(it[1]);
            brr[it[1]].add(it[0]);
        }
        int add=MinHeight(arr)+MinHeight(brr)+1;
        if(res<add) res=add;
        return res;
    }
}