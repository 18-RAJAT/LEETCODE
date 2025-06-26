class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=0;
        int l=0,r=height.size()-1;
        while(l<r)
        {
            int currentArea=min(height[l],height[r])*(r-l);
            if(maxArea<currentArea)maxArea=currentArea;
            if(height[l]<height[r])l++;
            else r--;
        }
        return maxArea;
    }
};