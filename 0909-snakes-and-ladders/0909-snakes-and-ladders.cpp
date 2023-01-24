
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        //to store the distance of each cell from 1 and visited or not
        vector<int>dist(n*n+1,-1),v(n*n+1);
        int a=1;
        bool ok=true;
        for(int i=n-1;i>=0;i--)
        {
            if(ok)
            {
                for(int j=0;j<n;j++)
                {
                    //storing the value of each cell in a vector
                    v[a++]=board[i][j];
                }
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    v[a++]=board[i][j];
                }
            }
            ok=!ok;
        }
        int ans=INT_MAX;
        queue<pair<int,int>>que;
        que.push(make_pair(1,0));
        
        while(!que.empty())
        {
            auto f=que.front();
            que.pop();
            int x=f.first;
            int y=f.second;
            //if the cell is already visited and the distance is less than the current distance then we will not push it in the queue
            if(dist[x]==-1 or dist[x]>y)
            {
                dist[x]=y;
            }
            else
            {
                continue;
            }
            //if the cell is not -1 then we will move to the cell which is stored in the vector
            if(v[x]!=-1)
            {
                x=v[x];
            }
            //if we reach the last cell then we will update the answer
            if(x==n*n)
            {
                ans=min(ans,y);
                continue;
            }
            //we will push the next 6 cells in the queue
            for(int k=1;k<=6;k++)
            {
                //if the cell is not visited and the cell is less than the total number of cells
                if(x+k<=n*n and dist[x+k]==-1)
                {
                    que.push(make_pair(x+k,y+1));
                }
            }
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};