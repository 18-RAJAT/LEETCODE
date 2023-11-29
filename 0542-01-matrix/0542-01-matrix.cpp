class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>answer(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>que;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(mat[i][j]==0)
                {
                    answer[i][j]=0;
                    que.emplace(make_pair(i,j));
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!que.empty())
        {
            pair<int,int>current=que.front();
            que.pop();
            for(int i=0;i<4;++i)
            {
                int row=current.first+dx[i];
                int col=current.second+dy[i];
                auto isValid=[&](int row,int col)->bool
                {
                    return(row>=0 && row<n && col>=0 && col<m)?true:false;
                };
                if(isValid(row,col) && answer[row][col]>=answer[current.first][current.second]+1)
                {
                    answer[row][col]=1+answer[current.first][current.second];
                    que.emplace(make_pair(row,col));
                }
            }
        }
        return answer;
    }
};