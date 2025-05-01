class Solution {
public:
    int maxTaskAssign(vector<int>&tasks, vector<int>&workers, int p, int strength) {
        int n=tasks.size(),m=workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int L=0,R=min(m,n),ans;
        while(L<=R)
        {
            int mid=L+(R-L)/2,count=0;
            int ok=1;
            multiset<int>st(workers.begin(), workers.end());
            for(int i=mid-1;~i;--i)
            {
                auto it=prev(st.end());
                if(tasks[i]<=*it)st.erase(it);
                else
                {
                    it=st.lower_bound(tasks[i]-strength);
                    if(it!=st.end())
                    {
                        count++;
                        st.erase(it);
                    }
                    else
                    {
                        ok=0;
                        break;
                    }
                }
                if(count>p)
                {
                    ok=0;
                    break;
                }
            }
            (ok)?ans=mid,L=mid+1:R=mid-1;
        }
        return ans;
    }
};