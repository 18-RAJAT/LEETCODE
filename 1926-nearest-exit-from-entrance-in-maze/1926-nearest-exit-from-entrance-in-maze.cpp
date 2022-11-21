class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) 
    {
     queue<pair<int,int>> q;
     q.push({e[0]-1,e[1]});
     q.push({e[0]+1,e[1]});
     q.push({e[0],e[1]-1});
     q.push({e[0],e[1]+1});
     maze[e[0]][e[1]]='+';
     int c=0;
     while(!q.empty())
     {
         c++;
         int s=q.size();
         for(int i=0;i<s;i++)
         {
             auto p=q.front();
             int x=p.first,y=p.second;
             if(x<0 or y<0 or x>=maze.size() or y>=maze[0].size() or maze[x][y]=='+')
             {
                 q.pop();
                 continue;
             }
             if(x==0 or y==0 or x==maze.size()-1 or y==maze[0].size()-1)
             {
                 return c;
             }
             q.push({x-1,y});
             q.push({x+1,y});
             q.push({x,y-1});
             q.push({x,y+1});
             q.pop();
             maze[x][y]='+'; 
         }
     }
             return -1;
    }
};