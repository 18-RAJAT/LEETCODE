class Solution {
public:
    int helper(vector<int>& rods, vector<vector<int>>& memo, int numProcessed, int lSup, int rSup) {
        if (numProcessed==rods.size()) {
            if (lSup==rSup) 
                return lSup;
            else 
                return 0;
        }

        if (memo[numProcessed][abs(lSup-rSup)]>0)
            return min(lSup, rSup)+memo[numProcessed][abs(lSup-rSup)];
        else if (memo[numProcessed][abs(lSup-rSup)]<0)
            return 0;

        int rt=max({helper(rods, memo, numProcessed+1, lSup+rods[numProcessed], rSup), 
                    helper(rods, memo, numProcessed+1, lSup, rSup+rods[numProcessed]),
                    helper(rods, memo, numProcessed+1, rSup, lSup)});

        memo[numProcessed][abs(lSup-rSup)]=rt-min(lSup, rSup);

        return rt;
    }
    int tallestBillboard(vector<int>& rods) {
        int sum=0;
        for (auto r : rods)
            sum+=r;
        vector<vector<int>> memo(rods.size(), vector<int>(sum));
        return helper(rods, memo, 0, 0, 0);
    }
};