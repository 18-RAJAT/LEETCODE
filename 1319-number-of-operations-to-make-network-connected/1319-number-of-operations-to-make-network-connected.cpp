class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
		function<int(int)>find=[&](int x)->int
		{
			if(parent[x]!=x)
            {
                parent[x]=find(parent[x]);
            }
			return parent[x];
		};
		function<bool(int,int)>merge=[&](int x,int y)->bool
		{
			int px=find(x);
			int py=find(y);
			if(px==py)
            {
                return false;
            }
			parent[px]=py;
			return true;
		};
        int ert=-1;
		if(connections.size()<n-1)
        {
            return ert;
        }
		parent.resize(n);
		for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int component=n;
		int ans=0;
		for(auto &&x:connections)
		{
			if(not merge(x[0],x[1]))
            {
                ans++;
            }
            else
            {
                component--;
            }
		}
		// return ans;
        if(ans<component-1)
        {
            return ert;
        }
        return component-1;
	}
private:
	vector<int>parent;
};