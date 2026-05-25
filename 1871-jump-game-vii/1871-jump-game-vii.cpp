class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1')return false;
        queue<int>q;
        q.push(0);
        int k=0;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            for(int j=max(i+minJump,k+1);j<=min(i+maxJump,n-1);++j)
            {
                if(s[j]=='0')
                {
                    if(j==n-1)return true;
                    q.push(j);
                }
            }
            k=min(i+maxJump,n-1);
        }
        return false;
    }
};