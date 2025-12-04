class Solution {
public:
    int countCollisions(string directions) {
        int S=0,L=0,R=0,ans=0;
        for(int i=0;i<directions.size();++i)
        {
            if(directions[i]=='R')R++;
            else if(directions[i]=='L')
            {
                if(R>0)
                {
                    ans+=R+1,R=0,S=1;
                }
                else ans+=(S>0?1:0);
            }
            else ans+=R,R=0,S=1;
        }
        return ans;
    }
};