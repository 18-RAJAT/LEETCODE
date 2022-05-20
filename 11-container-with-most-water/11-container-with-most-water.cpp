/*
The first thing we should realize is that the amount of water contained is always going to be a rectangle whose area is defined as length * width. The width of any container will be the difference between the index of the two lines (start and end), and the height will be whichever of the two sides is the lowest (min(H[start], H[end])).
*/
class Solution {
public:
    int maxArea(vector<int>& height) {

          int i=0,j=height.size()-1;
          int maxArea=-1;
            while(i<j)
            {
                    int currarea=min(height[i],height[j])*(j-i);
                    if(height[i]<height[j]){i++;}
                    else{j--;}
                    
                    maxArea=max(maxArea,currarea);
            }
            return maxArea;
    }
};