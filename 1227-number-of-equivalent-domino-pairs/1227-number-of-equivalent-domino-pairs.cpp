class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        map<vector<int>,int>m;
        for(int i=0;i<n;++i)
        {
            sort(dominoes[i].begin(),dominoes[i].end());
            m[dominoes[i]]++;
        }
        int sum=0;
        for(auto& it:m)
        {
            int res=it.second;
            if(res>=2)sum+=(res*(res-1))/2;
        }
        return sum;
    }
};