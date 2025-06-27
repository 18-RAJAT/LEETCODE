class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int n=heights.size();
        stack<pair<int,int>>st;
        int largest=0;
        for(int i=0;i<n;++i)
        {
            int j=i;
            while(!st.empty() && heights[i]<st.top().first)
            {
                auto& [F,S]=st.top();
                st.pop();
                largest=max(largest,F*(i-S));
                j=S;
            }
            st.push({heights[i],j});
        }
        return largest;
    }
};