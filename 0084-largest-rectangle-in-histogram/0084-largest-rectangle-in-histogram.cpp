class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int maxArea=0;
        //all bars including one extra (i==n) for remaining stack
        for(int i=0;i<=n;++i)
        {
            //
            while(!st.empty() && (i==n || heights[i]<=heights[st.top()]))
            {
                int cur=heights[st.top()],nextSmaller=i;
                st.pop();
                //stack empty -> no smaller bar to the left
                int prevSmaller=(st.empty())?-1:st.top();
                /*
                    width=(r-l-1) calculate area...
                    [2,1,5,6,2,3]
                    let say processing height 5 at idx 2.
                    prevSmaller=idx 1-> vals(1)
                    nextSmaller=idx 4-> vals(2)
                    width=4-1-1=2;
                    area=height*wdith=5*2=10;
                    spans bar=[5,6]...
                */
                int area=cur*(nextSmaller-prevSmaller-1);
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        return maxArea;
    }
};