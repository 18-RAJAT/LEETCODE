class Solution {
public:
    
    double dfs(int n, int k, int x, int y, vector<vector<vector<double>>>& cache){
        if(k==0) return 1;
        if(cache[x][y][k]!=-1) return cache[x][y][k];
        vector<vector<int>> dir = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
        double prob = 0;
        for(auto& d: dir){
            int xx = x + d[0], yy = y + d[1];
            if(xx>=0 && xx<n && yy>=0 && yy<n)
                prob += ((double)1/8)*dfs(n,k-1,xx,yy, cache);
        }
        return cache[x][y][k] = prob;
    }
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>> cache(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return dfs(n,k,r,c, cache);
    }
};