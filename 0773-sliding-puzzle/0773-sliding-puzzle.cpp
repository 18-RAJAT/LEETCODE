class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string str="";
        for(int i=0;i<2;++i)
        {
            for(int j=0;j<3;++j)
            {
                str+=to_string(board[i][j]);
            }
        }
        string target="123450";
        vector<vector<int>>nbg={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<pair<string,int>>q;
        q.push({str,0});
        unordered_set<string>visited;
        visited.insert(str);
        while(!q.empty())
        {
            auto [state,steps]=q.front();
            q.pop();
            if(state==target)return steps;
            int zeroIndex=state.find('0');
            for(int& it:nbg[zeroIndex])
            {
                string temp=state;
                swap(temp[zeroIndex],temp[it]);
                if(!visited.count(temp))
                {
                    q.push({temp,steps+1});
                    visited.insert(temp);
                }
            }
        }
        return -1;
    }
};