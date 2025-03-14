class Solution {
public:
    bool recur(vector<int>&candies,long long k,int x)
    {
        if(x==0)return true;
        long long res=0;
        for(auto& it:candies)
        {
            res+=it/x;
            if(res>=k)return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies,long long k) {
        long long sum=0;
        for(auto& it:candies)sum+=it;
        if(sum<k)return 0;
        int low=1,high=*max_element(candies.begin(),candies.end());
        while(low<high)
        {
            int mid=(low+high+1)/2;
            if(recur(candies,k,mid))low=mid;
            else high=mid-1;
        }
        return low;
    }
};