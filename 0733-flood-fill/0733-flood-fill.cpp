class Solution {
public:
    void dfs(vector<vector<int>>&image,int sr,int sc,int newColor,int oldColor)
    {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=oldColor)
        {
            return;
        }
        image[sr][sc]=newColor;//changing the color
        dfs(image,sr+1,sc,newColor,oldColor);
        dfs(image,sr-1,sc,newColor,oldColor);
        dfs(image,sr,sc+1,newColor,oldColor);
        dfs(image,sr,sc-1,newColor,oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];//store old color
        if(oldColor!=color)//not equal then change the color
        {
            dfs(image,sr,sc,color,oldColor);
        }
        return image;
    }
};