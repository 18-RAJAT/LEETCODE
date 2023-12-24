class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;++i)
        {
            ans+=i%2==0?(s[i]=='1'):(s[i]=='0');
        }
        int ans1=0;
        for(int i=0;i<n;++i)
        {
            ans1+=i%2==0?(s[i]=='0'):(s[i]=='1');
        }
        return min<int>(ans,ans1);
    }
};