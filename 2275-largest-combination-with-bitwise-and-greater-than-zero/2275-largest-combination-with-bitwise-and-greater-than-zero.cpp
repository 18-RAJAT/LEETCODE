class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int i=0;i<30;++i)
        {
            int cnt=count_if(candidates.begin(),candidates.end(),[&](int x){return (x>>i)&1;});
            ans=max(ans,cnt);
        }
        return ans;
    }
};