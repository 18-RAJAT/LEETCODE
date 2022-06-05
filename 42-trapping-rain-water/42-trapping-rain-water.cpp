class Solution {
public:
    int trap(vector<int>& height) {
        int h=height.size();
            int answer=0;
            vector<int>left(h);
            vector<int>right(h);
            
            for(int i=0;i<h;++i)
                    left[i]=i==0 ? height[i] : max(height[i],left[i-1]);
            
            for(int i=h-1;i>=0;--i)
                    right[i]=i==h-1 ? height[i] : max(height[i],right[i+1]);
            
            for(int i=0;i<h;++i)
            {
                    answer=answer+min(left[i],right[i])-height[i];
            }
            return answer;
    }
};