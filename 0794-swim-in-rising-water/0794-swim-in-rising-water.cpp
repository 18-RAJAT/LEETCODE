class Solution{
public:
int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<tuple<int,int,int>>ar;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i>0)ar.push_back({max(grid[i][j],grid[i-1][j]),i*n+j,(i-1)*n+j});
                if(j>0)ar.push_back({max(grid[i][j],grid[i][j-1]),i*n+j,i*n+j-1});
            }
        }
        sort(ar.begin(),ar.end());
        vector<int>par(m*n);
        iota(par.begin(),par.end(),0);
        function<int(int)>find=[&](int x){return par[x]==x?x:par[x]=find(par[x]);};
        auto unite=[&](int x,int y){par[find(x)]=find(y);};
        for(auto& [x,y,z]:ar)
        {
            unite(y,z);
            if(find(0)==find(m*n-1))return x;
        }
        return grid[0][0];
    }
};