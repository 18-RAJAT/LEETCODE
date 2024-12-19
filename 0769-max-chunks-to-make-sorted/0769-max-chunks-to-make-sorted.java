class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n=arr.length,maxi=Integer.MIN_VALUE,count=0;
        for(int i=0;i<n;++i)
        {
            maxi=Math.max(maxi,arr[i]);
            if(i==maxi)count++;
        }
        return count;
    }
}