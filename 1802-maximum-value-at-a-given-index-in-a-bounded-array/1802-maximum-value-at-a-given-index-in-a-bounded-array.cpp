class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int st=1;
        int end=1e9;
        long long mid=st+(end-st)/2;
        int ans=-1;
        while(st<=end)
        {
            mid=st+(end-st)/2;
            long long sum=mid*(mid+1);
            long long x=mid-index-1;
            if(x>0)
            {
                x=x*(x+1)/2;
            }
            sum-=x;
            x=mid-(n-index);
            if(x>0)
            {
                x=x*(x+1)/2;
            }
            sum-=x;
            sum-=mid;
            if(sum<=maxSum)
            {
                ans=mid;
                st=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
};