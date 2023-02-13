class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        function<bool(int,int)>check=[&](int i,int j) 
        {
			int val=matrix[i][j];
			while (i<matrix.size() and j<matrix[0].size()) 
            {
				if (matrix[i][j]!=val) {
					return false;
				}
				++i;++j;
			}
			return true;
		};
        for(int i=0;i<matrix.size();++i) 
        {
			if (not check(i,0)) 
            {
				return false;
			}
		}
		for(int j=0;j<matrix[0].size();++j) 
        {
			if (not check(0,j)) 
            {
				return false;
			}
		}
		return true;   
    }
};