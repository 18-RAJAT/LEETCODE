//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int d[4]={1,-1,0,0};
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,pair<int, int> des) {
        queue<pair<int, int>> q;
        q.push(src);
        grid[src.first][src.second] = 0;
        int ans=0,n=grid.size(),m=grid[0].size(),i,j;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                tie(i,j) = q.front();
                q.pop();
                if(des==make_pair(i,j))
                    return ans;
                for(int k=0;k<4;k++){
                    int x=i+d[k], y=j+d[3-k];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y])
                        grid[x][y]=0,q.push({x,y});
                }
            }
            ans++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends