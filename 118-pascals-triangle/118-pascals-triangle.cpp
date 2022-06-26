class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>answer;
        for(int i=0;i<n;++i)
        {
            vector<int>row(i+1,1);
            for(int j=1;j<i;++j)
            {
                row[j]=answer[i-1][j]+answer[i-1][j-1];
            }
            answer.push_back(row);
        }
        return answer;
    }
};