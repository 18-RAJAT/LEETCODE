class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
    vector<int>Expected(heights);
    sort(Expected.begin(),Expected.end());
        
        int result = 0;
        
        for(int i=0;i<heights.size();++i)
        {
            if(heights[i] != Expected[i])
            {
                result++;
            }
        }
        return result;
    }
};