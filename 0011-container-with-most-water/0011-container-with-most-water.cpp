class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int answer=0;
        while(left<right)
        {
            int minimum_height=min(height[left],height[right]);
            int width=right-left;
            answer=max(answer,minimum_height*width);//area of reactangle is length*width
            
            height[left]<height[right]?left++:right--;
        }
        return answer;
    }
};