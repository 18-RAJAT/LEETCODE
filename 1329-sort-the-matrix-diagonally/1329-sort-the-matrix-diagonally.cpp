class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (i?1:n); j++) {
            vector<int> vals;
            while (i<m && j<n)
                vals.push_back(A[i++][j++]);
            sort(vals.begin(), vals.end());
            while (i && j) {
                A[--i][--j] = vals.back();
                vals.pop_back();
            }
        }
    }
    return A;
}
};