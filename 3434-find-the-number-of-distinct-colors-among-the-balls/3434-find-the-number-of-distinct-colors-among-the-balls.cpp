class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,set<int>>ballColor;
        map<int,int>distColors;
        vector<int>ans;
        for(auto& it:queries)
        {
            int b=it[0],c=it[1];
            ballColor[c].insert(b);
            if(distColors.count(b))
            {
                int oldc=distColors[b];
                if(oldc!=c)
                {
                    ballColor[oldc].erase(b);
                    if(ballColor[oldc].size()==0)ballColor.erase(oldc);
                }
            }
            ans.push_back(ballColor.size());
            distColors[b]=c;
        }
        return ans;
    }
};