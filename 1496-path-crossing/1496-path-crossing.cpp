class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        multiset<pair<int,int>>st;
        st.insert({x,y});
        for(int i=0;i<path.size();++i)
        {
            if(path[i]=='N')
            {
                y++;
            }
            else if(path[i]=='S')
            {
                y--;
            }
            else if(path[i]=='E')
            {
                x++;
            }
            else
            {
                x--;
            }
            if(st.count({x,y})>0)
            {
                return true;
            }
            st.insert({x,y});
        }
        return false;
    }
};