class Solution{
public:
    int minMoves(vector<int>&nums,int limit){
        int n=nums.size();
        vector<int>ar(2*limit+2,0);
        for(int i=0;i<n/2;++i)
        {
            int a=nums[i],b=nums[n-1-i];
            int l=min(a,b)+1,r=max(a,b)+limit,tot=a+b;
            ar[2]+=2;
            ar[l]-=1,ar[r+1]++;
            ar[tot]-=1,ar[tot+1]++;
        }
        int ans=INT_MAX,curr=0;
        for(int j=2;j<=2*limit;++j)
        {
            curr+=ar[j];
            ans=min(ans,curr);
        }
        return ans;
    }
};