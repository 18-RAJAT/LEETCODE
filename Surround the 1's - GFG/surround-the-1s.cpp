//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
         int n = matrix.size();
        int m = matrix[0].size();
        
        int count = 0;
        
        int row[] = {0, 1, 0, -1, -1, -1, 1, 1};
        int col[] = {-1, 0, 1, 0, -1, 1, 1, -1};
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    int zeros = 0;
                    for (int k = 0; k < 8; k++)
                    {
                        int r = i + row[k];
                        int c = j + col[k];
                        
                        if (r >= 0 and r < n and c >=0 and c < m and matrix[r][c] == 0)
                            zeros++;
                            
                    }
                    if (zeros != 0 and zeros % 2 == 0)
                        count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends