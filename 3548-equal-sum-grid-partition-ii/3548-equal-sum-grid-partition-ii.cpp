class Solution {
public:
    bool canRemove(int r1,int c1,int r2,int c2,int i,int j)
    {
        int rows=r2-r1+1,cols=c2-c1+1;
        if(rows*cols==1)return false;
        if(rows==1)return (j==c1 || j==c2);
        if(cols==1)return (i==r1 || i==r2);
        return true;
    }
    bool canPartitionGrid(vector<vector<int>>& grid)
    {
        int n=grid.size(),m=grid[0].size();
        vector<long long>row(n),col(m);
        map<long long,vector<pair<int,int>>>mp;
        for(int i=0;i<n;++i)
        {
            long long val=0;
            for(int j=0;j<m;++j)
            {
                val+=grid[i][j];
                mp[grid[i][j]].push_back({i,j});
            }
            row[i]=val+(i?row[i-1]:0);
        }
        for(int j=0;j<m;++j)
        {
            long long val=0;
            for(int i=0;i<n;++i)val+=grid[i][j];
            col[j]=val+(j?col[j-1]:0);
        }
        long long res=row[n-1];
        for(int i=0;i<n-1;++i)
        {
            long long top=row[i],bottom=res-top;
            if(top==bottom)return true;
            long long diff=abs(top-bottom);
            if(mp.find(diff)==mp.end())continue;
            if(top>bottom)
            {
                for(auto& it:mp[diff])
                {
                    int x=it.first,y=it.second;
                    if(x<=i && canRemove(0,0,i,m-1,x,y))return true;
                }
            }
            else
            {
                for(auto& it:mp[diff])
                {
                    int x=it.first,y=it.second;
                    if(x>i && canRemove(i+1,0,n-1,m-1,x,y))return true;
                }
            }
        }
        for(int j=0;j<m-1;++j)
        {
            long long left=col[j],right=res-left;
            if(left==right)return true;
            long long diff=abs(left-right);
            if(mp.find(diff)==mp.end())continue;
            if(left>right)
            {
                for(auto& it:mp[diff])
                {
                    int x=it.first,y=it.second;
                    if(y<=j && canRemove(0,0,n-1,j,x,y))return true;
                }
            }
            else
            {
                for(auto& it:mp[diff])
                {
                    int x=it.first,y=it.second;
                    if(y>j && canRemove(0,j+1,n-1,m-1,x,y))return true;
                }
            }
        }
        return false;
    }
};