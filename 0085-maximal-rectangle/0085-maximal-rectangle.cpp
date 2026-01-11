class Solution{
public:
    int maxHistogram(vector<int>&heights)
    {
        heights.push_back(0);
        int n=heights.size();
        stack<int>st;
        int res=0,i=0;
        while(i<n)
        {
            if(st.empty() || heights[i]>=heights[st.top()])
              st.push(i++);
            else
            {
                int top=st.top();
                st.pop();
                res=max(res,heights[top]*(st.empty()?i:i-st.top()-1));
            }
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>&matrix)
    {
        if(matrix.empty())return 0;
        int m=matrix.size(),n=matrix[0].size();
        int res=0;
        vector<int>height(n,0);
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]=='1')height[j]++;
                else height[j]=0;
            }
            res=max(res,maxHistogram(height));
        }
        return res;
    }
};