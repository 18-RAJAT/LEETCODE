class Solution {
public:
    int minMoves(vector<int>& nums) {
            int tp=INT_MAX;
            for(auto n:nums)
            {
                tp=min(n,tp);
            }
                    int answer=0;
                    for(int n: nums)
                    {
                            answer=answer+n-tp;
                    }
            return answer;
    }
};