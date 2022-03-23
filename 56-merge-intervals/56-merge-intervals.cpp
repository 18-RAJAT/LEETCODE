class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>answer;
        
        if(intervals.size() == 0)
        {
            return answer;
        }
        
        sort(intervals.begin(),intervals.end());
        
        answer.push_back(intervals[0]);
        
        int j=0;
        for(int i=0;i<intervals.size();++i)
        {
            if(answer[j][1] >= intervals[i][0])
            {
                answer[j][1] = max(answer[j][1],intervals[i][1]);
            }
            
            else
            {
                j++;
                
                answer.push_back(intervals[i]);
            }
        }
        
        return answer;
    }
};