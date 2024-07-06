class Solution {
public:
    int passThePillow(int n, int time) {
        int db=-1,curr=1;
        for(int i=0;i<time;++i)
        {
            if(curr==1)
            {
                db=1;
            }
            else if(curr==n)
            {
                db=-1;
            }
            curr+=db;
        }
        return curr;
    }
};