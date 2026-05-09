class Solution{
public:
    void rotateArray(vector<int>&nums,int k)
    {
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+(n-k));
        reverse(nums.begin()+(n-k),nums.end());
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int topRow=0,bottomRow=n-1;
        int leftCol=0,rightCol=m-1;
        int fillTop=0,fillBottom=n-1;
        int fillLeft=0,fillRight=m-1;
        while(topRow<=bottomRow && leftCol<=rightCol)
        {
            vector<int>temp;
            for(int j=leftCol;j<=rightCol;++j)
            {
                temp.push_back(grid[topRow][j]);
            }
            topRow++;
            for(int i=topRow;i<=bottomRow;++i)
            {
                temp.push_back(grid[i][rightCol]);
            }
            rightCol--;
            if(topRow<=bottomRow)
            {
                for(int j=rightCol;j>=leftCol;--j)
                {
                    temp.push_back(grid[bottomRow][j]);
                }
                bottomRow--;
            }
            if(leftCol<=rightCol)
            {
                for(int i=bottomRow;i>=topRow;--i)
                {
                    temp.push_back(grid[i][leftCol]);
                }
                leftCol++;
            }
            rotateArray(temp,k);
            int ind=0;
            for(int j=fillLeft;j<=fillRight;++j)
            {
                grid[fillTop][j]=temp[ind++];
            }
            fillTop++;
            for(int i=fillTop;i<=fillBottom;++i)
            {
                grid[i][fillRight]=temp[ind++];
            }
            fillRight--;
            if(fillTop<=fillBottom)
            {
                for(int j=fillRight;j>=fillLeft;--j)
                {
                    grid[fillBottom][j]=temp[ind++];
                }
                fillBottom--;
            }
            if(fillLeft<=fillRight)
            {
                for(int i=fillBottom;i>=fillTop;--i)
                {
                    grid[i][fillLeft]=temp[ind++];
                }
                fillLeft++;
            }
        }
        return grid;
    }
};