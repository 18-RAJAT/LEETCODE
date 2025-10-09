class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(),m=mana.size();
        vector<long long>ar(n);
        ar[0]=skill[0];
        for(int i=1;i<n;++i)ar[i]=ar[i-1]+skill[i];
        long long res=0;
        for(int j=1;j<m;++j)
        {
            long long tmp=ar[0]*mana[j-1];
            for(int i=1;i<n;++i)tmp=max(tmp,ar[i]*mana[j-1]-ar[i-1]*mana[j]);
            res+=tmp;
        }
        return res+ar[n-1]*mana[m-1];
    }
};