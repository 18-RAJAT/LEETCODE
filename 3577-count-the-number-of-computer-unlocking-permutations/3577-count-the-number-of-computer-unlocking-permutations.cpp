class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size(),init=complexity[0],Mod=1000000007;
        long long ans=1;
        for(int i=1;i<n;++i)
        {
            if(complexity[i]<=init)return 0;
            ans=(ans*i)%Mod;
        }
        return ans;
    }
};