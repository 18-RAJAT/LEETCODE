class Solution {
    
    //DFS FUNCTION
    void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,int rows,int cols,int source)
    {
        //Base case 1st
        if(sr<0 or sr >= rows or sc <0 or sc >= cols)
        {
            return;
        }
        //Base case 2nd
        else if(image[sr][sc] != source)
        {
            return;
        }
        
        //image-> rows and cols firstlty initilized by newColor
        image[sr][sc] = newColor;
        
        //DFS CALLS ALL SIDE'S TOP,DOWN,LEFT,RIGHT...!!
        dfs(image,sr-1,sc,newColor,rows,cols,source);    //TOP
        
        dfs(image,sr+1,sc,newColor,rows,cols,source);   //DOWN
        
        dfs(image,sr,sc-1,newColor,rows,cols,source);  //LEFT
        
        dfs(image,sr,sc+1,newColor,rows,cols,source); //RIGHT
    }
    
public:
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        //Base case 3rd
        if(newColor == image[sr][sc])
        {
            return image;
        }
        
        //Rows traverse
        int rows = image.size();
        
        //Cols traverse
        int cols = image[0].size();
        
        //source will be seeing image row and image column
        int source = image[sr][sc];
        
        //Lastly we will be doing dfs call
        dfs(image,sr,sc,newColor,rows,cols,source);
        
        //And then return
        return image;
        
    }
};