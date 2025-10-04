class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,l=0,r=height.size()-1;
        while(l<r)
        {
            int mn=min(height[l],height[r])*(r-l);
            if(ans<mn)ans=mn;
            (height[l]<height[r])?l++:r--;
        }
        return ans;
    }
};