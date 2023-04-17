class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum=*max_element(candies.begin(),candies.end());
        vector<bool>greatestNoOfCandiesOrNot;
        for(int i=0;i<candies.size();++i)
        {
            if(maximum<=candies[i]+extraCandies)
            {
                greatestNoOfCandiesOrNot.push_back(true);
            }
            else
            {
                greatestNoOfCandiesOrNot.push_back(false);
            }
        }
        return greatestNoOfCandiesOrNot;
    }
};