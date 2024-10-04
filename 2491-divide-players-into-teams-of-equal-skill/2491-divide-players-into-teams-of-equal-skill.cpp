class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size(),teamSum=skill[0]+skill[n-1];
        long long chemistry=0;
        for(int i=0;i<n/2;++i)
        {
            if(skill[i]+skill[n-i-1]!=teamSum)return -1;
            chemistry+=skill[i]*skill[n-i-1];
        }
        return chemistry;
    }
};