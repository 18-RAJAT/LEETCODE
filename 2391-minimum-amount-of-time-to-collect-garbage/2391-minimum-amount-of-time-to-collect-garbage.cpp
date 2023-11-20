class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        int glass=0,metal=0,plastic=0;
        int garbageCount=0;
        for(int i=0;i<n;++i)
        {
            for(auto&itr:garbage[i])
            {
                if(itr=='M')
                {
                    metal=i;
                }
                else if(itr=='P')
                {
                    plastic=i;
                }
                else
                {
                    glass=i;
                }
                garbageCount++;
            }
        }
        // cout<<garbageCount;
        int ans=garbageCount;//+6
        int sum=0;
        for(int i=0;i<travel.size();++i)
        {
            sum+=travel[i];
            // cout<<i; 012
            if(i+1==glass)
            {
                ans+=sum;
            }
            if(i+1==metal)
            {
                ans+=sum;
            }
            if(i+1==plastic)
            {
                ans+=sum;
            }
        }
        // cout<<metal<<" "<<plastic<<" "<<glass<<"\n";//take 2 and i+=1
        return ans;
    }
};