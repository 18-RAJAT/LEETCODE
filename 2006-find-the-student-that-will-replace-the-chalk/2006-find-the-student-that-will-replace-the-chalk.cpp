class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long sum=accumulate(chalk.begin(),chalk.end(),0LL);
        k%=sum;
        int i=0;
        for(;chalk[i]<=k;k-=chalk[i++]);
        return i;
    }
};