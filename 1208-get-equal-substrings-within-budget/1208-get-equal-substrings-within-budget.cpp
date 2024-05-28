class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int i=0,j=0,cost=0;
        while(j<n)
        {
            cost+=abs(s[j]-t[j]);
            if(maxCost<cost)
            {
                cost-=abs(s[i]-t[i]);i++;
            }
            j++;
        }
        return j-i;
    }
};