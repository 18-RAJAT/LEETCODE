class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;++i)
        {
            vector<int>fz(26,0);
            int dist=0,mx=0;
            for(int j=i;j<n;++j)
            {
                int id=s[j]-'a';
                if(fz[id]==0)dist++;
                fz[id]++;
                mx=max(mx,fz[id]);
                if(j-i+1==dist*mx)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};