class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<pair<int,int>>cells(n*n+1);
        int cnt=1;
        vector<int>columns(n);
        iota(columns.begin(),columns.end(),0);
        for(int i=n-1;~i;--i)
        {
            for(auto& it:columns)
            {
                cells[cnt++]={i,it};
            }
            reverse(columns.begin(),columns.end());
        }
        vector<int>dist(n*n+1,-1);
        queue<int>q;
        dist[1]=0;
        q.push(1);
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(int i=curr+1;i<=min(curr+6,n*n);++i)
            {
                auto& [row,column]=cells[i];
                int destination=board[row][column]!=-1?board[row][column]:i;
                if(dist[destination]==-1)
                {
                    dist[destination]=dist[curr]+1;
                    q.push(destination);
                }
            }
        }
        return dist[n*n];
    }
};