class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
		long long sz=batteries.size();
		if(n==sz)
		{
			return *min_element(batteries.begin(),batteries.end());
		}
		sort(batteries.begin(),batteries.end());
		long long spare=0;
		for(long long i=0;i<sz-n;++i)
		{
			spare+=batteries[i];
		}
		long long cnt=1;
		long long ans=batteries[sz-n];
		for(long long i=sz-n+1;i<sz;++i)
		{
			if(spare>=cnt*(batteries[i]-batteries[i-1]))
			{
				spare-=cnt*(batteries[i]-batteries[i-1]);
				ans=batteries[i];
			}
			else
			{
				return ans+spare/cnt;
			}
			cnt++;
		}
		return ans+spare/n;
	}
};