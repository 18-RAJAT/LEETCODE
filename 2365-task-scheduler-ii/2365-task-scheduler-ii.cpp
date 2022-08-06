#define ll long long
class Solution {
public:
    
    long long taskSchedulerII(vector<int>& tasks, int space) {
        ll res=0;
        map<ll,ll>lastDay;
        for(auto it:tasks)
        {
            if(lastDay.count(it))
            res=max(res,lastDay[it]);
            res++;
            
            lastDay[it]=res+space;
        }
        return res;
    }
};