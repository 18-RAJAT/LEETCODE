class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
        vector<vector<char>>ans(m,vector<char>(n));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                ans[j][n-i-1]=box[i][j];
            }
        }
        for(int j=0;j<n;++j)
        {
            int cnt=0;
            for(int i=0;i<m;++i)
            {
                if(ans[i][j]=='#')
                {
                    ans[i][j]='.';
                    cnt++;
                }
                if(i+1==m || ans[i+1][j]=='*')
                {
                    while(cnt)
                    {
                        ans[i+1-cnt][j]='#';
                        cnt--;
                    }
                }
            }
        }
        return ans;
    }
};