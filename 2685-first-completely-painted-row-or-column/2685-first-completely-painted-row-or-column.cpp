class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int r[row];memset(r,0,sizeof(r));
        int c[col];memset(c,0,sizeof(c));
        map<int,pair<int,int>>m;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                m.insert(make_pair(mat[i][j],make_pair(i,j)));
            }
        }
        for(int i=0;i<arr.size();i++)
        {
            int x=m[arr[i]].first;
            int y=m[arr[i]].second;r[x]++;c[y]++;
            if(c[y]==row)
            {
                return i;
            }
            if(r[x]==col)
            {
                return i;
            }
        }
        return arr.size()-1;
    }
};