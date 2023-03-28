class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto transpose=[&](vector<vector<int>>&mat)->void
        {
            int n=mat.size();
            // int m=mat[0].size();
            for(int i=0;i<n;++i)
            {
                for(int j=i;j<n;++j)
                {
                    swap(mat[i][j],mat[j][i]);
                }
            }
        };
        
        /*
           sequence
           
           1
           4
           7
           
           transpose
           
           start=7
           start.next=4
           start.next.next=1
           last to first[7,4,1]
           
        */
        function<void(vector<vector<int>>&)>revRow=[&](vector<vector<int>>&mat)->void
        {
            int n=mat.size();
            for(int i=0;i<n;++i)
            {
                reverse(mat[i].begin(),mat[i].end());
            }
        };
        transpose(matrix);
        revRow(matrix);
    }
};