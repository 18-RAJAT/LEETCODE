class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long int sum=0;
        for(int i=0;i<k;++i)
        {
            sum+=max<int>(0LL,happiness[i]-i);
        }
        return sum;
    }
};