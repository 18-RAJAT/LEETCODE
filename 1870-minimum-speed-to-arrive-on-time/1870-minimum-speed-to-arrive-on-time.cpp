class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
		int n=dist.size();
		if(hour<=n-1)
		{
			return -1;
		}
		int l=1,r=1e7;
		while(l<r)
		{
			int mid=(l+r)>>1;
			double sum=0;
			for(int i=0;i<n-1;++i)
			{
				sum+=ceil((double)dist[i]/mid);
			}
			sum+=(double)dist[n-1]/mid;
			if(sum<=hour)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		return l;      
    }
};