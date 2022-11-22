class Solution {
public:
    //in=interval
    //inN=newInterval
    vector<vector<int>> insert(vector<vector<int>>& in,vector<int>& inN) {
        vector<vector<int>> ans;
        int i=0;
        while(i<in.size() and in[i][1]<inN[0])
        {
            ans.push_back(in[i]);
            ++i;
        }
        while(i<in.size() and in[i][0]<=inN[1])
        {
            inN[0]=min(inN[0],in[i][0]);
            inN[1]=max(inN[1],in[i][1]);
            ++i;
        }
        ans.push_back(inN);
        while(i<in.size())
        {
            ans.push_back(in[i]);
            ++i;
        }
        return ans;
    }
};