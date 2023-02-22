class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        auto chk=[&](int x)->int
        {
            int day=1,curr=0;
            for(auto w:weights)
            {
                if(curr+w>x)
                {
                    day++;curr=0;
                }
                curr+=w;
            }
            return day<=days;
        };
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(chk(mid))
            {
                // mid--;
                r=mid;
            }
            else
            {
                mid++;
                l=mid;
            }
        }
        return l;
    }
};