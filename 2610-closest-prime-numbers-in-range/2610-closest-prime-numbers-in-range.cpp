class Solution {
public:
    bool prime(int n)
    {
        if(n==2)return true;
        if(n==1 || n%2==0)return false;
        for(int i=3;i<=sqrt(n);i+=2)
        {
            if(n%i==0)return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left,int right) {
        vector<int>ar,ans;
        for(int i=left;i<=right;++i)if(prime(i))ar.push_back(i);
        if(ar.size()<2)return{-1,-1};
        int res=INT_MAX;
        for(int i=0;i<ar.size()-1;++i)
        {
            if(ar[i+1]-ar[i]<res)
            {
                ans={ar[i],ar[i+1]};
                res=ar[i+1]-ar[i];
            }
        }
        return ans;
    }
};