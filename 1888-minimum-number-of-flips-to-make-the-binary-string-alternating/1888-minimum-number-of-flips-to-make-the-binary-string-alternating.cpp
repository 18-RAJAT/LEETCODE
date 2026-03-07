class Solution {
public:
    int minFlips(string s) {
        int ans=INT_MAX,n=s.size(),x=0,y=0;
        for(int i=0;i<n*2;++i)
        {
            x+=(s[i%n]-'0'!=(i%2));
            y+=(s[i%n]-'0'!=(1-i%2));
            if(i>=n-1)
            {
                if(i>=n)
                {
                    x-=(s[i-n]!=((i-n)%2)+'0');
                    y-=(s[i-n]!=(1-(i-n)%2)+'0');
                }
                ans=min({ans,x,y});
            }
        }
        return ans; 
    }
};