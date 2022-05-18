class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            vector<vector<int>>v1;
            if(intervals.size()==0){return intervals;}
            
            sort(intervals.begin(),intervals.end());
            for(int i=1;i<intervals.size();i++)
            {
                    int l=max(intervals[i][1],intervals[i][0]);
                    int r=min(intervals[i-1][1],intervals[i-1][0]);
                    int l1=max(intervals[i-1][0],intervals[i-1][1]);
                    int r1=min(intervals[i][0],intervals[i][1]);
                    l=max(l,l1);
                    r=min(r,r1);
                    
                    if(intervals[i][0] <= intervals[i-1][1])
                    {
                            // cout<<"test";
                            intervals[i][0]=r;
                             intervals[i][1]=l;
                            intervals[i-1][0]=-1;
                    }
            }
            for(auto it : intervals)
            {
                    if(it[0]!=-1){v1.push_back({it[0],it[1]});}
                    
            }
            return v1;
    }
};