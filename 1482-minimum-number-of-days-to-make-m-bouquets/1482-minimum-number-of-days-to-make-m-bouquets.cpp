class Solution {
public:
    int recur(vector<int>& bloomDay,int m,int k,int day)
    {
        int b=0,f=0;
        for(auto& it:bloomDay)
        {
            if(it<=day)
            {
                f++;
                if(f==k)
                {
                    b++,f=0;
                }
            }
            else f=0;
        }
        return m<=b;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)n<(long long)m*k)return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end()),r=*max_element(bloomDay.begin(),bloomDay.end());
        while(l<r)
        {
            int mid=l+(r-l)/2;
            (recur(bloomDay,m,k,mid))?r=mid:l=mid+1;
        }
        return l;
    }
};