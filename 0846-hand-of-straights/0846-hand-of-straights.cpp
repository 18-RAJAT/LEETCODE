class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
        {
            return false;
        }
        map<int,int>mp;
        for(auto& it:hand)
        {
            mp[it]++;
        }
        while(!mp.empty())
        {
            int F=mp.begin()->first;
            for(int i=0;i<groupSize;++i)
            {
                if(mp[F+i]==0)return false;
                if(--mp[F+i]==0)mp.erase(F+i);
            }
        }
        return true;
    }
};