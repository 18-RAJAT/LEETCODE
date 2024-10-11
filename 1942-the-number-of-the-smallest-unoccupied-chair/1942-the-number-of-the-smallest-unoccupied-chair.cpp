class Solution {
public:
    int smallestChair(vector<vector<int>>&times, int targetFriend) {
        int n=times.size();
        vector<pair<int,int>>events;
        for(int i=0;i<n;++i)
        {
            events.push_back({times[i][0],i});
            events.push_back({times[i][1],~i});
        }
        sort(events.begin(),events.end());
        set<int>available;
        for(int i=0;i<n;++i) available.insert(i);
        vector<int>assigned(n,-1);
        for(auto& e:events)
        {
            int it=e.second;
            if(it>=0)
            {
                assigned[it]=*available.begin();
                available.erase(available.begin());
                if(it==targetFriend)return assigned[it];
            }
            else
            {
                available.insert(assigned[~it]);
            }
        }
        return -1;
    }
};