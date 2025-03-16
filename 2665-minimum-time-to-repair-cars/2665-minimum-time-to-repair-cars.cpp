class Solution { 
public: 
    bool recur(long long t,vector<int>& ar,int x)
    {
        long long cnt=0;
        for(auto& it:ar)
        {
            cnt+=sqrt(t/it);
            if(cnt>=x)return true;
        }
        return cnt>=x;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1,r=1LL*(*min_element(ranks.begin(),ranks.end()))*cars*cars;
        while(l<=r)
        {
            long long m=l+(r-l)/2;
            (recur(m,ranks,cars)?r=m-1:l=m+1);
        }
        return l;
    }
};