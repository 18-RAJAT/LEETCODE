class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        for(int i=0;i<image.size();++i)
        {
            reverse(image[i].begin(),image[i].end());
            
            for(int j=0;j<image[i].size();++j)
            {
                //Using XOR
                image[i][j]= image[i][j]^0x1;
            }
        }
        
        return image;
        
    }
};