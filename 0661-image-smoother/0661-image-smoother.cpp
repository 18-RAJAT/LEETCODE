class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        //apply convolution filter on each pixel of the image to get the smoothed image
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int sum=0,cnt=0;
                for(int x=-1;x<=1;++x)//8 directions -1 is for the current pixel 1 is for the next pixel
                {
                    for(int y=-1;y<=1;++y)//vice versa
                    {
                        int nx=i+x,ny=j+y;
                        if(nx>=0 && nx<n && ny>=0 && ny<m)
                        {
                            sum+=img[nx][ny];
                            cnt++;
                        }
                    }
                }
                ans[i][j]=sum/cnt;
            }
        }
        return ans;
    }
};