class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size(),cur=1,ans=0;
        for(int i=0;i<n+k-2;++i)
        {
            (colors[i%n]!=colors[(i+1)%n])?cur++:cur=1;
            ans+=(cur>=k);
        }
        return ans;
    }
};