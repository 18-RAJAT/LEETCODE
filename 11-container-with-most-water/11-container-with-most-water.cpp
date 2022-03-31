
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0;
        int r = height.size()-1;
        
        int Max_Area = 0;
        
        //Base Condition
        while(l < r)
        {
            int l_height = height[l];
            int r_height = height[r];
            
          Max_Area = max(Max_Area,(r-l) * min(l_height,r_height));
            
            if(l_height < r_height)
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return Max_Area;
    }
};