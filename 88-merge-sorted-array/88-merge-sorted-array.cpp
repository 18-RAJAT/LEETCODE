class Solution {
public:
 void merge(vector<int>& A, int m, vector<int>& B, int n) {
     
        for(int i=m,j=0; j<n; i++)
          A[i] = B[j++];
           sort(A.begin(),A.end());
    }
};