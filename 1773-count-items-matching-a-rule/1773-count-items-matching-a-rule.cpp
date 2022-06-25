class Solution {
public:
    //ruleValue=rv and ruleKey=rk and items=it
    int countMatches(vector<vector<string>>& it, string rk, string rv) {
        int ct=0;
        for(int i=0;i<it.size();++i)
        {
            if((rk=="type" and it[i][0]==rv) or (rk=="color" and it[i][1]==rv) or (rk=="name" and it[i][2]==rv)){ct++;}
        }
        return ct;
    }
};