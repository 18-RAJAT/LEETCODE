class Solution
{
    static class Building
    {
        int height;
        int index;
        Building(int height,int index)
        {
            this.height=height;
            this.index=index;
        }
    }
    static class Query
    {
        int maxIndex;
        int maxHeight;
        int queryIndex;
        Query(int maxIndex,int maxHeight,int queryIndex)
        {
            this.maxIndex=maxIndex;
            this.maxHeight=maxHeight;
            this.queryIndex=queryIndex;
        }
    }
    public int[] leftmostBuildingQueries(int[] h,int[][] q)
    {
        PriorityQueue<Query>pq=new PriorityQueue<>((a,b)->Integer.compare(b.maxIndex,a.maxIndex));
        int[] res=new int[q.length];
        Arrays.fill(res,-1);
        for (int i=0;i<q.length;++i)
        {
            int i1=q[i][0];
            int i2=q[i][1];
            int min=Math.min(i1,i2);
            int max=Math.max(i1,i2);
            int maxH=Math.max(h[i1],h[i2]);
            if (i1==i2 || (h[max]>h[min]))
            {
                res[i]=max;
            }
            else
            {
                pq.offer(new Query(max,maxH,i));
            }
        }
        TreeSet<Building> set=new TreeSet<>(Comparator.comparingInt(b->b.height));
        for (int i=h.length-1;i>=0;--i)
        {
            while (!pq.isEmpty() && pq.peek().maxIndex==i)
            {
                Query query=pq.poll();
                Building next=set.higher(new Building(query.maxHeight,0));
                if (next!=null)
                {
                    res[query.queryIndex]=next.index;
                }
            }
            while(!set.isEmpty() && set.first().height<=h[i])
            {
                set.pollFirst();
            }
            set.add(new Building(h[i],i));
        }
        return res;
    }
}