class Solution{
public:
    int minTimeToReach(vector<vector<int>>&moveTime){
        int n=moveTime.size(),m=moveTime[0].size();
        const long N=1e18;
        
        vector<vector<long>>dist(n,vector<long>(m,N));
        priority_queue<tuple<long,int,int>,vector<tuple<long,int,int>>,greater<tuple<long,int,int>>>pq;
        
        dist[0][0]=0;
        pq.push(make_tuple(0,0,0));
        vector<array<int,2>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(!pq.empty())
        {
            auto[i,j,k]=pq.top();pq.pop();
            if(j==n-1 && k==m-1)
            {
                return i;
            }
            if(dist[j][k]<i)continue;
            for(auto& it:dir)
            {
                int Nx=j+it[0],Ny=k+it[1];
                if(Nx>=0 && Nx<n && Ny>=0 && Ny<m)
                {
                    long long Nz=max(i,(long)moveTime[Nx][Ny])+1;
                    if(Nz<dist[Nx][Ny])
                    {
                        dist[Nx][Ny]=Nz;
                        pq.push(make_tuple(Nz,Nx,Ny));
                    }
                }
            }
        }
        return-1;
    }
};