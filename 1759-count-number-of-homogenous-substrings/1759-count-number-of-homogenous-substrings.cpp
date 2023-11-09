class Solution {
public:
    int countHomogenous(string s) {
        long long n=s.size();
        function<long long(long long)>recur=[&](long long x)->long long//x is the length of the substring
        {
            return (x*(x+1))/2;//sum of first x natural numbers
        };
        long long ans=0;
        long long cnt=1;
        for(long long i=1;i<n;++i)
        {
            if(s[i]==s[i-1])
            {
                cnt++;
            }
            else
            {
                ans+=recur(cnt);
                cnt=1;
            }
        }
        ans+=recur(cnt)%1000000007;
        return ans;
    }
};