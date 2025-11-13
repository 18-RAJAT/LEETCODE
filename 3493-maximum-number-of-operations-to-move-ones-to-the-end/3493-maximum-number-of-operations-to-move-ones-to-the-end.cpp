class Solution {
public:
    int maxOperations(string s) {
        int n=s.size(),cntO=0,ans=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1')cntO++;
            else
            {
                while(i<n && s[i]=='0')i++;
                i--;
                ans+=cntO;
            }
        }
        return ans;
    }
};