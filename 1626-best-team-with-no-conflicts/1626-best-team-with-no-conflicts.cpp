class Solution {
public:
    /*
        intution is that,
        Taking age,score,current and then
        taking the age and their score and the score is store in current
        again check the previous age is not less then this else the return that point
        and we have to iterate the next score who is less then previous score and 
        adding with the previous score+current score and store in current and these
        many cases will be created and then to return maximum.
    */
    
    //Time complexity O(n^2)
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>>best;
        for(int i=0;i<n;++i)
        {
            best.push_back(make_pair(ages[i],scores[i]));
        }
        sort(best.begin(),best.end());
        vector<int>dp(n,0);
        dp[0]=best[0].second;
        for(int i=1;i<n;++i)
        {
            //if we dont take anyone before this person then we can take this person only
            dp[i]=best[i].second;
            for(int j=0;j<i;++j)
            {
                //if we take this person then we can take anyone before this person
                if(best[i].second>=best[j].second)
                {
                    //we will take the maximum of the two cases current+previois
                    dp[i]=max(dp[i],dp[j]+best[i].second);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};