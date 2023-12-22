class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int ans=0;
        for(int i=1;i<n;++i)//non-empty
        {
            int count=0;
            for(int j=0;j<i;++j)
            {
                count+=s[j]=='0';//counting 0s in left part
            }
            for(int j=i;j<n;++j)
            {
                count+=s[j]=='1';//counting 1s in right part
            }
            ans=max<int>(ans,count);
        }
        return ans;
    }
};