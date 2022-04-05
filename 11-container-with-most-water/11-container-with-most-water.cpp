/*
The first thing we should realize is that the amount of water contained is always going to be a rectangle whose area is defined as length * width. The width of any container will be the difference between the index of the two lines (start and end), and the height will be whichever of the two sides is the lowest (min(H[start], H[end])).


*/
class Solution {
public:
    int maxArea(vector<int>& height) {
  
        int answer = 0;
        int start = 0;
        int end = height.size() - 1;
        int result = 0;
        
        while(start < end)
        {
            if(height[start] <= height[end])
            {
                result = height[start] * (end - start);
                start++;
            }
            
            else
            {
                result = height[end] * (end - start);
                end--;
            }
            
            if(result > answer)
            {
                answer = result;
            }
        }
    
        return answer;
    }
};